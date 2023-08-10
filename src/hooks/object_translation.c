#include "minirt.h"

// void	object_translation_z(t_minirt *minirt, keys_t key)
// {
// 	t_vec3	move;

// 	move.x = minirt->cam_matrix.p[2][0];
// 	move.y = minirt->cam_matrix.p[2][1];
// 	move.z = minirt->cam_matrix.p[2][2];
// 	move = vec_scale(move, 0.5);
// 	if (key == MLX_KEY_R)
// 		minirt->camera.position = vec_add(minirt->camera.position, move);
// 	if (key == MLX_KEY_F)
// 		minirt->camera.position = vec_subs(minirt->camera.position, move);
// 	// Add function to redraw the scene
// }

// void	object_translation_y(t_minirt *minirt, keys_t key)
// {
// 	t_vec3	move;

// 	move.x = minirt->cam_matrix.p[1][0];
// 	move.y = minirt->cam_matrix.p[1][1];
// 	move.z = minirt->cam_matrix.p[1][2];
// 	move = vec_scale(move, 0.5);
// 	if (key == MLX_KEY_W)
// 		minirt->camera.position = vec_add(minirt->camera.position, move);
// 	if (key == MLX_KEY_S)
// 		minirt->camera.position = vec_subs(minirt->camera.position, move);
// 	// Add function to redraw the scene
// }

// void	object_translation_x(t_minirt *minirt, keys_t key)
// {
// 	t_vec3	move;

// 	move.x = minirt->cam_matrix.p[0][0];
// 	move.y = minirt->cam_matrix.p[0][1];
// 	move.z = minirt->cam_matrix.p[0][2];
// 	move = vec_scale(move, 0.5);
// 	if (key == MLX_KEY_D)
// 		minirt->camera.position = vec_add(minirt->camera.position, move);
// 	if (key == MLX_KEY_A)
// 		minirt->camera.position = vec_subs(minirt->camera.position, move);
// 	// Add function to redraw the scene
// }
