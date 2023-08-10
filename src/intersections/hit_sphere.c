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
void	hit_sphere(t_vec3 d, t_object *packed_sphere, t_hit *hit)
{
	float	a;
	float	b;
	float	c;
	float	delta;
	t_vec3	displacement;
	t_sphere *sphere;

	sphere = packed_sphere->obj;

	displacement = vec_subs(get_minirt()->camera.position,  sphere->position);
	a = vec_dot(d, d);
	b = 2.0 * vec_dot(displacement, d);
	c = vec_dot(displacement,displacement) - sphere->rayon * sphere->rayon;
	delta = b * b - 4 * a * c;
	if (delta < 0.0)
	{
		hit->obj = NULL;
		hit->t = ERROR;
	}
	else
	{
		// hit->col = vec_add(get_minirt()->camera.position, vec_scale(ray.direction, hit->t)); // coord du point de collision = (vecteur directionnel * t) + vecteur origin
		hit->obj = packed_sphere;
		hit->t = -b - sqrtf(delta) / (2.0 * a); // distance au point de collision
	}
}

/* 		hit->t = -b - sqrtf(delta) / (2.0 * a); // distance au point de collision
		hit->col_pt = vec_add(ray.origin, vec_scale(ray.direction, hit->t)); // coord du point de collision = (vecteur directionnel * t) + vecteur origin
		hit->normal = vec_norm(vec_subs(hit->col_pt , sphere->position))*/
