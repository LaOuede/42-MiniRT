/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   water.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:23:17 by macote            #+#    #+#             */
/*   Updated: 2023/09/08 11:23:18 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
