#include "minirt.h"

void	camera_translation(t_minirt *minirt, keys_t key)
{
	t_mat4	move;

	move = vec_scale(minirt->camera.direction, 0.75);
	if (key == MLX_KEY_RIGHT)
		minirt->camera.direction = vec_add(minirt->camera.direction, move);
	if (key == MLX_KEY_LEFT)
		minirt->camera.direction = vec_subs(minirt->camera.direction, move);
	if (key == MLX_KEY_DOWN)
		minirt->camera.direction = vec_add(minirt->camera.direction, move);
	if (key == MLX_KEY_UP)
		minirt->camera.direction = vec_subs(minirt->camera.direction, move);


}

void	keys_camera(mlx_key_data_t keydata, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_UP))
		camera_translation(minirt, keydata.key);
}
