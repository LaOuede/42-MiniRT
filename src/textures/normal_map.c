#include "minirt.h"

t_color get_normap_value(t_hit *hit)
{
	t_minirt *minirt;
	t_color color;
	unsigned int px;
	unsigned int py;
	unsigned int p_xy;

	minirt = get_minirt();
	uv_map_sphere(hit, &px, &py, minirt->moon.norm_map);//could be any texture
	p_xy = 4 * (py * get_minirt()->moon.norm_map->width + px);

	color.r = minirt->moon.norm_map->pixels[p_xy];
	color.g = minirt->moon.norm_map->pixels[p_xy + 1];
	color.b = minirt->moon.norm_map->pixels[p_xy + 2];
	return (color);
}
