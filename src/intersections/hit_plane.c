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
bool	hit_plane(t_object *obj_actuel, t_plan *plane)
{
	float	a;
	float	b;
	float	t;

	a = vec_dot(vec_subs(plane->position, get_minirt()->camera.position), vec_norm(plane->direction));
	b = vec_dot(ray.direction, vec_norm(plane->direction)); // need to change ray.direction
	if (b < 0.0001)
	{
		obj_actuel = NULL;
		return (-1.0); // no hit - means ray is perpendicular to plane
	}
	t = a / b;
	if (t < 0.0001)
	{
		obj_actuel = NULL;
		return (-1.0); // no hit
	}
	else
	{
		obj_actuel = plane;
		return (t); // HIT!
	}
}
/* 		hit->t = t; // distance au point de collision
		hit->col = vec_add(ray.origin, vec_scale(ray.direction, hit->t)); // coord du point de collision = (vecteur directionnel * t) + vecteur origin */
