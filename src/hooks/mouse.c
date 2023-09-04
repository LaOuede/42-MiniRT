#include "minirt.h"

static void	find_closest_object(t_ray_info *ray, t_hit *closest_hit)
{
	t_hit		hit;
	t_list		*current;
	t_object	*object;

	init_hit_mouse(closest_hit, &hit);
	current = get_minirt()->objects;
	while (current)
	{
		object = current->content;
		if (object->type == SPHERE)
			hit_sphere(ray->d, object, &hit, get_minirt()->camera.position);
		else if (object->type == PLAN)
			hit_plane(ray->d, object, &hit, get_minirt()->camera.position);
		else if (object->type == CYLINDRE)
			hit_cylinder_body(ray->d, object, \
			&hit, get_minirt()->camera.position);
		if (hit.obj && (first_hit_mouse(TRUE) || hit.t < closest_hit->t))
		{
			object_selected(hit);
			update_closest_hit_mouse(closest_hit, hit);
		}
		current = current->next;
	}
	first_hit_mouse(FALSE);
}

static t_vec3	get_d_mouse(t_ray_info *ray)
{
	t_vec3	d;
	t_vec3	right;
	t_vec3	up;

	right = ray->right;
	up = ray->up;
	right = vec_scale(right, ray->x);
	up = vec_scale(up, ray->y);
	d = vec_add(ray->forward, vec_add(up, right));
	d = vec_norm(d);
	return (d);
}

static void	init_directions_mouse(t_ray_info *ray)
{
	t_mat4	camera;
	float	aspect_ratio;

	camera = get_minirt()->cam_matrix;
	aspect_ratio = (float)get_minirt()->image->width / \
		(float)get_minirt()->image->height;
	ray->height = atanf(get_minirt()->camera.field_of_view);
	ray->width = ray->height * aspect_ratio;
	ray->forward = get_minirt()->camera.direction;
	ray->right = vec_scale(vec_cross(ray->forward, up_guide_mouse()), \
		ray->width * -1);
	ray->up = vec_scale(vec_cross(vec_norm(ray->right), ray->forward), \
		ray->height);
	ray->forward = vec_scale(ray->forward, 3.0f);
	vec_reset(&ray->d);
	camera = init_cam_matrix(ray->right, ray->up, ray->forward);
	get_minirt()->cam_matrix = camera;
}

static void	ray_mouse(float x, float y)
{
	t_ray_info	ray;
	t_hit		closest_hit;

	init_directions_mouse(&ray);
	ray.x = 2.0f * ((float)x + 0.5f) / (float)get_minirt()->image->width - 1;
	ray.y = 2.0f * ((float)y + 0.5f) / (float)get_minirt()->image->height - 1;
	ray.d = get_d_mouse(&ray);
	find_closest_object(&ray, &closest_hit);
	if (closest_hit.obj)
<<<<<<< HEAD
		printf("x: %f, y: %f, z: %f\n", get_position(closest_hit.obj).x, get_position(closest_hit.obj).y, get_position(closest_hit.obj).z);
	
	get_minirt()->obj_selected = closest_hit.obj;
=======
		get_minirt()->obj_selected = closest_hit.obj;
	else
	{
		get_minirt()->selected = CAMERA;
		printf("Object selected = camera\n");
	}
>>>>>>> 881f68ee5ece49b20c8c047d7e69c37941494779
}

void	minirt_mouse(mouse_key_t button, action_t action, \
	modifier_key_t mods, void *param)
{
	int32_t		x_mouse;
	int32_t		y_mouse;
	t_minirt	*minirt;

	(void)button;
	(void)action;
	(void)mods;
	minirt = (t_minirt *)param;
	if (mlx_is_mouse_down(minirt->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		mlx_get_mouse_pos(minirt->mlx, &x_mouse, &y_mouse);
		printf("Coordinates :\n");
		printf("x_mouse = %d\n", x_mouse);
		printf("y_mouse = %d\n", y_mouse);
		ray_mouse((float)x_mouse, (float)y_mouse);
	}
}
