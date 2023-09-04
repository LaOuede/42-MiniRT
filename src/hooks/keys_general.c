#include "minirt.h"

/* 
	Handles hook for program mode;
 */
void	keys_mode(void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_1))
	{
		minirt->mode = NORMAL;
		printf("Mode selected = normal sampling\n");
		ray_launcher();
	}
	else if (mlx_is_key_down(minirt->mlx, MLX_KEY_2))
	{
		minirt->mode = SUPER;
		printf("Mode selected = super sampling\n");
		ray_launcher();
	}
}

/* 
	Handles hook for program closure;
 */
void	keys_menu(void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_M))
	{
		print_cmd_menu1();
		print_cmd_menu2();
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

/**
 * This function sets the key callback, which is called when a key is pressed
 * on the keyboard. Useful for single key press detection.
 * 
 * @param[in] mlx The MLX instance handle.
 * @param[in] func The key press callback function.
 * @param[in] param An additional optional parameter.
 * void mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param);
*/
void	minirt_keys(mlx_key_data_t keydata, void *param)
{
	(void) keydata;
	keys_exit(param);
	keys_menu(param);
	keys_mode(param);
	keys_light(param);
	keys_object(keydata, param);
}
