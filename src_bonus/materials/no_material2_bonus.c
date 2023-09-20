/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_material2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/09/19 14:09:24 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

void	load_no_material2(void)
{
	t_minirt	*minirt;

	minirt = get_minirt();
	minirt->material[NO_MAT2].id = NO_MAT2;
	minirt->material[NO_MAT2].texture = NULL;
	minirt->material[NO_MAT2].norm_map = NULL;
	minirt->material[NO_MAT2].reflexion = 0;
	minirt->material[NO_MAT2].shine = 10000;
	minirt->material[NO_MAT2].specular_factor = 0.3;
}
