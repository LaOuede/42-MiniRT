#include "minirt.h"

// void	keys_light(mlx_key_data_t keydata, void *param)
// {
// 	t_minirt	*minirt;

// 	minirt = (t_minirt *)param;
// 	if (mlx_is_key_down(minirt->mlx, MLX_KEY_A)
// 		|| mlx_is_key_down(minirt->mlx, MLX_KEY_D))
// 		ligh_translation_x(minirt, keydata.key);
// 	if (mlx_is_key_down(minirt->mlx, MLX_KEY_W)
// 		|| mlx_is_key_down(minirt->mlx, MLX_KEY_S))
// 		ligh_translation_y(minirt, keydata.key);
// 	if (mlx_is_key_down(minirt->mlx, MLX_KEY_R)
// 		|| mlx_is_key_down(minirt->mlx, MLX_KEY_F))
// 		ligh_translation_y(minirt, keydata.key);
// }

void	keys_camera(mlx_key_data_t keydata, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_A)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_D))
		camera_translation_x(minirt, keydata.key);
	else if (mlx_is_key_down(minirt->mlx, MLX_KEY_W)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_S))
		camera_translation_z(minirt, keydata.key);
	else if (mlx_is_key_down(minirt->mlx, MLX_KEY_Q)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_E))
		camera_translation_y(minirt, keydata.key);
	else if (mlx_is_key_down(minirt->mlx, MLX_KEY_I)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_K))
		camera_rotation_pitch(minirt, keydata.key);
	else if (mlx_is_key_down(minirt->mlx, MLX_KEY_J)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_L))
		camera_rotation_yaw(minirt, keydata.key);
	ray_launcher();
}

static void	mod_light_intensity(float add)
{
	t_light	*light;

	light = (t_light *)get_minirt()->lights->content;
	light->intensity += add;
	if (light->intensity > 1.0f)
		light->intensity = 1.0f;
	else if (light->intensity < 0.0f)
		light->intensity = 0.0f;
}

/* 
	Handles hook for lights;
 */
void	keys_light(void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_RIGHT_SHIFT)
		&& mlx_is_key_down(minirt->mlx, MLX_KEY_EQUAL))
		mod_light_intensity(0.01f);
	else if (mlx_is_key_down(minirt->mlx, MLX_KEY_RIGHT_SHIFT)
		&& mlx_is_key_down(minirt->mlx, MLX_KEY_MINUS))
		mod_light_intensity(-0.01f);
}
