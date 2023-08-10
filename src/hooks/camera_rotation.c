#include "minirt.h"

void	camera_rotation_roll(t_minirt *minirt, keys_t key)
{
	t_mat4	yaw;

	if (key == MLX_KEY_I)
		yaw = matrix_rotz(5);
	if (key == MLX_KEY_Y)
		yaw = matrix_rotz(-5);
	minirt->cam_matrix = matrix_mult(yaw, minirt->cam_matrix);
	// Add function to redraw the scene
}

void	camera_rotation_pitch(t_minirt *minirt, keys_t key)
{
	t_mat4	yaw;

	if (key == MLX_KEY_U)
		yaw = matrix_roty(5);
	if (key == MLX_KEY_I)
		yaw = matrix_roty(-5);
	minirt->cam_matrix = matrix_mult(yaw, minirt->cam_matrix);
	// Add function to redraw the scene
}

void	camera_rotation_yaw(t_minirt *minirt, keys_t key)
{
	t_mat4	yaw;

	if (key == MLX_KEY_L)
		yaw = matrix_rotx(5);
	if (key == MLX_KEY_J)
		yaw = matrix_rotx(-5);
	minirt->cam_matrix = matrix_mult(yaw, minirt->cam_matrix);
	// Add function to redraw the scene
}
