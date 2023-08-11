#include "minirt.h"

static t_vec3 sphere_normal(t_hit *hit)
{
	// t_sphere *sphere;
	t_vec3 n;
	t_vec3 hit_point;
	t_vec3 sphere_center;

	hit_point = vec_copy(hit->hit_point);
	sphere_center = vec_copy(get_position(hit->obj));

	n = vec_subs(hit_point, sphere_center);
	n = vec_norm(n);
	return (n);
}

static t_vec3 plane_normal(t_hit *hit)
{
	// t_plan *plane;
	t_vec3 n;

	// plane = (t_plan *)hit->obj;
	hit = NULL;
	n = null_vector();
	return (n);
}

static t_vec3 cylinder_normal(t_hit *hit)
{
	// t_cylindre *cylinder;
	t_vec3 n;

	// cylinder =/
	hit = NULL;
	n = null_vector();
	return (n);
}

t_vec3 get_normal_vec(t_hit *hit)
{
	if (hit->obj->type == SPHERE)
	{
		return (sphere_normal(hit));
	}
	else if (hit->obj->type == PLAN)
	{
		return (plane_normal(hit));
	}
	else if (hit->obj->type == CYLINDRE)
	{
		return (cylinder_normal(hit));
	}
	return (null_vector());
}
