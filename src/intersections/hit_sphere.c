#include "minirt.h"

/*

Equation :
	 (d.d)t² + 2d.(p - c)t + (p - c)(p - c) - r² = 0
	|______|  |___________| |___________________|
		a			b				c

Surface normal vector :
	N = nrm(P - C)
	P = point on the sphere and C = center of the sphere

*/
void	hit_sphere(t_vec3 d, t_object *packed_sphere, t_hit *hit, t_vec3 origin)
{
	float		a;
	float		b;
	float		c;
	float		t;
	float		discriminant;
	t_vec3		displacement;
	t_sphere	*sphere;

	sphere = packed_sphere->obj;
	displacement = vec_subs(origin, sphere->position);
	a = vec_dot(d, d);
	b = vec_dot(vec_scale(d, 2.0f), displacement);
	c = vec_dot(displacement, displacement) - pow(sphere->rayon, 2);
	discriminant = pow(b, 2) - (4.0f * a * c);
	if (discriminant < 0.0f)
	{
		hit->obj = NULL;
		hit->t = 0.0f;
	}
	else
	{
		t = (-b - sqrtf(discriminant)) / (2.0f * a);
		if (t < 0.00001)
		{
			t = (-b + sqrtf(discriminant)) / (2.0f * a);
			if (t < 0.00001)
			{
				hit->t = 0.0f;
				hit->obj = NULL;
			}
			else
			{
				hit->obj = packed_sphere;
				hit->t = t;
			}
		}
		else
		{
			hit->obj = packed_sphere;
			hit->t = t;
		}
	}
}
