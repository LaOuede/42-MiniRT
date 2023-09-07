#include "minirt.h"

void	keys_camera(mlx_key_data_t keydata, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		camera_translation_x(minirt, keydata.key);
	else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
		camera_translation_z(minirt, keydata.key);
	else if (keydata.key == MLX_KEY_Q || keydata.key == MLX_KEY_E)
		camera_translation_y(minirt, keydata.key);
	else if (keydata.key == MLX_KEY_I || keydata.key == MLX_KEY_K)
		camera_rotation_pitch(minirt, keydata.key);
	else if (keydata.key == MLX_KEY_J || keydata.key == MLX_KEY_L)
		camera_rotation_yaw(minirt, keydata.key);
	ray_launcher();
}
/* 
static t_list	*switch_lights(t_list **lst)
{
	t_list			*tmp;
	static t_list	*ptr = NULL;

	if (!lst || !(*lst))
		return (NULL);
	if (ptr == NULL)
		ptr = *lst;
	if (ptr->next)
	{
		printf("light = %p\n", ptr);
		tmp = ptr;
		ptr = ptr->next;
		return (tmp);
	}
	else if (ptr->next == NULL)
	{
		tmp = ptr;
		ptr = ((*lst));
		printf("light = %p\n", ptr);
		return (tmp);
	}
	return (NULL);
} */

/* 
	Handles hook for lights;
	Adjust the intensity of the light source and perform
	translation operations on the light source's position.
 */
void	keys_light(mlx_key_data_t keydata, void *param)
{
	t_light		*light;
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	light = (t_light *)minirt->lights->content;
/* 	if (keydata.key == MLX_KEY_BACKSPACE)
	{
		if (light == NULL)
			light = &minirt->lights;
		light = (t_light *)switch_lights(&minirt->lights);
	}
	printf("res light = %p\n", light); */
	if (keydata.key == MLX_KEY_EQUAL && light->intensity < 1.0f)
		light->intensity += 0.1f;
	else if (keydata.key == MLX_KEY_MINUS && light->intensity > 0.1f)
		light->intensity -= 0.1f;
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		light_translation(minirt, keydata.key, 'x');
	else if (keydata.key == MLX_KEY_Q || keydata.key == MLX_KEY_E)
		light_translation(minirt, keydata.key, 'y');
	else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
		light_translation(minirt, keydata.key, 'z');
	ray_launcher();
}
