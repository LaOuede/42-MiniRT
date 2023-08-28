#include "minirt.h"

void	update_d(t_minirt *minirt)
{
	minirt->camera.direction.x = minirt->cam_matrix.p[2][0];
	minirt->camera.direction.y = minirt->cam_matrix.p[2][1];
	minirt->camera.direction.z = minirt->cam_matrix.p[2][2];
}

/* void	camera_rotation_roll(t_minirt *minirt, keys_t key)
{
	t_mat4	roll;

	if (key == MLX_KEY_U)
		roll = matrix_rotz(5);
	if (key == MLX_KEY_O)
		roll = matrix_rotz(-5);
	minirt->cam_matrix = matrix_mult(roll, minirt->cam_matrix);
	update_d(minirt);
} */

void	camera_rotation_pitch(t_minirt *minirt, keys_t key)
{
	t_mat4	pitch;

	if (key == MLX_KEY_L)
		pitch = matrix_roty(1);
	if (key == MLX_KEY_J)
		pitch = matrix_roty(-1);
	minirt->cam_matrix = matrix_mult(pitch, minirt->cam_matrix);
	update_d(minirt);
}

void	camera_rotation_yaw(t_minirt *minirt, keys_t key)
{
	t_mat4	yaw;

/* 	printf("minirt->cam_matrix.p[2][0] = %f\n", minirt->cam_matrix.p[2][0]);
	printf("minirt->cam_matrix.p[2][1] = %f\n", minirt->cam_matrix.p[2][1]);
	printf("minirt->cam_matrix.p[2][2] = %f\n", minirt->cam_matrix.p[2][2]);
	printf("-----------------------------------\n"); */
	if (key == MLX_KEY_I)
		yaw = matrix_rotx(1);
	if (key == MLX_KEY_K)
		yaw = matrix_rotx(-1);
	minirt->cam_matrix = matrix_mult(yaw, minirt->cam_matrix);
	update_d(minirt);
}
