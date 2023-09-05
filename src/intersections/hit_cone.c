#include "minirt.h"

// void	hit_cone_body(t_vec3 d, t_object *packed_cone, \
// 	t_hit *hit, t_vec3 origin)
// {
// 	t_cone	*cone;

// 	cone = (t_cone *)packed_cone;
// 	//v = cone.position
	
// }


	// t_qdt		q;

	// cyl = (t_cylindre *)packed_cylinder->obj;
	// q.disp = vec_subs(origin, cyl->position);
	// q.a = vec_dot(d, d) - pow(vec_dot(d, vec_norm(cyl->direction)), 2);
	// q.half_b = vec_dot(d, q.disp) - vec_dot(d, vec_norm(cyl->direction)) \
	// 	* vec_dot(q.disp, vec_norm(cyl->direction));
	// q.c = vec_dot(q.disp, q.disp) - pow(vec_dot(q.disp, \
	// 	vec_norm(cyl->direction)), 2) - pow(cyl->rayon, 2);
	// q.discriminant = pow(q.half_b, 2) - (q.a * q.c);
	// if (q.discriminant < 0.00001)
	// {
	// 	hit->obj = NULL;
	// 	hit->t = ERROR;
	// 	return ;
	// }
	// q.t = (-q.half_b - sqrtf(q.discriminant)) / q.a;
	// q.m = vec_dot(d, vec_norm(cyl->direction)) * q.t + vec_dot(q.disp, \
	// 	vec_norm(cyl->direction));
	// q.origin = origin;
	// q.d = d;
	// hit_cylinder_norm(q, hit, cyl, packed_cylinder);

