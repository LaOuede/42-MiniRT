/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_translation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/09/19 15:08:22 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* 
Updates the position vector pos by adding or subtracting
a specified move vector based on the direction indicated
by the character c.
 */
void	new_pos(t_vec3 *pos, t_vec3 move, char c)
{
	if (c == '-')
	{
		pos->x -= move.x;
		pos->y -= move.y;
		pos->z -= move.z;
	}
	else if (c == '+')
	{
		pos->x = pos->x + move.x + (0.012432f * move.x);
		pos->y = pos->y + move.y + (0.012432f * move.y);
		pos->z = pos->z + move.z + (0.012432f * move.z);
	}
}

/* 
Initializes a move vector based on the given axis and camera matrix.
Calculates move which represents a displacement in the specified
axis relative to the camera's orientation.
 */
t_vec3	move_init(t_minirt *minirt, char axis)
{
	t_vec3	move;

	if (axis == 'x')
	{
		move.x = minirt->cam_matrix.p[0][0] * 0.5f;
		move.y = minirt->cam_matrix.p[0][1] * 0.5f;
		move.z = minirt->cam_matrix.p[0][2] * 0.5f;
	}
	if (axis == 'y')
	{
		move.x = minirt->cam_matrix.p[1][0] * 0.5f;
		move.y = minirt->cam_matrix.p[1][1] * 0.5f;
		move.z = minirt->cam_matrix.p[1][2] * 0.5f;
	}
	if (axis == 'z')
	{
		move.x = minirt->cam_matrix.p[2][0] * 0.5f;
		move.y = minirt->cam_matrix.p[2][1] * 0.5f;
		move.z = minirt->cam_matrix.p[2][2] * 0.5f;
	}
	return (move);
}

void	object_translation(t_minirt *minirt, keys_t key, char axis)
{
	char	c;
	t_vec3	pos;
	t_vec3	move;

	move = move_init(minirt, axis);
	pos = get_position(minirt->obj_selected);
	if (key == MLX_KEY_S || key == MLX_KEY_Q || key == MLX_KEY_A)
	{
		c = '-';
		new_pos(&pos, move, c);
	}
	else if (key == MLX_KEY_W || key == MLX_KEY_E || key == MLX_KEY_D)
	{
		c = '+';
		new_pos(&pos, move, c);
	}
	change_position(minirt->obj_selected, pos);
}
