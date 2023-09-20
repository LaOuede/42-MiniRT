/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/09/19 14:06:24 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	get_normap_value(t_hit *hit)
{
	t_material		*mat;
	t_color			color;
	unsigned int	px;
	unsigned int	py;
	unsigned int	p_xy;

	mat = get_obj_material(hit->obj);
	uv_map(hit, &px, &py, mat->norm_map);
	p_xy = 4 * (py * mat->norm_map->width + px);
	color.r = mat->norm_map->pixels[p_xy];
	color.g = mat->norm_map->pixels[p_xy + 1];
	color.b = mat->norm_map->pixels[p_xy + 2];
	return (color);
}
