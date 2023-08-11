#include "minirt.h"

t_vec3 get_light_dir(t_hit *hit)
{
	t_vec3 w;

	w = vec_subs(get_light_position(get_minirt()->lights->content), hit->hit_point);
	w = vec_norm(w);
	return (w);
}

int shading(t_hit *hit)
{
	t_vec3 	n;//normal vector to hit point
	t_vec3 	w;//light source direction
	float 	intensity;
	float 	kd;
	int		result;

	if (hit->obj->type == SPHERE)
	{
 		n = vec_copy(hit->hit_point);
		n = vec_norm(n);
	}
	else
		n = get_normal_vec(hit);
	w = get_light_dir(hit);
	intensity = get_light_intensity(get_minirt()->lights->content);
	kd = get_rgba(get_obj_color(hit->obj->obj), 255);

	result = intensity * vec_dot(n, w) * kd;
	return (result);
}
