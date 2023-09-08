/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_info_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:23:53 by macote            #+#    #+#             */
/*   Updated: 2023/09/08 11:23:54 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_amb_light_args(char **line, void *to_free)
{
	if (invalid_value_limited(line[1], 0.0f, 1.0f)
		|| invalid_coords_limited(line[2], 0.0f, 255.0f))
	{
		error(line, BAD_ARGS_AMB_LIGHT, to_free);
	}
}

void	check_light_args(char **line, void *to_free)
{
	if (invalid_coords(line[1]) || invalid_value_limited(line[2], 0.0f, 1.0f)
		|| invalid_coords_limited(line[3], 0.0f, 255.0f))
	{
		error(line, BAD_ARGS_LIGHT, to_free);
	}
}

void	check_camera_args(char **line, void *to_free)
{
	if (invalid_coords(line[1]) || invalid_coords_limited(line[2], -1.0f, 1.0f)
		|| invalid_value_limited(line[3], 0.0f, 180.0f))
	{
		error(line, BAD_ARGS_CAMERA, to_free);
	}
}
