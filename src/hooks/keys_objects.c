#include "minirt.h"

void	keys_sphere(void *param)
{
	float		*radius;
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	radius = get_radius(minirt->obj_selected);
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_EQUAL))
		*radius += 1.0f;
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_MINUS) && *radius > 1.0f)
		*radius -= 1.0f;
	ray_launcher();
}

void	keys_cylinder(void *param)
{
	float		*radius;
	float		*height;
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	height = get_height(minirt->obj_selected);
	radius = get_radius(minirt->obj_selected);
	if (mlx_is_key_down(minirt->mlx, MLX_KEY_H)
		&& mlx_is_key_down(minirt->mlx, MLX_KEY_EQUAL))
		*height += 1.0f;
	else if (mlx_is_key_down(minirt->mlx, MLX_KEY_H)
		&& mlx_is_key_down(minirt->mlx, MLX_KEY_MINUS) && *height > 1.0f)
		*height -= 1.0f;
	else if (mlx_is_key_down(minirt->mlx, MLX_KEY_R)
		&& mlx_is_key_down(minirt->mlx, MLX_KEY_EQUAL))
		*radius += 1.0f;
	else if (mlx_is_key_down(minirt->mlx, MLX_KEY_R)
		&& mlx_is_key_down(minirt->mlx, MLX_KEY_MINUS) && *radius > 1.0f)
		*radius -= 1.0f;
	ray_launcher();
}

void	keys_object(mlx_key_data_t keydata, void *param)
{
	if (mlx_is_key_down(get_minirt()->mlx, MLX_KEY_C))
	{
		get_minirt()->selected = CAMERA;
		printf("Object selected = camera\n");
	}
	if (get_minirt()->selected == CAMERA)
		keys_camera(keydata, param);
	else if (get_minirt()->selected == SPHERE)
	{
		keys_sphere(param);
		keys_translation(keydata, param);
	}
	else if (get_minirt()->selected == CYLINDRE)
	{
		keys_rotation(keydata, param);
		keys_translation(keydata, param);
		keys_cylinder(param);
	}
	else if (get_minirt()->selected == PLAN)
	{
		keys_rotation(keydata, param);
		keys_translation(keydata, param);
	}
}
