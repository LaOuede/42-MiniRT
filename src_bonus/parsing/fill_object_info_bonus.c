/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_object_info_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/09/19 14:09:39 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

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
