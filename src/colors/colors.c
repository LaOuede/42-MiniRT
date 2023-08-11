#include "minirt.h"

/*
Combines four individual channel bytes into a single integer using
bit-shifting
Use with mlx_put_pixel as 4th param (uint_32 color)

*** I think we don't need a so it will be silenced and assigned to 0 ???***

*/
int	get_rgba(t_color color, float a)
{
	return ((int)color.r << 24 | (int)color.g << 16 | (int)color.b << 8 | (int)a);
}

t_color no_color(void)
{
	t_color color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	return(color);
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
