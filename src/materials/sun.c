/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/16 14:31:30 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	load_sun(void)
{
	t_minirt	*minirt;

	minirt = get_minirt();
	minirt->material[SUN].id = SUN;
	minirt->material[SUN].texture = \
	mlx_load_png("./textures_png/sun/8k_sun.png");
	minirt->material[SUN].norm_map = NULL;
	minirt->material[SUN].shine = 1000;
	minirt->material[SUN].reflexion = 0.0000001;
	minirt->material[SUN].specular_factor = 0;
}
