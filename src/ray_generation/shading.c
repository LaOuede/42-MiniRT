#include "minirt.h"

t_vec3 get_light_dir(t_hit *hit, void *current_light)
{
	t_vec3 w;
	t_vec3 light_position;

	light_position = get_light_position(current_light);

	w = vec_subs(light_position, hit->hit_point);
	w = vec_norm(w);
	return (w);
}

float get_geo_term(t_hit *hit, void *current_light, t_vec3 n)
{
	t_vec3 w;
	float geo_term;

	w = get_light_dir(hit, current_light);
	geo_term = vec_dot(n, w);
	return (geo_term);
}

static bool shadow_ray_hits(t_hit *hit, void *light)
{
	t_vec3 light_position;
	t_vec3 d;
	float t;
	t_list *current;
	void *object;
	t_hit new_hit;

	light_position = get_light_position(light);
	d = vec_norm(vec_subs(light_position, hit->hit_point));
	t = vec_mag(vec_subs(light_position, hit->hit_point));

	current = get_minirt()->objects;
	while (current)
	{
		if (get_obj_material(current->content)->id == SUN
			|| hit->obj->obj == current->content)
		{
			current = current->next;
			continue ;
		}
		object = current->content;
		find_hit(d, object, &new_hit, hit->hit_point);
		if (new_hit.obj && new_hit.t < t)
			return (TRUE);
		current = current->next;
	}
	return (FALSE);
}

float shading_intensity(t_hit *hit, t_vec3 n)
{
	t_list *current;
	float diffuse_light;
	float ambiant_light;
	float light_intensity;
	float current_intensity;
	float geo_term;

	ambiant_light = 255.0f * get_minirt()->ambiant_light.intensity;
	light_intensity = ambiant_light;
	if (get_obj_material(hit->obj)->id == SUN)
		return (255.0f);
	current = get_minirt()->lights;
	while (current)
	{
		if (shadow_ray_hits(hit, current->content))
		{
			current = current->next;
			continue;
		}
		
		geo_term = get_geo_term(hit, current->content, n);
		if (geo_term >= 0.0f)
			diffuse_light = geo_term * 255.0f * get_light_intensity(current->content);
		else
			diffuse_light = 0.0f;
		current_intensity = diffuse_light;
		if (current_intensity > 255.0f)
			current_intensity = 255.0f;
		if (current_intensity > light_intensity)
			light_intensity = current_intensity;
		current = current->next;
	}
	if (light_intensity < ambiant_light)
		light_intensity = ambiant_light;
	
	return (light_intensity);
}


void calc_specular_effect(t_hit *hit, t_vec3 n, t_vec3 v, t_shading *shade)
{
	t_color specular_color;
	t_vec3	h;
	t_vec3	w;
	float	coeff;
	float	current_coeff;
	t_list *current;

	specular_color = get_specular_color(shade->color);
	current = get_minirt()->lights;
	coeff = 0;
	while (current)
	{
		w = get_light_dir(hit, current->content);
		h = vec_norm(vec_add(w, v));
		current_coeff = vec_dot(n, h);
		if (current_coeff < 0)
			current_coeff = 0;
		current_coeff = pow(current_coeff, get_obj_material(hit->obj)->shine * pow(get_light_intensity(current->content), 1.4f));
		if (current_coeff > coeff)
			coeff = current_coeff;
		current = current->next;
	}
	if (coeff > 0.5)
	{
		printf("");
	}
	// shade->color = color_scale(specular_color, shading_intensity(hit, n) / 255.0f);
	shade->color = color_add(shade->color, color_scale(specular_color, coeff));
}

t_color shading_color(t_hit *hit, t_vec3 n, t_shading *shade, int *refl, t_vec3 v)
{
	t_material *mat;

	mat = get_obj_material(hit->obj);
	if (mat->reflexion != 0)
		calc_reflexion(hit, n, v, shade, refl);
	// if (mat->shine != 0)
	// 	calc_specular_effect(hit, n, v, shade);//!!!!IMPORTANT!!!!<------------------

	return(shade->color);
}


t_shading shading(t_hit *hit)
{
	t_vec3 		n;
	t_shading	shade;
	int refl;
	t_vec3	v;

	v = vec_norm(vec_subs(get_minirt()->camera.position, hit->hit_point));

	refl = 0;
	
	shade.color = get_texture_color(hit);

	n = get_normal_vec(hit);
	shade.intensity = shading_intensity(hit, n);
	shade.color = shading_color(hit, n, &shade, &refl, v);
	
	shade.color = max_color(shade.color);
	return (shade);
}
