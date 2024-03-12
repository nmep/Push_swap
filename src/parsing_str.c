/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:34:17 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/14 19:48:40 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	str_to_int_str2(char **arg, int *size_tab, int	**tab, char ***tab_char)
{
	*tab_char = split(*(arg + 1), size_tab);
	if (!tab_char && !check_other_char(*tab_char))
	{
		ft_free(*tab_char);
		return (FALSE);
	}
	*tab = malloc(sizeof(int) * (*size_tab + 1));
	if (!tab)
	{
		ft_free(*tab_char);
		return (FALSE);
	}
	return (1);
}

int	*str_to_int_str(char **arg, int *size_tab)
{
	int		*tab;
	char	**tab_char;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(str_to_int_str2(arg, size_tab, &tab, &tab_char)))
		return (NULL);
	while (tab_char[j])
	{
		if (!(check_sign(tab_char[j]) && check_s_nbr(tab_char[j]))
			|| (!is_int(ft_atoi(tab_char[j]))))
		{
			*size_tab = 0;
			ft_free(tab_char);
			free(tab);
			return (FALSE);
		}
		tab[i++] = (int) ft_atoi(tab_char[j++]);
	}
	if (!str_to_int_str3(tab_char, tab, size_tab))
		return (NULL);
	ft_free(tab_char);
	return (tab);
}

int	str_to_int_str3(char **tab_char, int *tab, int *size_tab)
{
	if (!check_double(tab, size_tab))
	{
		ft_free(tab_char);
		free(tab);
		return (0);
	}
	return (1);
}
