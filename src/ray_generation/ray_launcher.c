#include "minirt.h"

static t_vec3 get_d(t_ray_info ray)
{
	t_vec3 d;
	t_vec3 right;
	t_vec3 up;

	right = ray.right;
	up = ray.up;

	right = vec_scale(right, ray.x);
	up = vec_scale(up, ray.y);
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
	ray->forward = vec_scale(ray->forward, 3.0f);
	vec_reset(&ray->d);
	get_minirt()->cam_matrix = init_cam_matrix(ray->right, ray->up, ray->forward);
}

static void pre_launch_operations(t_ray_info *ray)
{
	ray->x = 2.0f * ((float)ray->px + 0.5f) / (float)get_minirt()->image->width - 1;
	ray->y = 2.0f * ((float)ray->py + 0.5f) / (float)get_minirt()->image->height - 1;
	ray->first_hit = TRUE;
	ray->d = get_d(*ray);
}

void *routine(void *package)
{
	t_thread *thread;
	t_shading shade;

	thread = package;
	thread->ray.py = thread->index;
	while (thread->ray.py < thread->scr_height)
	{
		thread->ray.px = 0;
		while (thread->ray.px < thread->scr_width)
		{
			
			pre_launch_operations(&thread->ray);
			shade = single_ray(thread->ray, &thread->closest_hit);
			mlx_put_pixel(get_minirt()->image, thread->ray.px, thread->ray.py, (u_int32_t)get_rgba(shade.color, shade.intensity));
			thread->ray.px++;
		}
		thread->ray.py += THREAD_COUNT;
	}
	return (NULL);
}

static void super_pre_launch_operations(t_ray_info *ray, float px_plus, float py_plus)
{
	ray->x = 2.0f * ((float)ray->px + px_plus) / (float)get_minirt()->image->width - 1;
	ray->y = 2.0f * ((float)ray->py + py_plus) / (float)get_minirt()->image->height - 1;
	ray->first_hit = TRUE;
	ray->d = get_d(*ray);
}

