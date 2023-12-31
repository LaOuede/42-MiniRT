/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object_info3_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/09/19 14:11:07 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

float	*get_height(t_object *object)
{
	t_cone		*cone;
	t_cylindre	*cylinder;

	if (object->type == CYLINDRE)
	{
		cylinder = (t_cylindre *)object->obj;
		return (&cylinder->hauteur);
	}
	if (object->type == CONE)
	{
		cone = (t_cone *)object->obj;
		return (&cone->hauteur);
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

float	*get_angle(t_object *object)
{
	t_cone	*cone;

	if (object->type == CONE)
	{
		cone = (t_cone *)object->obj;
		return (&cone->angle);
	}
	return (NULL);
}
