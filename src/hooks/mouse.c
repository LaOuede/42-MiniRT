#include "minirt.h"

static bool first_hit_mouse(bool action)
{
	static bool first_hit = TRUE;
	bool output;

	if (action == TRUE)
	{
		output = first_hit;
		first_hit = FALSE;
		return (output);
	}
	else
	{
		first_hit = TRUE;
		return (FALSE);
	}
}

static t_vec3 up_guide_mouse(void)
{
	t_vec3 up_guide;

	up_guide.x = 0.0f;
	up_guide.y = 1.0f;
	up_guide.z = 0.0f;
	return (up_guide);
}

static void init_directions_mouse(t_ray_info *ray)
{
	float aspect_ratio;

	aspect_ratio = (float)get_minirt()->image->width / (float)get_minirt()->image->height;
	ray->height = atanf(get_minirt()->camera.field_of_view);
	ray->width = ray->height * aspect_ratio;
	ray->forward = get_minirt()->camera.direction;
	ray->right = vec_scale(vec_cross(ray->forward, up_guide_mouse()), ray->width * -1);
	ray->up = vec_scale(vec_cross(vec_norm(ray->right), ray->forward), ray->height);
	ray->forward = vec_scale(ray->forward, 3.0f);
	vec_reset(&ray->d);
	get_minirt()->cam_matrix = init_cam_matrix(ray->right, ray->up, ray->forward);
}

static void update_closest_hit_mouse(t_hit *closest_hit, t_hit hit)
{
	closest_hit->obj = hit.obj;
	closest_hit->t = hit.t;
}

static void init_hit_mouse(t_hit *closest_hit, t_hit *hit)
{
	hit->obj = NULL;
	hit->t = 0;
	closest_hit->obj = NULL;
	closest_hit->t = 0;
}

static void find_closest_object(t_ray_info *ray, t_hit *closest_hit)
{
	t_hit		hit;
	t_list		*current;
	t_object	*object;//a enlever/////////////////////////////////////////////

	init_hit_mouse(closest_hit, &hit);
	current = get_minirt()->objects;
	while (current)
	{
		//a changer////////////////////////////////////////////////////////////
		object = current->content;
		if (object->type == SPHERE)
			hit_sphere(ray->d, object, &hit, get_minirt()->camera.position);
		else if (object->type == PLAN)
			hit_plane(ray->d, object, &hit, get_minirt()->camera.position);
		else if (object->type == CYLINDRE)
			hit_cylinder(ray->d, object, &hit, get_minirt()->camera.position);
		///////////////////////////////////////////////////////////////////////

		if (hit.obj && (first_hit_mouse(TRUE) || hit.t < closest_hit->t))
		{
			if (hit.obj->type == SPHERE)
			{
				printf("SPHERE\n");
				get_minirt()->selected = SPHERE;
			}
			if (hit.obj->type == PLAN)
			{
				printf("PLAN\n");
				get_minirt()->selected = PLAN;
			}
			if (hit.obj->type == CYLINDRE)
			{
				printf("CYLINDRE\n");
				get_minirt()->selected = CYLINDRE;
			}
			update_closest_hit_mouse(closest_hit, hit);
		}
		current = current->next;
	}
	first_hit_mouse(FALSE);
}

static t_vec3 get_d_mouse(t_ray_info *ray)
{
	t_vec3 d;
	t_vec3 right;
	t_vec3 up;

	right = ray->right;
	up = ray->up;

	right = vec_scale(right, ray->x);
	// right = vec_norm(right);
	up = vec_scale(up, ray->y);
	// up = vec_norm(up);
	d = vec_add(ray->forward, vec_add(up, right));
	d = vec_norm(d);
	return (d);
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
	get_minirt()->obj_selected = closest_hit.obj;
}

void	minirt_mouse(mouse_key_t button, action_t action, modifier_key_t mods, void* param)
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
		printf("x_mouse = %d\n", x_mouse);
		printf("y_mouse = %d\n", y_mouse);
		ray_mouse((float)x_mouse, (float)y_mouse);
	}
}
