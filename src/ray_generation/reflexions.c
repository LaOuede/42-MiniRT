#include "minirt.h"

void sun_special_reflexion_case(t_shading *shade, float *multiplier)
{
	shade->intensity *= 1.2f;
	if (shade->intensity > 255.0f)
		shade->intensity = 255.0f;		
	*multiplier *= 5;
}

void calc_reflexion(t_hit *hit, t_vec3 n, t_vec3 v, t_shading *shade, int *refl)
{
	t_vec3		w;
	t_ray_info	ray;
	t_hit		closest_hit;
	float		multiplier;
	t_shading	new_shading;

	if (++(*refl) > NUMBER_OF_REFLEXIONS)
		return;
		
	w = vec_norm(vec_subs(vec_scale(n, 2 * vec_dot(v, n)), v));
	ray.first_hit = TRUE;
	ray.d = w;
	find_closest_hit(ray, &closest_hit, hit->hit_point);
	if (closest_hit.obj)
	{		
		closest_hit.hit_point = vec_add(hit->hit_point, vec_scale(ray.d, closest_hit.t));
		closest_hit.hit_point = vec_add(closest_hit.hit_point, vec_scale(get_normal_vec(&closest_hit), 0.01));
		multiplier = get_obj_material(hit->obj)->reflexion / sqrtf(closest_hit.t);
		if (get_obj_material(closest_hit.obj)->id == SUN)
		{
			sun_special_reflexion_case(shade, &multiplier);
		}
		new_shading.color = get_texture_color(&closest_hit);
		new_shading.intensity = shading_intensity(&closest_hit, get_normal_vec(&closest_hit));

		new_shading.color = shading_color(&closest_hit, get_normal_vec(&closest_hit), &new_shading, refl, vec_scale(w, -1));
		shade->color = color_add(shade->color, color_scale(new_shading.color, multiplier * new_shading.intensity / 255.0f));
	}
}
