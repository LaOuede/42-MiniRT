#include "minirt.h"

/*

Equation :
	 (d.d)t² + 2d.(p - c)t + (p - c)(p - c) - r² = 0
	|______|  |___________| |___________________|
		a			b				c

Surface normal vector :
	N = nrm(P - C)
	P = point on the sphere and C = center of the sphere

RUN "make int" to see informations

*/
void	hit_sphere(t_vec3 d, t_object *packed_sphere, t_hit *hit, t_vec3 origin)
{
	float		a;
	float		b;
	float		c;
	float		delta;
	t_vec3		displacement;
	t_sphere	*sphere;

	sphere = packed_sphere->obj;
	displacement = vec_subs(origin, sphere->position);
	a = vec_dot(d, d);
	b = vec_dot(vec_scale(d, 2.0f), displacement);
	c = vec_dot(displacement, displacement) - sphere->rayon * sphere->rayon;
	delta = (b * b) - (4.0f * a * c);
	if (delta < 0.0f)
	{
		hit->obj = NULL;
		hit->t = ERROR;
	}
	else
	{
		// hit->col = vec_add(get_minirt()->camera.position, vec_scale(ray.direction, hit->t)); // coord du point de collision = (vecteur directionnel * t) + vecteur origin
		hit->obj = packed_sphere;
		hit->t = (-b - sqrtf(delta)) / (2.0f * a); // distance au point de collision
		if (hit->t < 0.0f)
		{
			hit->t = 0.0f;
			hit->obj = NULL;
		}
	}
}

/* 		hit->t = -b - sqrtf(delta) / (2.0 * a); // distance au point de collision
		hit->col_pt = vec_add(ray.origin, vec_scale(ray.direction, hit->t)); // coord du point de collision = (vecteur directionnel * t) + vecteur origin
		hit->normal = vec_norm(vec_subs(hit->col_pt , sphere->position))*/
