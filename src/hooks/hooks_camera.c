#include "minirt.h"

void	camera_translation(t_minirt *minirt, keys_t key)
{
	if (key == MLX_KEY_RIGHT)
		minirt->camera.position.x += 5;
	if (key == MLX_KEY_LEFT)
		minirt->camera.position.x -= 5;
	if (key == MLX_KEY_DOWN)
		minirt->camera.position.y -= 5;
	if (key == MLX_KEY_UP)
		minirt->camera.position.y += 5;


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
