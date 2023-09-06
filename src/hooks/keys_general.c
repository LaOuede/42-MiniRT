#include "minirt.h"

/* 
	Handles hook for program mode;
 */
void	keys_mode(mlx_key_data_t keydata, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (keydata.key == MLX_KEY_1)
	{
		minirt->mode = NORMAL;
		printf("Mode selected = normal sampling\n");
		ray_launcher();
	}
	else if (keydata.key == MLX_KEY_2)
	{
		minirt->mode = SUPER;
		printf("Mode selected = super sampling\n");
		ray_launcher();
	}
}

/* 
	Handles hook for program closure;
 */
void	keys_menu(mlx_key_data_t keydata, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (keydata.key ==  MLX_KEY_M)
	{
		print_cmd_menu1();
		print_cmd_menu2();
		ray_launcher();
	}
}

/* 
	Handles hook for program closure;
 */
void	keys_exit(mlx_key_data_t keydata, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		free_minirt();
		exit(EXIT_SUCCESS);
	}
}

static bool	key_is_legit(mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D
		|| keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S
		|| keydata.key == MLX_KEY_Q || keydata.key == MLX_KEY_E
		|| keydata.key == MLX_KEY_J || keydata.key == MLX_KEY_L
		|| keydata.key == MLX_KEY_I || keydata.key == MLX_KEY_K
		|| keydata.key == MLX_KEY_U || keydata.key == MLX_KEY_O
		|| keydata.key == MLX_KEY_M || keydata.key == MLX_KEY_1
		|| keydata.key == MLX_KEY_2 || keydata.key == MLX_KEY_MINUS
		|| keydata.key == MLX_KEY_EQUAL || keydata.key == MLX_KEY_ESCAPE
		|| keydata.key == MLX_KEY_H || keydata.key == MLX_KEY_BACKSPACE
		|| keydata.key == MLX_KEY_C || keydata.key == MLX_KEY_R)
		return (true);
	return (false);
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
	if (key_is_legit(keydata) == true && keydata.action == MLX_PRESS)
	{
		keys_exit(keydata, param);
		keys_menu(keydata, param);
		keys_mode(keydata, param);
		keys_object(keydata, param);
	}
}
