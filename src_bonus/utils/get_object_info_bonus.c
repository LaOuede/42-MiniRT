/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object_info_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/09/19 14:11:04 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

void	change_direction(t_object *object, t_vec3 new_direction)
{
	t_plan		*plane;
	t_cone		*cone;
	t_cylindre	*cylinder;

	if (object->type == PLAN)
	{
		plane = (t_plan *)object->obj;
		plane->direction = new_direction;
	}
	if (object->type == CYLINDRE)
	{
		cylinder = (t_cylindre *)object->obj;
		cylinder->direction = new_direction;
	}
	if (object->type == CONE)
	{
		cone = (t_cone *)object->obj;
		cone->direction = new_direction;
	}
}

void	change_position(t_object *object, t_vec3 new_position)
{
	t_sphere	*sphere;
	t_plan		*plane;
	t_cone		*cone;
	t_cylindre	*cylinder;

	if (object->type == SPHERE)
	{
		sphere = (t_sphere *)object->obj;
		sphere->position = new_position;
	}
	if (object->type == PLAN)
	{
		plane = (t_plan *)object->obj;
		plane->position = new_position;
	}
	if (object->type == CYLINDRE)
	{
		cylinder = (t_cylindre *)object->obj;
		cylinder->position = new_position;
	}
	if (object->type == CONE)
	{
		cone = (t_cone *)object->obj;
		cone->position = new_position;
	}
}

t_vec3	get_position(t_object *object)
{
	if (object->type == SPHERE)
	{
		return (((t_sphere *)object->obj)->position);
	}
	if (object->type == PLAN)
	{
		return (((t_plan *)object->obj)->position);
	}
	if (object->type == CYLINDRE)
	{
		return (((t_cylindre *)object->obj)->position);
	}
	if (object->type == CONE)
	{
		return (((t_cone *)object->obj)->position);
	}
	return (generate_vector(0, 0, 0));
}

t_color	get_obj_color(t_object *obj)
{
	if (obj->type == SPHERE)
	{
		return (((t_sphere *)obj->obj)->color);
	}
	else if (obj->type == PLAN)
	{
		return (((t_plan *)obj->obj)->color);
	}
	else if (obj->type == CYLINDRE)
	{
		return (((t_cylindre *)obj->obj)->color);
	}
	else if (obj->type == CONE)
	{
		return (((t_cone *)obj->obj)->color);
	}
	else
		return (no_color());
}
