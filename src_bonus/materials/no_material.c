/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_material.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:23:10 by macote            #+#    #+#             */
/*   Updated: 2023/09/08 11:23:11 by macote           ###   ########.fr       */
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
