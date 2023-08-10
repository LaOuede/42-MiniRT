#include "minirt.h"

void	light_translation_z(t_minirt *minirt, keys_t key)
{
	t_vec3	move;

	move.x = minirt->cam_matrix.p[2][0];
	move.y = minirt->cam_matrix.p[2][1];
	move.z = minirt->cam_matrix.p[2][2];
	move = vec_scale(move, 0.5);
	if (key == MLX_KEY_R)
		minirt->light->position = vec_add(minirt->light->position, move);
	if (key == MLX_KEY_F)
		minirt->light->position = vec_subs(minirt->light->position, move);
	// Add function to redraw the scene
}

void	light_translation_y(t_minirt *minirt, keys_t key)
{
	t_vec3	move;

	move.x = minirt->cam_matrix.p[1][0];
	move.y = minirt->cam_matrix.p[1][1];
	move.z = minirt->cam_matrix.p[1][2];
	move = vec_scale(move, 0.5);
	if (key == MLX_KEY_W)
		minirt->light->position = vec_add(minirt->light->position, move);
	if (key == MLX_KEY_S)
		minirt->light->position = vec_subs(minirt->light->position, move);
	// Add function to redraw the scene
}

void	light_translation_x(t_minirt *minirt, keys_t key)
{
	t_vec3	move;

	move.x = minirt->cam_matrix.p[0][0];
	move.y = minirt->cam_matrix.p[0][1];
	move.z = minirt->cam_matrix.p[0][2];
	move = vec_scale(move, 0.5);
	if (key == MLX_KEY_D)
		minirt->light->position = vec_add(minirt->light->position, move);
	if (key == MLX_KEY_A)
		minirt->light->position = vec_subs(minirt->light->position, move);
	// Add function to redraw the scene
}
