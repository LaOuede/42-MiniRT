/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error_helper_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/09/19 14:31:07 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

//helper in parsing_error_handling.c/bad_arg_count()
int	expected_arg_count(int type)
{
	if (type == SPHERE || type == PLAN || type == LIGHT || type == CAMERA)
		return (4);
	else if (type == CYLINDRE || type == CONE)
		return (6);
	else if (type == AMBIANT_LIGHT)
		return (3);
	else if (type == CONE)
		return (5);
	return (0);
}

//helper to check_bad_arg()
int	get_count_error(int type)
{
	if (type == SPHERE)
		return (BAD_ARG_COUNT_SPHERE);
	else if (type == PLAN)
		return (BAD_ARG_COUNT_PLANE);
	else if (type == CYLINDRE)
		return (BAD_ARG_COUNT_CYLINDER);
	else if (type == CONE)
		return (BAD_ARG_COUNT_CONE);
	else if (type == LIGHT)
		return (BAD_ARG_COUNT_LIGHT);
	else if (type == AMBIANT_LIGHT)
		return (BAD_ARG_COUNT_AMB_LIGHT);
	else if (type == CAMERA)
		return (BAD_ARG_COUNT_CAMERA);
	else
		return (-1);
}

//checks if the nb of args is right for the type of object
void	check_bad_arg_count(char **line, int type, void *to_free)
{
	int	nb_args;

	nb_args = 0;
	while (line[nb_args])
		nb_args++;
	if (type == SPHERE || type == PLAN)
	{
		if (nb_args != expected_arg_count(type) && nb_args
			- 1 != expected_arg_count(type))
			error(line, get_count_error(type), to_free);
	}
	else
		if (nb_args != expected_arg_count(type))
			error(line, get_count_error(type), to_free);
}
