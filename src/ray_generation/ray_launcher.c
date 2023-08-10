#include "minirt.h"

static t_vec3 up_guide(void)
{
	t_vec3 up_guide;

	up_guide.x = 0.0f;
	up_guide.y = 1.0f;
	up_guide.z = 0.0f;
	return (up_guide);
}

static t_vec3 get_d(t_ray_info ray)
{
	t_vec3 d;
	t_vec3 right;
	t_vec3 up;

	right = ray.right;
	up = ray.up;

	right = vec_scale(right, ray.x);
	// right = vec_norm(right);
	up = vec_scale(up, ray.y);
	// up = vec_norm(up);
	d = vec_add(ray.forward, vec_add(up, right));
	d = vec_norm(d);
	return (d);
}

static void init_direcions(t_ray_info *ray)
{
	float aspect_ratio;

	aspect_ratio = (float)get_minirt()->image->width / (float)get_minirt()->image->height;
	ray->height = atanf(get_minirt()->camera.field_of_view);
	ray->width = ray->height * aspect_ratio;
	ray->forward = get_minirt()->camera.direction;
	ray->right = vec_scale(vec_cross(ray->forward, up_guide()), ray->width);
	ray->up = vec_scale(vec_cross(ray->right, ray->forward), ray->height);
	vec_reset(&ray->d);
}

static void pre_launch_operations(t_ray_info *ray)
{
	ray->x = 2.0f * ((float)ray->px + 0.5f) / (float)get_minirt()->image->width - 1;
	ray->y = 2.0f * ((float)ray->py + 0.5f) / (float)get_minirt()->image->height - 1;
	ray->d = get_d(*ray);
}

//optimisation a faire ici...
// d = f + hyu + wxr
void ray_launcher(void)
{
	t_ray_info ray;
	t_hit closest_hit;
	// t_shading shading;

	init_direcions(&ray);
	ray.py = -1;
	while (++ray.py < (int)get_minirt()->image->height)
	{
		ray.px = -1;
		while (++ray.px < (int)get_minirt()->image->width)
		{
			pre_launch_operations(&ray);
			find_closest_hit(ray, &closest_hit);
			
		}
	}
}
