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

	V = (theta / M_PI);
	if (V < 0)
		V += 1;

	(*px) = U * (image->width - 1);
	if ((*px) > (image->width - 1))
		(*px) = (image->width - 1);

	(*py) = V * (image->height - 1);
	if ((*py) > image->height - 1)
		(*py) = image->height - 1;
}

void uv_map_plane(t_hit *hit, unsigned int *px, unsigned int *py, mlx_texture_t *image)
{
    t_vec3 normal;
    t_vec3 u_vec;
    t_vec3 v_vec;
    t_vec3 hit_to_point;
	float U;
	float V;

	normal = get_plane_direction(hit->obj);
    u_vec = vec_cross(normal, generate_vector(1, 0, 0));
    v_vec = vec_cross(normal, u_vec);
    hit_to_point = vec_subs(hit->hit_point, get_position(hit->obj));
    U = vec_dot(hit_to_point, u_vec);
    V = vec_dot(hit_to_point, v_vec);


    U /= 30;
    V /= 35;

    // Normalize U and V to [0, 1] range
    U = fmod(U, 1.0f);
    if (U < 0)
        U += 1;

    V = fmod(V, 1.0f);
    if (V < 0)
        V += 1;

    *px = (unsigned int)(U * (image->width - 1));
    *py = (unsigned int)(V * (image->height - 1));
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
