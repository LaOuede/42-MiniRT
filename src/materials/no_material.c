#include "minirt.h"

void load_no_material(void)
{
	t_minirt *minirt;

	minirt = get_minirt();
	minirt->material[NO_MAT].id = NO_MAT;
	minirt->material[NO_MAT].texture = NULL;
	minirt->material[NO_MAT].norm_map = NULL;
	// minirt->material[NO_MAT].reflexion = 1000;//?
	minirt->material[NO_MAT].reflexion = 5;//?
	minirt->material[NO_MAT].shine = 1000;//?
	minirt->material[NO_MAT].specular_factor = 1;//?
}

// void load_no_material(void)
// {
// 	t_minirt *minirt;

// 	minirt = get_minirt();
// 	minirt->material[NO_MAT].id = NO_MAT;
// 	minirt->material[NO_MAT].texture = NULL;
// 	minirt->material[NO_MAT].norm_map = NULL;
// 	minirt->material[NO_MAT].shine = 4;//?
// 	// minirt->material[NO_MAT].reflexion = 1000;//?
// 	minirt->material[NO_MAT].reflexion = 0;//?
// }

