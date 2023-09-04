#include "minirt.h"

/*
Surface normal vector calcul :
	// n = nrm(P-C-V*m)
*/
t_vec3	calc_normal(t_qdt q, t_cylindre *cyl)
{
	t_vec3	p;
	t_vec3	c;
	t_vec3	pc;
	t_vec3	vm;
	t_vec3	n;

	p = vec_add(q.origin, vec_scale(q.d, q.t));
	c = vec_subs(cyl->position, (vec_scale(vec_norm(cyl->direction), \
		cyl->hauteur / 2)));
	pc = vec_subs(p, c);
	vm = vec_scale(vec_norm(cyl->direction), q.m);
	n = vec_norm(vec_subs(pc, vm));
	return (n);
}

static void	hit_cylinder_norm(t_qdt q, t_hit *hit, t_cylindre *cyl, \
	t_object *packed_cylinder)
{
	if (q.t < 0.00001 || fabs(q.m) > cyl->hauteur / 2)
	{
		q.t = (-q.half_b + sqrtf(q.discriminant)) / q.a;
		q.m = vec_dot(q.d, vec_norm(cyl->direction)) * q.t + \
			vec_dot(q.disp, vec_norm(cyl->direction));
		if (q.t < 0.00001 || fabs(q.m) > cyl->hauteur / 2)
		{
			hit->obj = NULL;
			hit->t = ERROR;
			return ;
		}
		else
		{
			hit->obj = packed_cylinder;
			hit->t = q.t;
			hit->normal_cyl = calc_normal(q, cyl);
		}
	}
	else
	{
		hit->obj = packed_cylinder;
		hit->t = q.t;
		hit->normal_cyl = calc_normal(q, cyl);
	}
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
void	hit_cylinder(t_vec3 d, t_object *packed_cylinder, \
	t_hit *hit, t_vec3 origin)
{
	t_qdt		q;
	t_cylindre	*cyl;

	cyl = (t_cylindre *)packed_cylinder->obj;
	q.disp = vec_subs(origin, cyl->position);
	q.a = vec_dot(d, d) - pow(vec_dot(d, vec_norm(cyl->direction)), 2);
	q.half_b = vec_dot(d, q.disp) - vec_dot(d, vec_norm(cyl->direction)) \
		* vec_dot(q.disp, vec_norm(cyl->direction));
	q.c = vec_dot(q.disp, q.disp) - pow(vec_dot(q.disp, \
		vec_norm(cyl->direction)), 2) - pow(cyl->rayon, 2);
	q.discriminant = pow(q.half_b, 2) - (q.a * q.c);
	if (q.discriminant < 0.00001)
	{
		hit->obj = NULL;
		hit->t = ERROR;
		return ;
	}
	q.t = (-q.half_b - sqrtf(q.discriminant)) / q.a;
	q.m = vec_dot(d, vec_norm(cyl->direction)) * q.t + vec_dot(q.disp, \
		vec_norm(cyl->direction));
	q.origin = origin;
	q.d = d;
	hit_cylinder_norm(q, hit, cyl, packed_cylinder);
}

// void	hit_cylinder(t_vec3 d, t_object *packed_cylinder, t_hit *hit, t_vec3 origin)
// {
// 	float		a;
// 	float		b;
// 	float		c;
// 	float		t;
// 	float		discriminant;
// 	t_vec3		displacement;
// 	t_cylindre	*cylinder;

// 	cylinder = packed_cylinder->obj;
// 	displacement = vec_subs(origin, cylinder->position);
// 	a = vec_dot(d, d);
// 	b = vec_dot(vec_scale(d, 2.0f), displacement);
// 	c = vec_dot(displacement, displacement) - pow(cylinder->rayon, 2);
// 	discriminant = pow(b, 2) - (4.0f * a * c);
// 	if (discriminant < 0.0f)
// 	{
// 		hit->obj = NULL;
// 		hit->t = 0.0f;
// 	}
// 	else
// 	{
// 		t = (-b - sqrtf(discriminant)) / (2.0f * a);
// 		if (t < 0.00001)
// 		{
// 			t = (-b + sqrtf(discriminant)) / (2.0f * a);
// 			if (t < 0.00001)
// 			{
// 				hit->t = 0.0f;
// 				hit->obj = NULL;
// 			}
// 			else
// 			{
// 				hit->obj = packed_cylinder;
// 				hit->t = t;
// 			}
// 		}
// 		else
// 		{
// 			hit->obj = packed_cylinder;
// 			hit->t = t;
// 		}
// 	}
// }
