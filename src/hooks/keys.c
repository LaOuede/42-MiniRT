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

void	keys_object(mlx_key_data_t keydata, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_A)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_D))
		object_translation_x(minirt, keydata.key);
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_Q)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_E))
		object_translation_y(minirt, keydata.key);
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_W)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_S))
		object_translation_z(minirt, keydata.key);
	if (minirt->selected == PLAN
		&& (mlx_is_key_down(minirt->mlx, MLX_KEY_L)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_J)))
		plane_rotation_pitch(minirt, keydata.key);
	if (minirt->selected == PLAN
		&& (mlx_is_key_down(minirt->mlx, MLX_KEY_I)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_K)))
		plane_rotation_yaw(minirt, keydata.key);
	if (minirt->selected == PLAN
		&& (mlx_is_key_down(minirt->mlx, MLX_KEY_O)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_U)))
		plane_rotation_roll(minirt, keydata.key);
	ray_launcher();
}

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

void	mod_light_intensity(float add)
{
	t_light	*light;

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
	else if (mlx_is_key_down(minirt->mlx, MLX_KEY_W)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_S))
		camera_translation_z(minirt, keydata.key);
	else if (mlx_is_key_down(minirt->mlx, MLX_KEY_Q)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_E))
		camera_translation_y(minirt, keydata.key);
	else if (mlx_is_key_down(minirt->mlx, MLX_KEY_L)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_J))
		camera_rotation_pitch(minirt, keydata.key);
	else if (mlx_is_key_down(minirt->mlx, MLX_KEY_I)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_K))
		camera_rotation_yaw(minirt, keydata.key);
	else if (mlx_is_key_down(minirt->mlx, MLX_KEY_RIGHT_SHIFT)
		&& mlx_is_key_down(minirt->mlx, MLX_KEY_EQUAL))
		mod_light_intensity(0.01f);
	else if (mlx_is_key_down(minirt->mlx, MLX_KEY_RIGHT_SHIFT)
		&& mlx_is_key_down(minirt->mlx, MLX_KEY_MINUS))
		mod_light_intensity(-0.01f);
	ray_launcher();
}

/* 
	Handles hook for program mode;
 */
void	keys_mode(void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_1))
	{
		minirt->mode = ROUTINE;
		printf("Mode selected = routine\n");
		ray_launcher();
	}
	else if (mlx_is_key_down(minirt->mlx, MLX_KEY_2))
	{
		minirt->mode = SUPER_ROUTINE;
		printf("Mode selected = super routine\n");
		ray_launcher();
	}
}

/* 
	Handles hook for program closure;
 */
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
	keys_mode(param);
	if (mlx_is_key_down(get_minirt()->mlx, MLX_KEY_C))
	{
		get_minirt()->selected = CAMERA;
		printf("Object selected = camera\n");
	}
	if (get_minirt()->selected == CAMERA)
		keys_camera(keydata, param);
	if (SPHERE <= get_minirt()->selected && get_minirt()->selected <= PLAN)
		keys_object(keydata, param);
	//keys_light(keydata, param);
}
