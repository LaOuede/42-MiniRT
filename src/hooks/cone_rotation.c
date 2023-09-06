#include "minirt.h"

void	cone_rotation_pitch(t_minirt *minirt, keys_t key)
{
	t_vec3	dir;
	t_vec3	new_dir;
	t_mat4	pitch;

	dir = get_cone_direction(minirt->obj_selected);
	if (key == MLX_KEY_K)
		pitch = matrix_rotx(5);
	if (key == MLX_KEY_I)
		pitch = matrix_rotx(-5);
	new_dir = matrix_vec_mult(pitch, dir);
	change_direction(minirt->obj_selected, new_dir);
}

void	cone_rotation_yaw(t_minirt *minirt, keys_t key)
{
	t_vec3	dir;
	t_vec3	new_dir;
	t_mat4	yaw;

	dir = get_cone_direction(minirt->obj_selected);
	if (key == MLX_KEY_L)
		yaw = matrix_roty(5);
	if (key == MLX_KEY_J)
		yaw = matrix_roty(-5);
	new_dir = matrix_vec_mult(yaw, dir);
	change_direction(minirt->obj_selected, new_dir);
}

void	cone_rotation_roll(t_minirt *minirt, keys_t key)
{
	t_vec3	dir;
	t_vec3	new_dir;
	t_mat4	roll;

	dir = get_cone_direction(minirt->obj_selected);
	if (key == MLX_KEY_O)
		roll = matrix_rotz(5);
	if (key == MLX_KEY_U)
		roll = matrix_rotz(-5);
	new_dir = matrix_vec_mult(roll, dir);
	change_direction(minirt->obj_selected, new_dir);
}
