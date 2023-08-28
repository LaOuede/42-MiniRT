#include "minirt.h"

void load_water(void)
{
	t_minirt *minirt;

	minirt = get_minirt();
	minirt->material[WATER].id = WATER;
	minirt->material[WATER].texture = mlx_load_png("textures_png/water/wod_tex.png");
	minirt->material[WATER].norm_map = NULL;
	minirt->material[WATER].shine = 1000;//?
	minirt->material[WATER].reflexion = 0;//?
}
