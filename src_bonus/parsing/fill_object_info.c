/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_object_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:23:28 by macote            #+#    #+#             */
/*   Updated: 2023/09/08 11:23:29 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_sphere_info(t_object *object, char **line)
{
	object->type = SPHERE;
	object->obj = ft_calloc(1, sizeof(t_sphere));
	parse_sphere(line, object);
}

void	fill_plane_info(t_object *object, char **line)
{
	object->type = PLAN;
	object->obj = ft_calloc(1, sizeof(t_plan));
	parse_plane(line, object);
}

void	fill_cylinder_info(t_object *object, char **line)
{
	object->type = CYLINDRE;
	object->obj = ft_calloc(1, sizeof(t_cylindre));
	parse_cylinder(line, object);
}

void	fill_cone_info(t_object *object, char **line)
{
	object->type = CONE;
	object->obj = ft_calloc(1, sizeof(t_cone));
	parse_cone(line, object);
}
