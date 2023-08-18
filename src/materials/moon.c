#include "minirt.h"

void load_moon(void)
{
	t_minirt *minirt;

	minirt = get_minirt();
	minirt->material[MOON].texture = mlx_load_png("/Users/macote/cursus42/miniRT_/textures_png/moon/moon_texture.png");
	minirt->material[MOON].norm_map = mlx_load_png("/Users/macote/cursus42/miniRT_/textures_png/moon/moon_normap_6.png");
	minirt->material[MOON].shine = 1000;//?
}
