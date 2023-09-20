/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_translation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/09/19 14:04:15 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	update_light_pos(t_vec3 new_pos, t_light *light)
{
	light->position.x = new_pos.x;
	light->position.y = new_pos.y;
	light->position.z = new_pos.z;
}

void	light_translation(t_minirt *minirt, keys_t key, char axis)
{
	char	c;
	t_vec3	pos;
	t_vec3	move;
	t_light	*light;

	light = (t_light *)minirt->lights->content;
	move = move_init(minirt, axis);
	pos = get_light_position(light);
	if (key == MLX_KEY_W || key == MLX_KEY_Q || key == MLX_KEY_A)
	{
		c = '-';
		new_pos(&pos, move, c);
	}
	else if (key == MLX_KEY_S || key == MLX_KEY_E || key == MLX_KEY_D)
	{
		c = '+';
		new_pos(&pos, move, c);
	}
	update_light_pos(pos, light);
}