void *super_routine(void *package)
{
	t_thread *thread;
	t_shading shades[9];

	thread = package;
	thread->ray.py = thread->index;
	while (thread->ray.py < thread->scr_height)
	{
		thread->ray.px = 0;
		while (thread->ray.px < thread->scr_width)
		{
			// super_pre_launch_operations(&thread->ray, 0.25f, 0.25f);
			// shades[0] = single_ray(thread->ray, &thread->closest_hit);
			// super_pre_launch_operations(&thread->ray, 0.25f, 0.75f);
			// shades[1] = single_ray(thread->ray, &thread->closest_hit);
			// super_pre_launch_operations(&thread->ray, 0.75f, 0.25f);
			// shades[2] = single_ray(thread->ray, &thread->closest_hit);
			// super_pre_launch_operations(&thread->ray, 0.75f, 0.75f);
			// shades[3] = single_ray(thread->ray, &thread->closest_hit);
			// shades[0].color = color_add(add_3_colors(shades[0].color, shades[1].color, shades[2].color), shades[3].color);
			// shades[0].color = color_scale(shades[0].color, 0.25f);
			// shades[0].intensity = (shades[0].intensity + shades[1].intensity + shades[2].intensity + shades[3].intensity) / 4;

			super_pre_launch_operations(&thread->ray, 0.17f, 0.17f);
			shades[0] = single_ray(thread->ray, &thread->closest_hit);
			super_pre_launch_operations(&thread->ray, 0.5f, 0.17f);
			shades[1] = single_ray(thread->ray, &thread->closest_hit);
			super_pre_launch_operations(&thread->ray, 0.83f, 0.17f);
			shades[2] = single_ray(thread->ray, &thread->closest_hit);
			super_pre_launch_operations(&thread->ray, 0.17f, 0.5f);
			shades[3] = single_ray(thread->ray, &thread->closest_hit);
			super_pre_launch_operations(&thread->ray, 0.5f, 0.5f);
			shades[4] = single_ray(thread->ray, &thread->closest_hit);
			super_pre_launch_operations(&thread->ray, 0.83f, 0.5f);
			shades[5] = single_ray(thread->ray, &thread->closest_hit);
			super_pre_launch_operations(&thread->ray, 0.17f, 0.83f);
			shades[6] = single_ray(thread->ray, &thread->closest_hit);
			super_pre_launch_operations(&thread->ray, 0.5f, 0.83f);
			shades[7] = single_ray(thread->ray, &thread->closest_hit);
			super_pre_launch_operations(&thread->ray, 0.83f, 0.83f);
			shades[8] = single_ray(thread->ray, &thread->closest_hit);

			shades[0].color = add_3_colors(shades[0].color, shades[1].color, shades[2].color);
			shades[1].color = add_3_colors(shades[3].color, shades[4].color, shades[5].color);
			shades[2].color = add_3_colors(shades[6].color, shades[7].color, shades[8].color);
			shades[0].color = add_3_colors(shades[0].color, shades[1].color, shades[2].color);
			shades[0].color = color_scale(shades[0].color, 0.11111111f);

			shades[0].intensity = (shades[0].intensity + shades[1].intensity + shades[2].intensity + shades[3].intensity + shades[4].intensity + shades[5].intensity + shades[6].intensity + shades[7].intensity + shades[8].intensity) / 9;


			mlx_put_pixel(get_minirt()->image, thread->ray.px, thread->ray.py, (u_int32_t)get_rgba(shades[0].color, shades[0].intensity));
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
		thread[i].scr_width = (int)get_minirt()->image->width;
		thread[i].scr_height = (int)get_minirt()->image->height;
		if (get_minirt()->mode == ROUTINE)
			pthread_create(&thread[i].thread, NULL, &super_routine, &thread[i]);
		else if (get_minirt()->mode == SUPER_ROUTINE)
			pthread_create(&thread[i].thread, NULL, &super_routine, &thread[i]);
		i++;
	}
	i = 0;
	while (i < THREAD_COUNT)
	{
		pthread_join(thread[i].thread, NULL);
		i++;
	}
}


			// super_pre_launch_operations(&thread->ray, 0.1f, 0.1f);
			// shades[0] = single_ray(thread->ray, &thread->closest_hit);
			// super_pre_launch_operations(&thread->ray, 0.5f, 0.1f);
			// shades[1] = single_ray(thread->ray, &thread->closest_hit);
			// super_pre_launch_operations(&thread->ray, 0.9f, 0.1f);
			// shades[2] = single_ray(thread->ray, &thread->closest_hit);
			// super_pre_launch_operations(&thread->ray, 0.1f, 0.5f);
			// shades[3] = single_ray(thread->ray, &thread->closest_hit);
			// super_pre_launch_operations(&thread->ray, 0.5f, 0.5f);
			// shades[4] = single_ray(thread->ray, &thread->closest_hit);
			// super_pre_launch_operations(&thread->ray, 0.9f, 0.5f);
			// shades[5] = single_ray(thread->ray, &thread->closest_hit);
			// super_pre_launch_operations(&thread->ray, 0.1f, 0.9f);
			// shades[6] = single_ray(thread->ray, &thread->closest_hit);
			// super_pre_launch_operations(&thread->ray, 0.5f, 0.9f);
			// shades[7] = single_ray(thread->ray, &thread->closest_hit);
			// super_pre_launch_operations(&thread->ray, 0.9f, 0.9f);
			// shades[8] = single_ray(thread->ray, &thread->closest_hit);

			// shades[0].color = add_3_colors(shades[0].color, shades[1].color, shades[2].color);
			// shades[1].color = add_3_colors(shades[3].color, shades[4].color, shades[5].color);
			// shades[2].color = add_3_colors(shades[6].color, shades[7].color, shades[8].color);
			// shades[3].color = add_3_colors(shades[0].color, shades[1].color, shades[2].color);
			// shades[0].color = color_scale(shades[0].color, 0.11111111f);

			// shades[0].intensity = (shades[0].intensity + shades[1].intensity + shades[2].intensity + shades[3].intensity + shades[4].intensity + shades[5].intensity + shades[6].intensity + shades[7].intensity + shades[8].intensity) / 9;
