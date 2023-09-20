/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_object_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/09/19 14:05:25 by gle-roux         ###   ########.fr       */
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
