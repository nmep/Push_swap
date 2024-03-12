/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:38:05 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/14 19:49:32 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_signe_only2(char *str)
{
	return ((str[0] == '-' || str[0] == '+') && (str[1] == '\0'));
}

int	check_signe_only(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!check_signe_only2(arg[i]))
		{
			write(1, "signe seul\n", 11);
			return (0);
		}
		i++;
	}
	return (1);
}

int	len_tab_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
