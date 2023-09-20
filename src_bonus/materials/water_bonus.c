/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   water_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/09/19 14:09:29 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

void	load_wood(void)
{
	t_minirt	*minirt;

	minirt = get_minirt();
	minirt->material[WOOD].id = WOOD;
	minirt->material[WOOD].texture = \
	mlx_load_png("textures_png/water/wod_tex.png");
	minirt->material[WOOD].norm_map = NULL;
	minirt->material[WOOD].shine = 10000;
	minirt->material[WOOD].reflexion = 0;
	minirt->material[WOOD].specular_factor = 2;
}
