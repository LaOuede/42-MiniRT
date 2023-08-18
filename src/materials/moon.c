#include "minirt.h"


void load_moon(void)
{
	t_minirt *minirt;

	minirt = get_minirt();
	// minirt->moon.texture = mlx_load_png("/Users/macote/cursus42/miniRT_/textures_png/lava/lava.png");
	// minirt->moon.norm_map = mlx_load_png("/Users/macote/cursus42/miniRT_/textures_png/lava/lava_normap.png");

	// minirt->moon.texture = mlx_load_png("/Users/macote/cursus42/miniRT_/textures_png/earth/earth_texture.png");
	// minirt->moon.norm_map = mlx_load_png("/Users/macote/cursus42/miniRT_/textures_png/earth/earth_normap.png");

	minirt->moon.texture = mlx_load_png("/Users/macote/cursus42/miniRT_/textures_png/moon/moon_texture.png");
	minirt->moon.norm_map = mlx_load_png("/Users/macote/cursus42/miniRT_/textures_png/moon/moon_normap_6.png");
	minirt->moon.shine = SHINY_FACTOR;//?
}
