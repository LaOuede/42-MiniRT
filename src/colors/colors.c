#include "minirt.h"

/*
Combines four individual channel bytes into a single integer using
bit-shifting
Use with mlx_put_pixel as 4th param (uint_32 color)

*** I think we don't need a so it will be silenced and assigned to 0 ???***

*/
int	get_rgba(float r, float g, float b, float a)
{
	return ((int)r << 24 | (int)g << 16 | (int)b << 8 | (int)a);
}

/*
SCALE
*/
// int	color_scale(t_color col1, float scale)
// {
// 	t_color	new;

// 	new.r = col1.r * scale;
// 	new.g = col1.g * scale;
// 	new.b = col1.b * scale;
// 	return (get_rgba(new.r, new.g, new.b, 0));
// }
