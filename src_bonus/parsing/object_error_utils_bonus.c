/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_error_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/09/19 14:09:49 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

int	nb_of_split(char **splits)
{
	int	split_count;

	split_count = 0;
	while (splits[split_count])
		split_count++;
	return (split_count);
}

int	is_all_digit_dot(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
	{
		i++;
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	while (str[i] && str[i + 1])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (FALSE);
		i++;
	}
	if (str[i] && str[i] != '\n' && !ft_isdigit(str[i]))
		return (FALSE);
	return (TRUE);
}
