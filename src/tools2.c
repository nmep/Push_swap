/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:22:44 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/14 19:49:29 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] && s2[i]) && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

int	check_double(int *tab, int *size_tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*size_tab - 1))
	{
		j = i + 1;
		while (j <= (*size_tab - 1))
		{
			if (tab[i] == tab[j])
			{
				write (1, "doublons\n", 9);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_other_char2(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-' || str[i] == '+'))
		i++;
	if (str[i] == '\0')
		return (1);
	write (1, "il n'y a pas que des chiffres\n", 30);
	return (0);
}

int	check_other_char(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!check_other_char2(arg[i]))
			return (0);
		i++;
	}
	return (1);
}
