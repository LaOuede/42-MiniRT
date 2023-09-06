#include "minirt.h"

void	update_light_pos(t_vec3 new_pos, t_light *light)
{
	light->position.x = new_pos.x;
	light->position.y = new_pos.y;
	light->position.z = new_pos.z;
}

void	light_translation_z(t_minirt *minirt, keys_t key)
{
	t_vec3	pos;
	t_vec3	move;
	t_light	*light;

	light = (t_light *)minirt->lights->content;
	move.x = minirt->cam_matrix.p[2][0];
	move.y = minirt->cam_matrix.p[2][1];
	move.z = minirt->cam_matrix.p[2][2];
	move = vec_scale(move, 10);
	pos = get_light_position(light);
	if (key == MLX_KEY_W)
	{
		pos.x -= move.x;
		pos.y -= move.y;
		pos.z -= move.z;
	}
	else if (key == MLX_KEY_S)
	{
		pos.x += move.x;
		pos.y += move.y;
		pos.z += move.z;
	}
	update_light_pos(pos, light);
}

void	light_translation_y(t_minirt *minirt, keys_t key)
{
	t_vec3	pos;
	t_vec3	move;
	t_light	*light;

	light = (t_light *)minirt->lights->content;
	move.x = minirt->cam_matrix.p[1][0];
	move.y = minirt->cam_matrix.p[1][1];
	move.z = minirt->cam_matrix.p[1][2];
	move = vec_scale(move, 10);
	pos = get_light_position(light);
	if (key == MLX_KEY_Q)
	{
		pos.x -= move.x;
		pos.y -= move.y;
		pos.z -= move.z;
	}
	else if (key == MLX_KEY_E)
	{
		pos.x += move.x;
		pos.y += move.y;
		pos.z += move.z;
	}
	update_light_pos(pos, light);
}

void	light_translation_x(t_minirt *minirt, keys_t key)
{
	t_vec3	pos;
	t_vec3	move;
	t_light	*light;

	light = (t_light *)minirt->lights->content;
	move.x = minirt->cam_matrix.p[0][0];
	move.y = minirt->cam_matrix.p[0][1];
	move.z = minirt->cam_matrix.p[0][2];
	move = vec_scale(move, 10);
	pos = get_light_position(light);
	if (key == MLX_KEY_A)
	{
		pos.x -= move.x;
		pos.y -= move.y;
		pos.z -= move.z;
	}
	else if (key == MLX_KEY_D)
	{
		pos.x += move.x;
		pos.y += move.y;
		pos.z += move.z;
	}
	update_light_pos(pos, light);
}