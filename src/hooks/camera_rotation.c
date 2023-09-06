#include "minirt.h"

void	update_d(t_minirt *minirt, t_vec3 new_dir)
{
	minirt->camera.direction.x = new_dir.x;
	minirt->camera.direction.y = new_dir.y;
	minirt->camera.direction.z = new_dir.z;
}

void	camera_rotation_yaw(t_minirt *minirt, keys_t key)
{
	t_mat4			yaw;
	t_vec3			new_dir;

	if (key == MLX_KEY_J)
		yaw = matrix_roty(5);
	if (key == MLX_KEY_L)
		yaw = matrix_roty(-5);
	new_dir = matrix_vec_mult(yaw, minirt->camera.direction);
	update_d(minirt, new_dir);
}

void	camera_rotation_pitch(t_minirt *minirt, keys_t key)
{
	t_mat4			pitch;
	t_vec3			new_dir;

	if (key == MLX_KEY_I && minirt->camera.direction.y < 0.95f)
	{
		pitch = matrix_rotx(5.0f);
		new_dir = matrix_vec_mult(pitch, minirt->camera.direction);
	printf("avant: %f %f %f\n", minirt->camera.direction.x, minirt->camera.direction.y, minirt->camera.direction.z);
		update_d(minirt, new_dir);
	printf("apres: %f %f %f\n", minirt->camera.direction.x, minirt->camera.direction.y, minirt->camera.direction.z);
	}
	if (key == MLX_KEY_K && minirt->camera.direction.y > -0.95f)
	{
		pitch = matrix_rotx(-5.0f);
		new_dir = matrix_vec_mult(pitch, minirt->camera.direction);
		update_d(minirt, new_dir);
	}
}
