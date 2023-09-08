/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_materials.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:23:06 by macote            #+#    #+#             */
/*   Updated: 2023/09/08 11:23:07 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	load_materials(void)
{
	load_no_material();
	load_no_material2();
	load_moon();
	load_earth();
	load_wood();
	load_sun();
	load_damier();
}
