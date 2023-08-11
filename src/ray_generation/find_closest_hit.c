#include "minirt.h"

static bool first_hit(bool action)
{
	static bool first_hit = TRUE;
	bool output;

	if (action == TRUE)
	{
		output = first_hit;
		first_hit = FALSE;
		return (output);
	}
	else
	{
		first_hit = TRUE;
		return (FALSE);
	}
}

static void init_hit(t_hit *closest_hit, t_hit *hit)
{
	hit->t = 0;
	hit->obj = NULL;
	hit->hit_point = null_vector();
	closest_hit->t = 0;
	closest_hit->obj = NULL;
	closest_hit->hit_point = null_vector();
}

static void update_closest_hit(t_hit *closest_hit, t_hit hit)
{
	closest_hit->obj = hit.obj;
	closest_hit->t = hit.t;
}

void find_hit(t_vec3 d, t_object *object, t_hit *hit)
{
	if (object->type == SPHERE)
		hit_sphere(d, object, hit);
	else if (object->type == PLAN)
		hit_plane(d, object, hit);
}

void find_closest_hit(t_ray_info ray, t_hit *closest_hit)
{
	t_hit		hit;
	t_list		*current;
	t_object	*object;//a enlever/////////////////////////////////////////////

	init_hit(closest_hit, &hit);
	current = get_minirt()->objects;
	while (current)
	{
		object = current->content;
		find_hit(ray.d, object, &hit);
		if (hit.obj && (first_hit(TRUE) || hit.t < closest_hit->t))
		{
			// if (hit.obj->type == SPHERE)
			// {
			// 	(t_sphere)hit.obj->obj.color;
			// 	mlx_put_pixel(get_minirt()->image, ray.px, ray.py, get_rgba(204, 0, 255, 255));
			// }
			// else
			// 	mlx_put_pixel(get_minirt()->image, ray.px, ray.py, get_rgba(0, 0, 255, 255));
			
			update_closest_hit(closest_hit, hit);
		}
		current = current->next;
	}
	if (closest_hit->obj)
	{
		if (closest_hit->obj->type == SPHERE)
		{
			printf("hi");
		}
		
		closest_hit->hit_point = vec_add(get_minirt()->camera.position, vec_scale(ray.d, closest_hit->t));
		mlx_put_pixel(get_minirt()->image, ray.px, ray.py, shading(closest_hit));
	}
	first_hit(FALSE);
}
