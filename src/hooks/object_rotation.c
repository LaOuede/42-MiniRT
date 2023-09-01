#include "minirt.h"

void	plane_rotation_roll(t_minirt *minirt, keys_t key)
{
	t_vec3	dir;
	float	rad;

	dir = get_plane_direction(minirt->obj_selected);
	if (key == MLX_KEY_J)
	{
		rad = 5 * M_PI / 180.0f;
		dir.x = cos(rad) * dir.x - sin(rad) * dir.y;
		dir.y = sin(rad) * dir.x + cos(rad) * dir.y;
	}
	else if (key == MLX_KEY_L)
	{
		rad = -5 * M_PI / 180.0f;
		dir.x = cos(rad) * dir.x - sin(rad) * dir.y;
		dir.y = sin(rad) * dir.x + cos(rad) * dir.y;
	}
	change_direction(minirt->obj_selected, dir);
}

void	plane_rotation_pitch(t_minirt *minirt, keys_t key)
{
	t_vec3	dir;
	float	rad;

	dir = get_plane_direction(minirt->obj_selected);
	if (key == MLX_KEY_I)
	{
		rad = 5 * M_PI / 180.0f;
		dir.y = cos(rad) * dir.y - sin(rad) * dir.z;
		dir.z = sin(rad) * dir.y + cos(rad) * dir.z;
	}
	else if (key == MLX_KEY_K)
	{
		rad = -5 * M_PI / 180.0f;
		dir.y = cos(rad) * dir.y - sin(rad) * dir.z;
		dir.z = sin(rad) * dir.y + cos(rad) * dir.z;
	}
	change_direction(minirt->obj_selected, dir);
}

void	cyl_rotation_pitch(t_minirt *minirt, keys_t key)
{
	t_vec3	dir;
	float	rad;

	dir = get_cylinder_direction(minirt->obj_selected);
	if (key == MLX_KEY_I)
	{
		rad = 5 * M_PI / 180.0f;
		dir.y = cos(rad) * dir.y - sin(rad) * dir.z;
		dir.z = sin(rad) * dir.y + cos(rad) * dir.z;
	}
	else if (key == MLX_KEY_K)
	{
		rad = -5 * M_PI / 180.0f;
		dir.y = cos(rad) * dir.y - sin(rad) * dir.z;
		dir.z = sin(rad) * dir.y + cos(rad) * dir.z;
	}
	change_direction(minirt->obj_selected, dir);
}

void	cyl_rotation_yaw(t_minirt *minirt, keys_t key)
{
	t_vec3	dir;
	float	rad;

	dir = get_cylinder_direction(minirt->obj_selected);
	if (key == MLX_KEY_J)
	{
		rad = 5 * M_PI / 180.0f;
		dir.x = cos(rad) * dir.x + sin(rad) * dir.z;
		dir.z = -sin(rad) * dir.x + cos(rad) * dir.z;
	}
	else if (key == MLX_KEY_L)
	{
		rad = -5 * M_PI / 180.0f;
		dir.x = cos(rad) * dir.x + sin(rad) * dir.z;
		dir.z = -sin(rad) * dir.x + cos(rad) * dir.z;
	}
	change_direction(minirt->obj_selected, dir);
}

void	cyl_rotation_roll(t_minirt *minirt, keys_t key)
{
	t_vec3	dir;
	float	rad;

	dir = get_cylinder_direction(minirt->obj_selected);
	if (key == MLX_KEY_U)
	{
		rad = 5 * M_PI / 180.0f;
		dir.x = cos(rad) * dir.x - sin(rad) * dir.y;
		dir.y = sin(rad) * dir.x + cos(rad) * dir.y;
	}
	else if (key == MLX_KEY_O)
	{
		rad = -5 * M_PI / 180.0f;
		dir.x = cos(rad) * dir.x - sin(rad) * dir.y;
		dir.y = sin(rad) * dir.x + cos(rad) * dir.y;
	}
	change_direction(minirt->obj_selected, dir);
}
