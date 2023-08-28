#include "minirt.h"

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
