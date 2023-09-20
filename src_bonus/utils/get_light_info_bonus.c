/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light_info_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/09/19 14:10:51 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

t_vec3	get_light_position(void *packed_light)
{
	t_light	*light;

	light = (t_light *)packed_light;
	return (light->position);
}

float	get_light_intensity(void *packed_light)
{
	t_light	*light;

	light = (t_light *)packed_light;
	return (light->intensity);
}

t_color	get_light_color(void *packed_light)
{
	t_light	*light;

	light = (t_light *)packed_light;
	return (light->color);
}
