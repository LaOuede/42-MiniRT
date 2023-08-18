#include "minirt.h"


t_color get_texture_color(t_hit *hit)
{
	t_minirt *minirt;
	t_color color;
	unsigned int px;
	unsigned int py;
	unsigned int p_xy;

	minirt = get_minirt();

	uv_map_sphere(hit, &px, &py, minirt->moon.texture);//could be any texture
	p_xy = 4 * (py * get_minirt()->moon.texture->width + px);
	
	color.r = minirt->moon.texture->pixels[p_xy];
	color.g = minirt->moon.texture->pixels[p_xy + 1];
	color.b = minirt->moon.texture->pixels[p_xy + 2];
	return (color);
}
