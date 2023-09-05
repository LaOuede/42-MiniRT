#include "minirt.h"

t_vec3	get_light_dir(t_hit *hit, void *current_light)
{
	t_vec3	w;
	t_vec3	light_position;

	light_position = get_light_position(current_light);
	w = vec_subs(light_position, hit->hit_point);
	w = vec_norm(w);
	return (w);
}

float	get_geo_term(t_hit *hit, void *current_light, t_vec3 n)
{
	t_vec3	w;
	float	geo_term;

	w = get_light_dir(hit, current_light);
	geo_term = vec_dot(n, w);
	return (geo_term);
}

static bool	shadow_ray_hits(t_hit *hit, t_list **light)
{
	t_vec3	d;
	float	t;
	t_list	*current;
	t_hit	new_hit;

	d = vec_norm(vec_subs(get_light_position((*light)->content), hit->hit_point));
	t = vec_mag(vec_subs(get_light_position((*light)->content), hit->hit_point));
	current = get_minirt()->objects;
	while (current)
	{
		if (get_obj_material(current->content)->id == SUN
			|| hit->obj->obj == current->content)
		{
			current = current->next;
			continue ;
		}
		find_hit(d, current->content, &new_hit, hit->hit_point);
		if (new_hit.obj && new_hit.t < t)
		{
			(*light) = (*light)->next;
			return (TRUE);
		}
		current = current->next;
	}
	return (FALSE);
}

void	add_light_color(t_shading *shade, void *light, float light_intensity,
		int refl)
{
	t_color	coloradd;

	if (refl > 1)
		return ;
	light_intensity /= 255.0f;
	coloradd = color_scale(get_light_color(light), light_intensity);
	shade->color = color_add(shade->color, coloradd);
	coloradd = color_scale(get_minirt()->ambiant_light.color,
							get_minirt()->ambiant_light.intensity);
	shade->color = color_add(shade->color, coloradd);
}

float	shading_intensity(t_hit *hit, t_vec3 n, t_shading *shade, int refl)
{
	t_list	*current;
	float	ambiant_light;
	float	light_intensity;
	float	current_intensity;

	ambiant_light = 255.0f * get_minirt()->ambiant_light.intensity;
	if (get_obj_material(hit->obj)->id == SUN)
		return (255.0f);
	current = get_minirt()->lights;
	while (current)
	{
		if (shadow_ray_hits(hit, &current))
			continue ;
		current_intensity = 0.0f;
		if (get_geo_term(hit, current->content, n) > 0.0f)
			current_intensity = get_geo_term(hit, current->content, n) * 255.0f
				* get_light_intensity(current->content);
		if (current_intensity > 255.0f)
			current_intensity = 255.0f;
		add_light_color(shade, current->content, current_intensity, refl);
		if (MAX(current_intensity, ambiant_light) > light_intensity)
			light_intensity = MAX(current_intensity, ambiant_light);
		current = current->next;
	}
	return (light_intensity);
}

void	calc_specular_effect(t_hit *hit, t_vec3 n, t_vec3 v, t_shading *shade)
{
	t_color	specular_color;
	t_vec3	h;
	t_vec3	w;
	float	coeff;
	float	current_coeff;
	t_list	*current;
	float	light_intensity;

	light_intensity = 0.0f;
	current = get_minirt()->lights;
	coeff = 0;
	while (current)
	{
		w = get_light_dir(hit, current->content);
		h = vec_norm(vec_add(w, v));
		current_coeff = vec_dot(n, h);
		if (current_coeff < 0)
			current_coeff = 0;
		current_coeff = pow(current_coeff, get_obj_material(hit->obj)->shine
				* pow(get_light_intensity(current->content), 1.4f));
		if (current_coeff > coeff)
		{
			coeff = current_coeff;
			specular_color = get_specular_color(shade->color, hit,
					get_light_intensity(current->content));
			light_intensity = get_light_intensity(current->content) * 255.0f;
		}
		current = current->next;
	}
	shade->intensity += coeff * (light_intensity - shade->intensity);
	shade->color = color_add(shade->color, color_scale(specular_color, coeff));
}

t_color	shading_color(t_hit *hit, t_vec3 n, t_shading *shade, int *refl,
		t_vec3 v)
{
	t_material	*mat;

	mat = get_obj_material(hit->obj);
	if (mat->shine != 0)
		calc_specular_effect(hit, n, v, shade);
	if (mat->reflexion != 0)
		calc_reflexion(hit, n, v, shade, refl);
	return (shade->color);
}

t_shading	shading(t_hit *hit)
{
	t_vec3		n;
	t_shading	shade;
	int			refl;
	t_vec3		v;
	t_color		coloradd;

	v = vec_norm(vec_subs(get_minirt()->camera.position, hit->hit_point));
	refl = 0;
	shade.color = get_texture_color(hit);
	n = get_normal_vec(hit);
	shade.intensity = shading_intensity(hit, n, &shade, refl);
	shade.color = shading_color(hit, n, &shade, &refl, v);
	coloradd = color_scale(get_minirt()->ambiant_light.color,
							get_minirt()->ambiant_light.intensity);
	shade.color = color_add(shade.color, coloradd);
	shade.color = max_color(shade.color);
	return (shade);
}
