#include "minirt.h"

void single_ray(t_vec3 grid_position)
{
	t_vec3 d;

	float t_min;
	float t_actuel;
	t_object *obj;
	t_object *obj_actuel;
	

	t_vec3 closest_hit;
	d = vec_unit_vec(grid_position, get_minirt()->camera.position);


	while (get_minirt()->objects->content)
	{
		
		t_actuel = hit_sphere(&obj_actuel);
		if (obj_actuel && t_actuel < t_min)
		{
			obj = obj_actuel;
			t_min = t_actuel;
		}

		get_minirt()->objects->content = get_minirt()->objects->next;
	}
	

	//parcours linked list d'object et met a jour closest hit si hit plus proche

	//shadow_ray(closest_hit)
}

void ray_launcher(mlx_t* mlx)
{
	int py;
	int px;


	float aspect_ratio;
	float height;
	float width;
	t_vec3 grid_position;

	aspect_ratio = mlx->width / mlx->height;
	height = atanf(get_minirt()->camera.field_of_view);
	width = height * aspect_ratio;

	//lauches a ray for every pixel on the screen
	py = 0;
	while (py < mlx->height)
	{
		px = 0;
		while (px < mlx->width)
		{
			grid_position.x = ((2 * px) / width) - 1;
			grid_position.y = ((2 * py) / height) - 1;
			grid_position.z = 0;
			
			single_ray();
			//lauch ray
			px++;
		}
		py++;
	}
}
