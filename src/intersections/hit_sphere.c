#include "minirt.h"

/*

Supposons que l'on a une structure t_ray qui contient 2 vectors (origin et direction)
typedef struct	s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray

Une autre structure permet de garder les infos pertinentes
typedef struct	s_hit
{
	t_vec3	col; // coord du point de collision
	float	t; //distance au point de collision
}	t_hit

*/
/* bool	hit_sphere(t_ray ray, t_sphere *sphere, t_hit *hit)
{
	float	a;
	float	b;
	float	c;
	float	discriminant;
	t_vec3	vec;
 
	vec = vec_subs(ray.origin - sphere->position);
	a = vec_dot(ray.direction, ray.direction);
	b = 2.0 * vec_dot(vec, ray.direction);
	c = vec_dot(vec,vec) - sphere->rayon * sphere->rayon;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0.0)
		return (false); // no hit
	else
	{
		hit->t = -b - sqrtf(discriminant) / (2.0 * a); // distance au point de collision
		hit->col = vec_add(ray.origin, vec_scale(ray.direction, hit->t)); // coord du point de collision = (vecteur directionnel * t) + vecteur origin
		return (true); // HIT!
	}
} */
