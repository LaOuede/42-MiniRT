#include "minirt.h"

/*

Do the ray touch a plane ?
Does the ray touch the triangle which is a part of the plane ?
plane is defined by the normal of the triangle : cross_prod of 2 edges = normal
how to check if the intersection is inside the triangle : 

Equation :


Surface normal vector :
	Surface normal vector at point P equals to the plane normal, unless d.n is negative, in which case N = -n.

*/

void	hit_plane(t_vec3 d, t_object *packed_plane, t_hit *hit, t_vec3 origin)
{
	float	a;
	float	b;
	float	t;
	t_plan *plane;

	plane = (t_plan *)packed_plane->obj;
	a = vec_dot(vec_subs(plane->position, origin), vec_norm(plane->direction));
	b = vec_dot(d, vec_norm(plane->direction)); // need to change ray.direction
	if (b < 0.0001)
	{
		// no hit - means ray is perpendicular to plane
		hit->obj = NULL;
	}
	t = a / b;
	if (t < 0.0001)
	{
		// no hit
		hit->obj = NULL;
	}
	else
	{
		hit->obj = packed_plane;
		hit->t = t; // HIT
	}
}
