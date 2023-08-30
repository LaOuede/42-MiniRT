#include "minirt.h"

/*

Equation :

Surface normal vector :

RUN "make int" to see informations

*/
void	hit_cylinder(t_vec3 d, t_object *packed_cylinder, t_hit *hit, t_vec3 origin)
{
	float		a;
	float		half_b;
	float		c;
	float		discriminant;
	float		t;
	float		m;
	t_cylindre	*cyl;
	t_vec3		displacement; //calculate vector from the origin of the ray to the cylinder's position

	cyl = (t_cylindre *)packed_cylinder->obj;
	displacement = vec_subs(origin, cyl->position);

	// a = D|D - (D|V)^2
	a = vec_dot(d, d) - pow(vec_dot(d, vec_norm(cyl->direction)), 2);
	// b/2 = D|X - (D|V)*(X|V)
	half_b = vec_dot(d, displacement) - vec_dot(d, vec_norm(cyl->direction)) * vec_dot(displacement, vec_norm(cyl->direction));
	//c = X|X - (X|V)^2 - r*r
	c = vec_dot(displacement, displacement) - pow(vec_dot(displacement, vec_norm(cyl->direction)), 2) - pow(cyl->rayon, 2);
	// d = b² - a * c
	discriminant = pow(half_b, 2) - (a * c);
	// No intersection if discriminant < 0
	if (discriminant < 0.00001)
	{
		hit->obj = NULL;
		hit->t = ERROR;
		return ;
	}
	// t = (-b - √d) / a;
	t = (-half_b - sqrtf(discriminant)) / a;
	m = vec_dot(d, vec_norm(cyl->direction)) * t + vec_dot(otoc, vec_norm(cyl->direction));
	if (t < 0.00001 || fabs(m) > cyl->hauteur / 2)
	{
		t = (-half_b + sqrtf(discriminant)) / a;
		m = vec_dot(d, vec_norm(cyl->direction)) * t + vec_dot(otoc, vec_norm(cyl->direction));
		if (t < 0.00001 || fabs(m) > cyl->hauteur / 2)
		{
			hit->obj = NULL;
			hit->t = ERROR;
			return ;
		}
		else
		{
			hit->obj = packed_cylinder;
			hit->t = t; // HIT
		}
	}
	else
	{
		hit->obj = packed_cylinder;
		hit->t = t; // HIT
	}
}
