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

static void init_directions(t_ray_info *ray)
{
	float aspect_ratio;

	aspect_ratio = (float)get_minirt()->image->width / (float)get_minirt()->image->height;
	ray->height = atanf(get_minirt()->camera.field_of_view);
	ray->width = ray->height * aspect_ratio;
	ray->forward = get_minirt()->camera.direction;
	ray->right = vec_scale(vec_cross(ray->forward, up_guide()), ray->width);
	ray->right = vec_scale(ray->right, -1);
	ray->up = vec_scale(vec_cross(vec_norm(ray->right), ray->forward), ray->height);
	// ray->up = vec_scale(ray->up, -1); 
	ray->forward = vec_scale(ray->forward, 3.0f);
	vec_reset(&ray->d);
	get_minirt()->cam_matrix = init_cam_matrix(ray->right, ray->up, ray->forward);
}

static void pre_launch_operations(t_ray_info *ray, float added_px, float added_py)
{
	ray->x = 2.0f * ((float)ray->px + added_px) / (float)get_minirt()->image->width - 1;
	ray->y = 2.0f * ((float)ray->py + added_py) / (float)get_minirt()->image->height - 1;
	// ray->x = 2.0f * ((float)ray->px + 0.5f) / (float)get_minirt()->image->width - 1;
	// ray->y = 2.0f * ((float)ray->py + 0.5f) / (float)get_minirt()->image->height - 1;
	ray->first_hit = TRUE;
	ray->d = get_d(*ray);
}

void single_sample(t_thread *thread, t_shading *shade, float added_px, float added_py)
{
	pre_launch_operations(&thread->ray, added_px, added_py);
	find_closest_hit(thread->ray, &thread->closest_hit);
	if (thread->closest_hit.obj)
	{
		thread->closest_hit.hit_point = vec_add(get_minirt()->camera.position, vec_scale(thread->ray.d, thread->closest_hit.t));
		shading(&thread->closest_hit, shade);
	}
	else
	{
		shade->color = no_color();
		shade->intensity = 0.0f;
	}
}

void super_sample_pixel(t_thread *thread)
{
	t_shading	shade[4];
	t_color		result_color;
	float		result_intensity;
	u_int32_t	hexa_color;
	int i;

	single_sample(thread, &shade[0], 0.25f, 0.25f);
	single_sample(thread, &shade[1], 0.25f, 0.75f);
	single_sample(thread, &shade[2], 0.75f, 0.25f);
	single_sample(thread, &shade[3], 0.75f, 0.75f);


	result_color = no_color();
	result_intensity = 0.0f;
	i = 0;
	while (i < 4)
	{
		result_color.r += shade[i].color.r;
		result_color.g += shade[i].color.g;
		result_color.b += shade[i].color.b;
		result_intensity += shade[i].intensity;
		i++;
	}
		result_color.r /= 4.0f;
		result_color.g /= 4.0f;
		result_color.b /= 4.0f;
		result_intensity /= 4.0f;


	hexa_color = (u_int32_t)get_rgba(result_color, result_intensity);




	mlx_put_pixel(get_minirt()->image, thread->ray.px, thread->ray.py, hexa_color);
}

void *routine(void *package)
{
	t_thread *thread;
	int scr_height;
	int scr_width;

	scr_height = (int)get_minirt()->image->height;
	scr_width = (int)get_minirt()->image->width;
	thread = package;
	thread->ray.py = thread->index;
	while (thread->ray.py < scr_height)
	{
		thread->ray.px = 0;
		while (thread->ray.px < scr_width)
		{
			super_sample_pixel(thread);
			thread->ray.px++;
		}
		thread->ray.py += THREAD_COUNT;
	}
	return (NULL);
}

void ray_launcher(void)
{
	int i;
	t_thread thread[THREAD_COUNT];
	t_ray_info ray;

	init_directions(&ray);
	map_erase(get_minirt());
	i = 0;
	while (i < THREAD_COUNT)
	{
		thread[i].ray = ray;
		thread[i].index = i;
		pthread_create(&thread[i].thread, NULL, &routine, &thread[i]);
		i++;
	}
	i = 0;
	while (i < THREAD_COUNT)
	{
		pthread_join(thread[i].thread, NULL);
		i++;
	}
}