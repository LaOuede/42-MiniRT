#include "minirt.h"

void	plane_rotation_roll(t_minirt *minirt, keys_t key)
{
	t_vec3	dir;
	t_mat4	roll;
	t_mat4	mat;

	dir = get_plane_direction(minirt->obj_selected);
	mat = identity_matrix();
	mat.p[3][0] = dir.x;
	mat.p[3][1] = dir.y;
	mat.p[3][2] = dir.z;
	if (key == MLX_KEY_U)
		roll = matrix_rotz(1);
	if (key == MLX_KEY_O)
		roll = matrix_rotz(-1);
	mat = matrix_mult(roll, mat);
	dir.x = mat.p[3][0];
	dir.y = mat.p[3][1];
	dir.z = mat.p[3][2];
	change_direction(minirt->obj_selected, dir);
}

void	plane_rotation_yaw(t_minirt *minirt, keys_t key)
{
	t_vec3	dir;
	t_mat4	yaw;
	t_mat4	mat;

	dir = get_plane_direction(minirt->obj_selected);
	mat = identity_matrix();
	mat.p[2][0] = dir.x;
	mat.p[2][1] = dir.y;
	mat.p[2][2] = dir.z;
	if (key == MLX_KEY_I)
		yaw = matrix_roty(1);
	if (key == MLX_KEY_K)
		yaw = matrix_roty(-1);
	mat = matrix_mult(yaw, mat);
	dir.x = mat.p[2][0];
	dir.y = mat.p[2][1];
	dir.z = mat.p[2][2];
	change_direction(minirt->obj_selected, dir);
}

/* void	plane_rotation_pitch(t_minirt *minirt, keys_t key)
{
	t_vec3	dir;
	t_mat4	pitch;
	t_mat4	mat;

	dir = get_plane_direction(minirt->obj_selected);
	mat = identity_matrix();
	mat.p[2][0] = dir.x;
	mat.p[2][1] = dir.y;
	mat.p[2][2] = dir.z;
	if (key == MLX_KEY_L)
		pitch = matrix_rotx(1);
	if (key == MLX_KEY_J)
		pitch = matrix_rotx(-1);
	mat = matrix_mult(pitch, mat);
	dir.x = mat.p[2][0];
	dir.y = mat.p[2][1];
	dir.z = mat.p[2][2];
	change_direction(minirt->obj_selected, dir);
} */

void	plane_rotation_pitch(t_minirt *minirt, keys_t key)
{
	t_vec3	dir;
	t_vec3	right;
	t_mat4	pitch;
	t_mat4	mat;

	dir = get_plane_direction(minirt->obj_selected);
	mat = identity_matrix();
	right = vec_norm(vec_cross(dir, up_guide()));
	mat.p[0][0] = right.x;
	mat.p[0][1] = right.y;
	mat.p[0][2] = right.z;
	if (key == MLX_KEY_L)
		pitch = matrix_rotx(1);
	if (key == MLX_KEY_J)
		pitch = matrix_rotx(-1);
	mat = matrix_mult(pitch, mat);
	right.x = mat.p[0][0];
	right.y = mat.p[0][1];
	right.z = mat.p[0][2];
	change_direction(minirt->obj_selected, right);
}
