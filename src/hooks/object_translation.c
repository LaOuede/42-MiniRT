#include "minirt.h"

void	object_translation_z(t_minirt *minirt, keys_t key)
{
	t_vec3	move;
	t_vec3	pos;

	move.x = minirt->cam_matrix.p[2][0];
	move.y = minirt->cam_matrix.p[2][1];
	move.z = minirt->cam_matrix.p[2][2];
	move = vec_scale(move, 0.5);
	pos = get_position(minirt->obj_selected);
	if (key == MLX_KEY_S)
	{
		pos.x -= move.x;
		pos.y -= move.y;
		pos.z -= move.z;
	}
	else if (key == MLX_KEY_W)
	{
		pos.x += move.x;
		pos.y += move.y;
		pos.z += move.z;
	}
	change_position(minirt->obj_selected, pos);
}

void	object_translation_y(t_minirt *minirt, keys_t key)
{
	t_vec3	move;
	t_vec3	pos;

	move.x = minirt->cam_matrix.p[1][0];
	move.y = minirt->cam_matrix.p[1][1];
	move.z = minirt->cam_matrix.p[1][2];
	move = vec_scale(move, 0.5);
	pos = get_position(minirt->obj_selected);
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
	change_position(minirt->obj_selected, pos);
}

void	object_translation_x(t_minirt *minirt, keys_t key)
{
	t_vec3	move;
	t_vec3	pos;

	move.x = minirt->cam_matrix.p[0][0];
	move.y = minirt->cam_matrix.p[0][1];
	move.z = minirt->cam_matrix.p[0][2];
	move = vec_scale(move, 0.5);
	pos = get_position(minirt->obj_selected);
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
	change_position(minirt->obj_selected, pos);
}
