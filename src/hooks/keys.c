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

/*
	Handles hook for program closure;
*/
void	keys_exit(mlx_key_data_t keydata, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_ESCAPE)
		|| mlx_is_key_down(minirt->mlx, MLX_KEY_Q))
		free_minirt();
	
}

void	minirt_keys(mlx_key_data_t keydata, void *param)
{
	(void) param;
	keys_exit(keydata, param);
	keys_size(keydata, param);
	keys_objects(keydata, param);
}
