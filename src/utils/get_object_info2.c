#include "minirt.h"

t_vec3	get_plane_direction(t_object *object)
{
	t_plan	*plane;

	if (object->type == PLAN)
	{
		plane = (t_plan *)object->obj;
		return (plane->direction);
	}
	return (generate_vector(0, 0, 0));
}

t_vec3	get_cylinder_direction(t_object *object)
{
	t_cylindre	*cyl;

	if (object->type == CYLINDRE)
	{
		cyl = (t_cylindre *)object->obj;
		return (cyl->direction);
	}
	return (generate_vector(0, 0, 0));
}

t_material	*get_obj_material(t_object *obj)
{
	t_sphere	*sphere;
	t_plan		*plane;
	t_cylindre	*cylindre;
	t_cone		*cone;

	if (obj->type == SPHERE)
	{
		sphere = (t_sphere *)obj->obj;
		return (sphere->material);
	}
	else if (obj->type == PLAN)
	{
		plane = (t_plan *)obj->obj;
		return (plane->material);
	}
	else if (obj->type == CYLINDRE)
	{
		cylindre = (t_cylindre *)obj->obj;
		return (cylindre->material);
	}
	else if (obj->type == CONE)
	{
		cone = (t_cone *)obj->obj;
		return (cone->material);
	}
	else
		return (NULL);
}

float	*get_height(t_object *object)
{
	t_cylindre	*cylinder;

	if (object->type == CYLINDRE)
	{
		cylinder = (t_cylindre *)object->obj;
		return (&cylinder->hauteur);
	}
	return (NULL);
}

float	*get_radius(t_object *object)
{
	t_sphere	*sphere;
	t_cylindre	*cylinder;

	if (object->type == SPHERE)
	{
		sphere = (t_sphere *)object->obj;
		return (&sphere->rayon);
	}
	if (object->type == CYLINDRE)
	{
		cylinder = (t_cylindre *)object->obj;
		return (&cylinder->rayon);
	}
	return (NULL);
}
