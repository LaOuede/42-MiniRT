#include "minirt.h"

/*

Supposons que l'on a une structure t_ray qui contient 2 vectors (origin et direction)
typedef struct	s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray

Une autre structure qui serait accessible depuis l'objet permet de garder les infos pertinentes en lien avec les hits
typedef struct	s_hit
{
	t_vec3	col; // coord du point de collision
	float	t; //distance au point de collision
}	t_hit

Equation :
	       
	     ___a___
	    |       |
	     c - p.n
	t = ---------
	       d.n
	      |___|
			b

*/
/* bool	hit_plane(t_ray ray, t_plan *plane, t_hit *hit)
{
	float	a;
	float	b;
	float	t;

	a = vec_dot(vec_subs(plane->position - ray.origin), vec_norm(plane->direction));
	b = vec_dot(ray.direction, vec_norm(plane->direction));
	if (b < 0.0001)
		return (false); // no hit - means ray is perpendicular to plane
	t = a / b;
	if (t < 0.0)
		return (false); // no hit
	else
	{
		hit->t = t; // distance au point de collision
		hit->col = vec_add(ray.origin, vec_scale(ray.direction, hit->t)); // coord du point de collision = (vecteur directionnel * t) + vecteur origin
		return (true); // HIT!
	}
} */
