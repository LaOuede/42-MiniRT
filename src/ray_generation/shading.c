#include "minirt.h"

t_vec3 get_light_dir(t_hit *hit)
{
	t_vec3 w;

	w = vec_subs(get_light_position(get_minirt()->lights->content), hit->hit_point);
	w = vec_norm(w);
	return (w);
}

float shading_intensity(float geo_term)
{
	float diffuse_light;
	float ambiant_light;
	float light_intensity;

	ambiant_light = 255.0f * get_minirt()->ambiant_light.intensity;
	if (geo_term >= 0.0f)
		diffuse_light = geo_term * 255.0f * get_light_intensity(get_minirt()->lights->content);
	else
		diffuse_light = 0.0f;
	light_intensity = diffuse_light + ambiant_light;
	if (light_intensity > 255.0f)
		light_intensity = 255.0f;
	return (light_intensity);
}

t_color shading_color(t_hit *hit, t_vec3 w, t_vec3 n, t_color obj_color)
{
	t_color specular_color;
	t_color output_color;
	t_vec3	v;
	t_vec3	h;
	float	coeff;

	specular_color = get_specular_color(obj_color);

	v = vec_norm(vec_subs(get_minirt()->camera.position, hit->hit_point));
	h = vec_norm(vec_add(w, v));


	coeff = vec_dot(n, h);
	if (coeff < 0)
		coeff = 0;
	coeff = pow(coeff, get_obj_material(hit->obj)->shine * pow(get_light_intensity(get_minirt()->lights->content), 1.4f));

	specular_color = color_scale(specular_color, coeff);

	output_color = color_add(obj_color, specular_color);

	output_color = max_color(output_color);
	return(output_color);
}

u_int32_t shading(t_hit *hit)
{
	t_vec3 		n;//normal vector to hit point
	t_vec3 		w;//light source direction
	float		geo_term;
	t_color color;
	float intensity;

	// color = get_obj_color(hit->obj);
	color = get_texture_color(hit);
	n = get_normal_vec(hit);
	w = get_light_dir(hit);
	geo_term = vec_dot(n, w);

	
	intensity = shading_intensity(geo_term);
	color = shading_color(hit, w, n, color);

	

	return ((u_int32_t)get_rgba(color, intensity));
}
