/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/09/19 14:06:27 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	get_texture_color(t_hit *hit)
{
	t_material		*mat;
	t_color			color;
	unsigned int	px;
	unsigned int	py;
	unsigned int	p_xy;

	mat = get_obj_material(hit->obj);
	if (!mat->texture)
		return (get_obj_color(hit->obj));
	uv_map(hit, &px, &py, mat->texture);
	p_xy = 4 * (py * mat->texture->width + px);
	color.r = mat->texture->pixels[p_xy];
	color.g = mat->texture->pixels[p_xy + 1];
	color.b = mat->texture->pixels[p_xy + 2];
	return (color);
}
