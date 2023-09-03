#include "minirt.h"

/*
Surface normal vector calcul :
	// n = nrm(P-C-V*m)
*/
t_vec3	calc_normal(t_vec3 origin, t_vec3 d, float t, float m, t_cylindre *cyl)
{
	t_vec3	p;
	t_vec3	c;
	t_vec3	pc;
	t_vec3	vm;
	t_vec3	n;

	p = vec_add(origin, vec_scale(d, t));
	c = vec_subs(cyl->position, (vec_scale(vec_norm(cyl->direction), \
		cyl->hauteur / 2)));
	pc = vec_subs(p, c);
	vm = vec_scale(vec_norm(cyl->direction), m);
	n = vec_norm(vec_subs(pc, vm));
	return (n);
}

/*

Equation :
	a = D|D - (D|V)^2
	b/2 = D|X - (D|V)*(X|V)
	c = X|X - (X|V)^2 - r*r
	d = b² - a * c
	t = (-b - √d) / a; OUTSIDE
	t = (-b + √d) / a; INSIDE
	m = D|V*t + X|V
*/
void	hit_cylinder_body(t_vec3 d, t_object *packed_cylinder, \
	t_hit *hit, t_vec3 origin)
{
	float		a;
	float		half_b;
	float		c;
	float		discriminant;
	float		t;
	float		m;
	t_cylindre	*cyl;
	t_vec3		displacement;

	cyl = (t_cylindre *)packed_cylinder->obj;
	displacement = vec_subs(origin, cyl->position);
	a = vec_dot(d, d) - pow(vec_dot(d, vec_norm(cyl->direction)), 2);
	half_b = vec_dot(d, displacement) - vec_dot(d, vec_norm(cyl->direction)) * \
		vec_dot(displacement, vec_norm(cyl->direction));
	c = vec_dot(displacement, displacement) - pow(vec_dot(displacement, \
		vec_norm(cyl->direction)), 2) - pow(cyl->rayon, 2);
	discriminant = pow(half_b, 2) - (a * c);
	// No intersection if discriminant < 0
	if (discriminant < 0.00001)
	{
		hit->obj = NULL;
		hit->t = ERROR;
		return ;
	}
	t = (-half_b - sqrtf(discriminant)) / a;
	m = vec_dot(d, vec_norm(cyl->direction)) * t + vec_dot(displacement, \
		vec_norm(cyl->direction));
	if (t < 0.00001 || fabs(m) > cyl->hauteur / 2)
	{
		t = (-half_b + sqrtf(discriminant)) / a;
		m = vec_dot(d, vec_norm(cyl->direction)) * t + vec_dot(displacement, \
			vec_norm(cyl->direction));
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
			hit->normal_cyl = calc_normal(origin, d, t, m, cyl);
		}
	}
	else
	{
		hit->obj = packed_cylinder;
		hit->t = t; // HIT
		hit->normal_cyl = calc_normal(origin, d, t, m, cyl);
	}
}
