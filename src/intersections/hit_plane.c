#include "minirt.h"

/*

Une structure qui serait accessible depuis l'objet permet de garder les infos pertinentes en lien avec les hits
typedef struct	s_hit
{
	t_vec3	col_pt; // coord du point de collision
	float	t; //distance au point de collision
	t_vec3	normal // Surface normal vector
}	t_hit

Equation :
	       
	     ___a___
	    |       |
	     c - p.n
	t = ---------
	       d.n
	      |___|
			b

Surface normal vector :
	Surface normal vector at point P equals to the plane normal, unless d.n is negative, in which case N = -n.

RUN "make int" to see informations

*/

void	hit_plane(t_vec3 d, t_object *packed_plane, t_hit *hit)
{
	float	a;
	float	b;
	float	t;
	t_plan *plane;

	plane = (t_plan *)packed_plane->obj;
	a = vec_dot(vec_subs(plane->position, get_minirt()->camera.position), vec_norm(plane->direction));
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

/* 		hit->t = t; // distance au point de collision
		hit->col = vec_add(ray.origin, vec_scale(ray.direction, hit->t)); // coord du point de collision = (vecteur directionnel * t) + vecteur origin */
