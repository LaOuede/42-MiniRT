#include "minirt.h"

/**
 * This function sets the key callback, which is called when a key is pressed
 * on the keyboard. Useful for single key press detection.
 * 
 * @param[in] mlx The MLX instance handle.
 * @param[in] func The key press callback function.
 * @param[in] param An additional optional parameter.
 * void mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param);
*/

/* void	keys_object(mlx_key_data_t keydata, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_C)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_B))
		object_translation_x(minirt, keydata.key);
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_W)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_S))
		object_translation_y(minirt, keydata.key);
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_R)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_F))
		object_translation_y(minirt, keydata.key);
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_L)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_J))
		object_rotation_yaw(minirt, keydata.key);
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_I)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_K))
		object_rotation_pitch(minirt, keydata.key);
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_O)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_U))
		object_rotation_roll(minirt, keydata.key);
	ray_launcher();
} */

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

void mod_light_intensity(float add)
{
	t_light *light;

	light = (t_light *)get_minirt()->lights->content;

	light->intensity += add;
	if (light->intensity > 1.0f)
		light->intensity = 1.0f;
	else if (light->intensity < 0.0f)
		light->intensity = 0.0f;
}

void	keys_camera(mlx_key_data_t keydata, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_A)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_D))
		camera_translation_x(minirt, keydata.key);
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_W)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_S))
		camera_translation_y(minirt, keydata.key);
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_Q)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_E))
		camera_translation_z(minirt, keydata.key);
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_L)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_J))
		camera_rotation_yaw(minirt, keydata.key);
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_I)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_K))
		camera_rotation_pitch(minirt, keydata.key);
	
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_RIGHT_SHIFT)
		&& mlx_is_key_down(minirt->mlx, MLX_KEY_EQUAL))
		mod_light_intensity(0.05f);

	if (mlx_is_key_down(minirt->mlx, MLX_KEY_RIGHT_SHIFT)
		&& mlx_is_key_down(minirt->mlx, MLX_KEY_MINUS))
		mod_light_intensity(-0.05f);
	
/* 	if (mlx_is_key_down(minirt->mlx, MLX_KEY_O)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_U))
		camera_rotation_roll(minirt, keydata.key); */
	ray_launcher();
}

// /*
// 	Handles hook for program closure;
// */
void	keys_exit(void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_ESCAPE))
	{
		free_minirt();
		exit(EXIT_SUCCESS);
	}
}

void	minirt_keys(mlx_key_data_t keydata, void *param)
{
	(void) keydata;
	keys_exit(param);
	keys_camera(keydata, param);
	//keys_light(keydata, param);
	//keys_object(keydata, param);
}
