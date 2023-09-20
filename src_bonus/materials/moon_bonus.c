/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moon_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/09/19 14:09:19 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

void	load_moon(void)
{
	t_minirt	*minirt;

	minirt = get_minirt();
	minirt->material[MOON].id = MOON;
	minirt->material[MOON].texture = \
	mlx_load_png("textures_png/moon/moon_texture.png");
	minirt->material[MOON].norm_map = \
	mlx_load_png("textures_png/moon/moon_normap_5.png");
	minirt->material[MOON].shine = 0;
	minirt->material[MOON].reflexion = 0;
	minirt->material[MOON].specular_factor = 0;
}
