#include "minirt.h"

/*
ROT on axe X
 _                   _
|  1    0     0    0  |
|  0   cos𝜃  sin𝜃   0  |
|  0  -sin𝜃  cos𝜃   0  |
|_ 0    0     0    1 _|
To convert from degrees to radians, multiply the number of degrees by π/180.
*/
void	camera_rotation_pitch(t_minirt *minirt, keys_t key)
{
	t_vec3	*dir;
	float	rad;

	dir = &minirt->camera.direction;
	if (key == MLX_KEY_I)
	{
		rad = 1 * M_PI / 180.0f;
		dir->y = cos(rad) * dir->y - sin(rad) * dir->z;
		dir->z = sin(rad) * dir->y + cos(rad) * dir->z;
	}
	else if (key == MLX_KEY_K)
	{
		rad = -1 * M_PI / 180.0f;
		dir->y = cos(rad) * dir->y - sin(rad) * dir->z;
		dir->z = sin(rad) * dir->y + cos(rad) * dir->z;
	}
}

/*
ROT on axe Y
 _                   _
|  cos𝜃  0  -sin𝜃   0  |
|   0    1    0     0  |
|  sin𝜃  0   cos𝜃   0  |
|_  0    0    0     1 _|
To convert from degrees to radians, multiply the number of degrees by π/180.
*/
void	camera_rotation_yaw(t_minirt *minirt, keys_t key)
{
	t_vec3	*dir;
	float	rad;

	dir = &minirt->camera.direction;
	if (key == MLX_KEY_L)
	{
		rad = 5 * M_PI / 180.0f;
		dir->x = cos(rad) * dir->x + sin(rad) * dir->z;
		dir->z = -sin(rad) * dir->x + cos(rad) * dir->z;
	}
	else if (key == MLX_KEY_J)
	{
		rad = -5 * M_PI / 180.0f;
		dir->x = cos(rad) * dir->x + sin(rad) * dir->z;
		dir->z = -sin(rad) * dir->x + cos(rad) * dir->z;
	}
}
