/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_transformations_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/09/19 14:08:18 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

t_color	max_color(t_color color)
{
	float	big_color;
	float	div_factor;

	big_color = MAX(MAX(color.r, color.g), color.b);
	if (big_color > 255.0f)
	{
		div_factor = big_color / 255.0f;
		color.r = color.r / div_factor;
		color.g = color.g / div_factor;
		color.b = color.b / div_factor;
	}
	if (color.r > 255.0f)
		color.r = 255.0f;
	if (color.g > 255.0f)
		color.g = 255.0f;
	if (color.b > 255.0f)
		color.b = 255.0f;
	return (color);
}
