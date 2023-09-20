/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_image_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/09/19 14:11:18 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

/* Draw the points of the previous image with the background color */
void	map_erase(t_minirt *minirt)
{
	size_t	screen_size;

	screen_size = minirt->image->width * minirt->image->height * \
		sizeof(uint32_t);
	ft_bzero(minirt->image->pixels, screen_size);
}

void	resize_image(int32_t width, int32_t height, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	mlx_resize_image(minirt->image, width, height);
	ray_launcher();
}
