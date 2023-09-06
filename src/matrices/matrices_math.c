#include "minirt.h"

/*
IDENTITY MATRIX
Ihe identity matrix has ones on the main diagonal and zeros elsewhere.
When the identity matrix represents a geometric transformation,
the object remains unchanged by the transformation.
In other contexts, it is analogous to multiplying by the number 1.
*/
t_mat4	identity_matrix(void)
{
	t_mat4	id_mat;

	ft_bzero(&id_mat, sizeof(t_mat4));
	id_mat.p[0][0] = 1;
	id_mat.p[1][1] = 1;
	id_mat.p[2][2] = 1;
	id_mat.p[3][3] = 1;
	return (id_mat);
}

/* 
MULTIPLY MATRIX * VECTOR
*/
t_vec3	matrix_vec_mult(t_mat4 mat, t_vec3 v)
{
	t_vec3	res;

	res.x = (mat.p[0][0] * v.x) + (mat.p[0][1] * v.y) + \
		(mat.p[0][2] * v.z) + mat.p[0][3];
	res.y = (mat.p[1][0] * v.x) + (mat.p[1][1] * v.y) + \
		(mat.p[1][2] * v.z) + mat.p[1][3];
	res.z = (mat.p[2][0] * v.x) + (mat.p[2][1] * v.y) + \
		(mat.p[2][2] * v.z) + mat.p[2][3];
	return (res);
}
