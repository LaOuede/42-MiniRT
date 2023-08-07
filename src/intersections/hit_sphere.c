#include "minirt.h"

/*

Une structure qui serait accessible depuis l'objet permet de garder les infos pertinentes en lien avec les hits
typedef struct	s_hit
{
	t_vec3	col_pt; // coord du point de collision
	float	t; //distance au point de collision
	t_vec3	normal //  Surface normal vector
}	t_hit

Equation :
	 (d.d)t² + 2d.(p - c)t + (p - c)(p - c) - r² = 0
	|______|  |___________| |___________________|
		a			b				c

Surface normal vector :
	N = nrm(P - C)
	P = point on the sphere and C = center of the sphere
RUN "make int" to see informations

*/
float	hit_sphere(t_object *obj_actuel)
{
	float		a;
	float		b;
	float		c;
	float		delta;
	t_vec3		displacement;
	t_sphere	*obj;

	obj = (t_sphere *)obj_actuel;
	displacement = vec_subs(get_minirt()->camera.position, obj->position);
	a = vec_dot(ray.direction, ray.direction); //need to change ray.direction
	b = 2.0 * vec_dot(displacement, ray.direction); //need to change ray.direction
	c = vec_dot(displacement, displacement) - obj->rayon * obj->rayon;
	delta = b * b - 4 * a * c;
	if (delta < 0.0)
	{
		obj_actuel = NULL;
		return (-1.0); // no hit
	}
	else
	{
		obj_actuel = obj;
		return (-b - sqrtf(delta) / (2.0 * a)); // HIT!
	}
}

/* 		hit->t = -b - sqrtf(delta) / (2.0 * a); // distance au point de collision
		hit->col_pt = vec_add(ray.origin, vec_scale(ray.direction, hit->t)); // coord du point de collision = (vecteur directionnel * t) + vecteur origin
		hit->normal = vec_norm(vec_subs(hit->col_pt , sphere->position))*/
