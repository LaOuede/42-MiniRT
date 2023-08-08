#include "minirt.h"

void	camera_translation(t_minirt *minirt, keys_t key)
{
	if (key == MLX_KEY_RIGHT)
		minirt.
	if (key == MLX_KEY_LEFT)

	if (key == MLX_KEY_DOWN)

	if (key == MLX_KEY_UP)


}

void	keys_camera(mlx_key_data_t keydata, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_RIGHT))
		|| (mlx_is_key_down(minirt->mlx, MLX_KEY_LEFT))
		|| (mlx_is_key_down(minirt->mlx, MLX_KEY_DOWN))
		|| (mlx_is_key_down(minirt->mlx, MLX_KEY_UP))
		camera_translation(minirt, keydata.key);

}