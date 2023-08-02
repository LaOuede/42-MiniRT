#include "minirt.h"

/*
Combines four individual channel bytes into a single integer using
bit-shifting
Use with mlx_put_pixel as 4th param (uint_32 color)
*/
int	get_rgba(float r, float g, float b, float a)
{
	return ((int)r << 24 | (int)g << 16 | (int)b << 8 | (int)a);
}
