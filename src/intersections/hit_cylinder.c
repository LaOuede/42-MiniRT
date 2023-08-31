#include "minirt.h"

/*

Equation :

Surface normal vector :

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
	m = vec_dot(d, vec_norm(cyl->direction)) * t + vec_dot(displacement, vec_norm(cyl->direction));
	if (t < 0.00001 || fabs(m) > cyl->hauteur / 2)
	{
		t = (-half_b + sqrtf(discriminant)) / a;
		m = vec_dot(d, vec_norm(cyl->direction)) * t + vec_dot(displacement, vec_norm(cyl->direction));
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

	############### Normal test 1 ###################
	// n = nrm(P-C-V*m)
/* 	t_vec3	P;
	t_vec3	C;
	t_vec3	PC;
	t_vec3	Vm;

	P = vec_add(origin, vec_scale(d, t));
	C = vec_subs(cyl->position, (vec_scale(vec_norm(cyl->direction), cyl->hauteur / 2)));
	PC = vec_subs(P, C);
	Vm = vec_scale(d, m);
	hit->normal = vec_subs(PC, Vm);
	hit->normal = vec_norm(hit->normal); */


	############### Normal test 2 ###################
	t_vec3	hp;
	t_vec3	C;
	float T;
	t_vec3 pt;

	hp = vec_add(origin, vec_scale(d, t));
	C = vec_subs(cyl->position, (vec_scale(vec_norm(cyl->direction), cyl->hauteur / 2)));
	T = vec_dot(vec_subs(hp, C), vec_norm(cyl->direction));
	pt = vec_add(C, vec_scale(vec_norm(cyl->direction), T));
	hit->normal = vec_norm(vec_subs(hp, pt));

	############### Normal test 3 ###################
/* 	t_vec3	cross_prod;
	cross_prod = vec_cross(vec_norm(hit->d), vec_norm(cyl->direction));
	hit->normal = vec_norm(vec_cross(cross_prod, vec_norm(cyl->direction))); */
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
