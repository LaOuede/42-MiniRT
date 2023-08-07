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
	 (d.d)t² + 2d.(p - c)t + (p - c)(p - c) - r² = 0
	|______|  |___________| |___________________|
		a			b				c

*/
bool	hit_sphere(t_ray ray, t_sphere *sphere, t_hit *hit)
{
	float	a;
	float	b;
	float	c;
	float	delta;
	t_vec3	displacement;
 
	displacement = vec_subs(get_minirt()->camera.position,  sphere->position);
	a = vec_dot(ray.direction, ray.direction);
	b = 2.0 * vec_dot(displacement, ray.direction);
	c = vec_dot(displacement,displacement) - sphere->rayon * sphere->rayon;
	delta = b * b - 4 * a * c;
	if (delta < 0.0)
		return (false); // no hit
	else
	{
		hit->t = -b - sqrtf(delta) / (2.0 * a); // distance au point de collision
		hit->col = vec_add(get_minirt()->camera.position, vec_scale(ray.direction, hit->t)); // coord du point de collision = (vecteur directionnel * t) + vecteur origin
		return (true); // HIT!
	}
}
