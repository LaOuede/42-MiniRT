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
