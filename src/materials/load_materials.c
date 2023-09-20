/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_materials.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/09/19 14:04:55 by gle-roux         ###   ########.fr       */
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
