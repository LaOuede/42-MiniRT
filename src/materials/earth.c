/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   earth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:23:04 by macote            #+#    #+#             */
/*   Updated: 2023/09/08 11:23:05 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	load_earth(void)
{
	t_minirt	*minirt;

	minirt = get_minirt();
	minirt->material[EARTH].id = EARTH;
	minirt->material[EARTH].texture = \
	mlx_load_png("textures_png/earth/new_earth_texture.png");
	minirt->material[EARTH].norm_map = \
	mlx_load_png("textures_png/earth/earth_normap.png");
	minirt->material[EARTH].shine = 0;
	minirt->material[EARTH].reflexion = 0;
	minirt->material[EARTH].specular_factor = 0;
}
