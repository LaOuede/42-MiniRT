#include "minirt.h"

void	cone_rotation(t_minirt *minirt, keys_t key)
{
	t_vec3	dir;
	t_vec3	new_dir;
	t_mat4	mat;

	dir = get_cone_direction(minirt->obj_selected);
	if (key == MLX_KEY_K)
		mat = matrix_rotx(5);
	if (key == MLX_KEY_I)
		mat = matrix_rotx(-5);
	if (key == MLX_KEY_L)
		mat = matrix_roty(5);
	if (key == MLX_KEY_J)
		mat = matrix_roty(-5);
	if (key == MLX_KEY_O)
		mat = matrix_rotz(5);
	if (key == MLX_KEY_U)
		mat = matrix_rotz(-5);
	new_dir = matrix_vec_mult(mat, dir);
	change_direction(minirt->obj_selected, new_dir);
}

void	cyl_rotation(t_minirt *minirt, keys_t key)
{
	t_vec3	dir;
	t_vec3	new_dir;
	t_mat4	mat;

	dir = get_cylinder_direction(minirt->obj_selected);
	if (key == MLX_KEY_K)
		mat = matrix_rotx(5);
	if (key == MLX_KEY_I)
		mat = matrix_rotx(-5);
	if (key == MLX_KEY_L)
		mat = matrix_roty(5);
	if (key == MLX_KEY_J)
		mat = matrix_roty(-5);
	if (key == MLX_KEY_O)
		mat = matrix_rotz(5);
	if (key == MLX_KEY_U)
		mat = matrix_rotz(-5);
	new_dir = matrix_vec_mult(mat, dir);
	change_direction(minirt->obj_selected, new_dir);
}

void	plane_rotation(t_minirt *minirt, keys_t key)
{
	t_vec3	dir;
	t_vec3	new_dir;
	t_mat4	mat;

	dir = get_plane_direction(minirt->obj_selected);
	if (key == MLX_KEY_K)
		mat = matrix_rotx(5);
	if (key == MLX_KEY_I)
		mat = matrix_rotx(-5);
	if (key == MLX_KEY_L)
		mat = matrix_roty(5);
	if (key == MLX_KEY_J)
		mat = matrix_roty(-5);
	new_dir = matrix_vec_mult(mat, dir);
	change_direction(minirt->obj_selected, new_dir);
}
