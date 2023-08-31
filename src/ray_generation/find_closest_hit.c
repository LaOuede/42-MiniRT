#include "minirt.h"

// static bool first_hit(bool action)
// {
// 	static bool first_hit = TRUE;
// 	bool output;

// 	if (action == TRUE)
// 	{
// 		output = first_hit;
// 		first_hit = FALSE;
// 		return (output);
// 	}
// 	else
// 	{
// 		first_hit = TRUE;
// 		return (FALSE);
// 	}
// }

static void init_hit(t_hit *closest_hit, t_hit *hit)
{
	hit->t = 0;
	hit->obj = NULL;
	hit->hit_point = generate_vector(0,0,0);
	closest_hit->t = 0;
	closest_hit->obj = NULL;
	closest_hit->hit_point = generate_vector(0,0,0);
}

static void update_closest_hit(t_hit *closest_hit, t_hit hit)
{
	closest_hit->obj = hit.obj;
	closest_hit->t = hit.t;
}

void find_hit(t_vec3 d, t_object *object, t_hit *hit, t_vec3 origin)
{
	if (object->type == SPHERE)
		hit_sphere(d, object, hit, origin);
	else if (object->type == PLAN)
		hit_plane(d, object, hit, origin);
	else if (object->type == CYLINDRE)
		hit_cylinder(d, object, hit, origin);
}

void find_closest_hit(t_ray_info ray, t_hit *closest_hit, t_vec3 origin)
{
	t_hit		hit;
	t_list		*current;
	t_object	*object;

	init_hit(closest_hit, &hit);
	current = get_minirt()->objects;
	while (current)
	{
		object = current->content;
		find_hit(ray.d, object, &hit, origin);
		if (hit.obj && (ray.first_hit || hit.t < closest_hit->t))
		{
			update_closest_hit(closest_hit, hit);
			ray.first_hit = FALSE;
		}
		current = current->next;
	}

	// if (closest_hit->obj)
	// {
	// 	closest_hit->hit_point = vec_add(get_minirt()->camera.position, vec_scale(ray.d, closest_hit->t));
	// 	mlx_put_pixel(get_minirt()->image, ray.px, ray.py, shading(closest_hit));
	// }
}

t_shading single_ray(t_ray_info ray, t_hit *closest_hit)
{
	t_shading shade;

	if (ray.px == 320 && ray.py == 243){
		printf("");
	}
	find_closest_hit(ray, closest_hit, get_minirt()->camera.position);
	if (closest_hit->obj)
	{
		closest_hit->hit_point = vec_add(get_minirt()->camera.position, vec_scale(ray.d, closest_hit->t));
		closest_hit->hit_point = vec_add(closest_hit->hit_point, vec_scale(get_normal_vec(closest_hit), 0.01));

		shade = shading(closest_hit);
		// return ((u_int32_t)get_rgba(shade.color, shade.intensity));
		return (shade);
		// mlx_put_pixel(get_minirt()->image, ray.px, ray.py, (u_int32_t)get_rgba(shade.color, shade.intensity));
	}
	else
	{
		shade.color = no_color();
		shade.intensity = 0;
		return(shade);
	}
}
