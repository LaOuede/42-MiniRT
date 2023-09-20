/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_material.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/09/19 14:05:03 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	load_no_material(void)
{
	t_minirt	*minirt;

	minirt = get_minirt();
	minirt->material[NO_MAT].id = NO_MAT;
	minirt->material[NO_MAT].texture = NULL;
	minirt->material[NO_MAT].norm_map = NULL;
	minirt->material[NO_MAT].reflexion = 4;
	minirt->material[NO_MAT].shine = 10000;
	minirt->material[NO_MAT].specular_factor = 10;
}
