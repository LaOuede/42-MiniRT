#include "minirt.h"

void uv_map_sphere(t_hit *hit, unsigned int *px, unsigned int *py, mlx_texture_t *image)
{
	t_vec3		normal;
	float		phi;
	float		theta;
	float			U;
	float			V;

	normal = vec_norm(vec_subs(hit->hit_point, get_position(hit->obj)));
	phi = atan2f(normal.z, normal.x);
	theta = acosf(normal.y);

	
	U = (phi / (2 * M_PI)) * -1;
	if (U < 0)
		U += 1;

	V = ((theta / M_PI));
	if (V < 0)
		V += 0;

	(*px) = U * (image->width - 1);
	if ((*px) > (image->width - 1))
		(*px) = (image->width - 1);

	(*py) = V * (image->height - 1);
	if ((*py) > image->height - 1)
		(*py) = image->height - 1;
}

void uv_map_plane(t_hit *hit, unsigned int *px, unsigned int *py, mlx_texture_t *image)
{
    t_vec3 hit_point = hit->hit_point;

	
    // Define the local axes of the plane
    t_vec3 axis_u = (t_vec3){1.0f, 0.0f, 0.0f}; // Local x-axis of the plane
    t_vec3 axis_v = (t_vec3){0.0f, 0.0f, 1.0f}; // Local z-axis of the plane

    // Calculate the coordinates of the hit point in the local space of the plane
    t_vec3 hit_vector = vec_norm(vec_subs(hit_point, get_position(hit->obj)));
    float U = vec_dot(hit_vector, axis_u);
		if (U < 0)
		U += 1;
    float V = vec_dot(hit_vector, axis_v);
		if (V < 0)
		V += 1;

    // Calculate pixel coordinates
    (*px) = (unsigned int)(U * (image->width - 1));
    (*py) = (unsigned int)(V * (image->height - 1));

    // Clamp pixel coordinates to the image dimensions
    if ((*px) >= image->width)
        (*px) = image->width - 1;

    if ((*py) >= image->height)
        (*py) = image->height - 1;
}

void uv_map(t_hit *hit, unsigned int *px, unsigned int *py, mlx_texture_t *image)
{
	if (hit->obj->type == SPHERE)
	{
		uv_map_sphere(hit, px, py, image);
	}
	else if (hit->obj->type == PLAN)
	{
		uv_map_plane(hit, px, py, image);
	}
	
	
}