#include "minirt.h"

void load_water(void)
{
	t_minirt *minirt;

	minirt = get_minirt();
	minirt->material[WATER].texture = mlx_load_png("/Users/macote/cursus42/miniRT/textures_png/water/water_textures_2k.png");
	minirt->material[WATER].norm_map = mlx_load_png("/Users/macote/cursus42/miniRT/textures_png/water/water_textures_2k_normal.png");
	minirt->material[WATER].shine = 1000;//?
}
