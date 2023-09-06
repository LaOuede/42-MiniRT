#include "minirt.h"

void	keys_rotation(mlx_key_data_t keydata, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (minirt->selected == PLAN && (keydata.key == MLX_KEY_J
			|| keydata.key == MLX_KEY_L))
		plane_rotation_roll(minirt, keydata.key);
	if (minirt->selected == PLAN && (keydata.key == MLX_KEY_I
			|| keydata.key == MLX_KEY_K))
		plane_rotation_pitch(minirt, keydata.key);
	if (minirt->selected == CYLINDRE && (keydata.key == MLX_KEY_J
			|| keydata.key == MLX_KEY_L))
		cyl_rotation_yaw(minirt, keydata.key);
	if (minirt->selected == CYLINDRE && (keydata.key == MLX_KEY_I
			|| keydata.key == MLX_KEY_K))
		cyl_rotation_pitch(minirt, keydata.key);
	if (minirt->selected == CYLINDRE && (keydata.key == MLX_KEY_U
			|| keydata.key == MLX_KEY_O))
		cyl_rotation_roll(minirt, keydata.key);
	if (minirt->selected == CONE && (keydata.key == MLX_KEY_J
			|| keydata.key == MLX_KEY_L))
		cone_rotation_yaw(minirt, keydata.key);
	if (minirt->selected == CONE && (keydata.key == MLX_KEY_I
			|| keydata.key == MLX_KEY_K))
		cone_rotation_pitch(minirt, keydata.key);
	if (minirt->selected == CONE && (keydata.key == MLX_KEY_U
			|| keydata.key == MLX_KEY_O))
		cone_rotation_roll(minirt, keydata.key);
	ray_launcher();
}

void	keys_translation(mlx_key_data_t keydata, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		object_translation_x(minirt, keydata.key);
	else if (keydata.key == MLX_KEY_Q || keydata.key == MLX_KEY_E)
		object_translation_y(minirt, keydata.key);
	else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
		object_translation_z(minirt, keydata.key);
	ray_launcher();
}
