#include "minirt.h"

// /*
// MATRIX TRANSLATION
// A translation matrix simply moves an object along one 
// or more of the three axes.
//  _             _
// |  1  0  0  𝘵𝘹  |
// |  0  1  0  𝘵𝘺  |
// |  0  0  1  𝘵𝘻  |
// |_ 0  0  0  1 _|
// */
// t_mat4	matrix_translation(float tx, float ty, float tz)
// {
// 	t_mat4	mat;

// 	mat = identity_matrix();
// 	mat.p[0][3] = tx;
// 	mat.p[1][3] = ty;
// 	mat.p[2][3] = tz;
// 	return (mat);
// }

// /*
// MATRIX SCALE
// A scaling transform changes the size of an object by expanding
// or contracting all voxels or vertices along the three axes
// by three scalar values specified in the matrix.
//  _             _
// |  𝘴𝘹  0  0  0  |
// |  0  𝘴𝘺  0  0  |
// |  0  0  𝘴𝘻  0  |
// |_ 0  0  0  1 _|
// */
// t_mat4	matrix_scale(float sx, float sy, float sz)
// {
// 	t_mat4	mat;

// 	mat = identity_matrix();
// 	mat.p[0][0] = sx;
// 	mat.p[1][1] = sy;
// 	mat.p[2][2] = sz;
// 	return (mat);
// }

/*
MATRIX ROTATION
A rotation matrix rotates an object about one of the three coordinate axes,
or any arbitrary vector.
ROT on axe X
 _                   _
|  1    0     0    0  |
|  0   cos𝜃  sin𝜃   0  |
|  0  -sin𝜃  cos𝜃   0  |
|_ 0    0     0    1 _|
To convert from degrees to radians, multiply the number of degrees by π/180.
*/
t_mat4	matrix_rotx(float angle)
{
	t_mat4	mat;
	float	rad;

	mat = identity_matrix();
	rad = angle * M_PI / 180.0f;
	mat.p[1][1] = cosf(rad);
	mat.p[1][2] = sinf(rad);
	mat.p[2][1] = -sinf(rad);
	mat.p[2][2] = cosf(rad);
	return (mat);
}

/*
MATRIX ROTATION
A rotation matrix rotates an object about one of the three coordinate axes,
or any arbitrary vector.
ROT on axe Y
 _                   _
|  cos𝜃  0  -sin𝜃   0  |
|   0    1    0     0  |
|  sin𝜃  0   cos𝜃   0  |
|_  0    0    0     1 _|
To convert from degrees to radians, multiply the number of degrees by π/180.
*/
t_mat4	matrix_roty(float angle)
{
	t_mat4	mat;
	float	rad;

	rad = angle * M_PI / 180.0f;
	mat = identity_matrix();
	mat.p[0][0] = cosf(rad);
	mat.p[0][2] = -sinf(rad);
	mat.p[2][0] = sinf(rad);
	mat.p[2][2] = cosf(rad);
	return (mat);
}

/*
MATRIX ROTATION
A rotation matrix rotates an object about one of the three coordinate axes,
or any arbitrary vector.
ROT on axe Z
 _                   _
|  cos𝜃  sin𝜃  0  0  |
| -sin𝜃  cos𝜃  0  0  |
|   0     0    1  0  |
|_  0     0    0  1 _|
To convert from degrees to radians, multiply the number of degrees by π/180.
*/
t_mat4	matrix_rotz(float angle)
{
	t_mat4	mat;
	float	rad;

	rad = angle * M_PI / 180.0f;
	mat = identity_matrix();
	mat.p[0][0] = cos(rad);
	mat.p[0][1] = sin(rad);
	mat.p[1][0] = -sin(rad);
	mat.p[1][1] = cos(rad);
	return (mat);
}
