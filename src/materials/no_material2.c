/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_material2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:23:13 by macote            #+#    #+#             */
/*   Updated: 2023/09/08 11:23:14 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	load_no_material2(void)
{
	t_minirt	*minirt;

	minirt = get_minirt();
	minirt->material[NO_MAT2].id = NO_MAT2;
	minirt->material[NO_MAT2].texture = NULL;
	minirt->material[NO_MAT2].norm_map = NULL;
	minirt->material[NO_MAT2].reflexion = 4;
	minirt->material[NO_MAT2].shine = 10000;
	minirt->material[NO_MAT2].specular_factor = 0.3;
}
