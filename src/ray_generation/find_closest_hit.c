#include "minirt.h"

static bool first_hit(void)
{
	static bool first_hit = TRUE;
	bool output;

	output = first_hit;
	first_hit = FALSE;
	return (output);
}

static void init_hit(t_hit *closest_hit, t_hit *hit)
{
	hit->obj = NULL;
	hit->t = 0;
	closest_hit->obj = NULL;
	closest_hit->t = 0;
}

static void update_closest_hit(t_hit *closest_hit, t_hit hit)
{
	closest_hit->obj = hit.obj;
	closest_hit->t = hit.t;
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
		//a changer////////////////////////////////////////////////////////////
		object = current->content;
		if (object->type == SPHERE)
			hit.t = hit_sphere(ray.d, object, &hit);
		///////////////////////////////////////////////////////////////////////

		if (hit.obj && (first_hit() || hit.t < closest_hit->t))
		{
			update_closest_hit(&closest_hit, hit);
		}
		current = current->next;
	}
}
