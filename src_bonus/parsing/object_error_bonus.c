/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/09/19 14:09:42 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

void	check_sphere_args(char **line, void *to_free)
{
	if (invalid_coords(line[1]) || invalid_value(line[2])
		|| invalid_coords_limited(line[3], 0.0f, 255.0f))
	{
		error(line, BAD_ARGS_SPHERE, to_free);
	}
}

void	check_cylinder_args(char **line, void *to_free)
{
	if (invalid_coords(line[1]) || invalid_coords_limited(line[2], -1.0f, 1.0f)
		|| invalid_value(line[3]) || invalid_value(line[4])
		|| invalid_coords_limited(line[5], 0.0f, 255.0f))
	{
		error(line, BAD_ARGS_CYLINDER, to_free);
	}
}

void	check_plane_args(char **line, void *to_free)
{
	if (invalid_coords(line[1]) || invalid_coords_limited(line[2], -1.0f, 1.0f)
		|| invalid_coords_limited(line[3], 0.0f, 255.0f))
	{
		error(line, BAD_ARGS_PLANE, to_free);
	}
}

void	check_cone_args(char **line, void *to_free)
{
	if (invalid_coords(line[1]) || invalid_coords_limited(line[2], -1.0f, 1.0f)
		|| invalid_value_limited(line[3], 0.0f, 180.0f)
		|| invalid_value(line[4])
		|| invalid_coords_limited(line[5], 0.0f, 255.0f))
	{
		error(line, BAD_ARGS_CONE, to_free);
	}
}
