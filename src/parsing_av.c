/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_av.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:34:17 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/14 19:48:35 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write (1, &str[i++], 1);
}

void	print_tab_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_putstr(tab[i++]);
}

int	str_to_int_av2(char **arg, int *size_tab, int **tab, char ***tab_char)
{
	*tab_char = arg + 1;
	*size_tab = len_tab_tab(*tab_char);
	if (!check_other_char(*tab_char))
		return (FALSE);
	*tab = malloc(sizeof(int) * (*size_tab + 1));
	if (!tab)
		return (FALSE);
	return (1);
}

int	*str_to_int_av(char **arg, int *size_tab)
{
	char	**tab_char;
	int		*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(str_to_int_av2(arg, size_tab, &tab, &tab_char)))
		return (NULL);
	while (tab_char[j])
	{
		if (!(check_sign(tab_char[j]) && check_s_nbr(tab_char[j]))
			|| (!is_int(ft_atoi(tab_char[j]))))
		{
			*size_tab = 0;
			free(tab);
			return (FALSE);
		}
		tab[i++] = (int) ft_atoi(tab_char[j++]);
	}
	if (!str_to_int_av3(tab, size_tab))
		return (NULL);
	return (tab);
}

int	str_to_int_av3(int *tab, int *size_tab)
{
	if (!check_double(tab, size_tab))
	{
		free(tab);
		return (0);
	}
	return (1);
}
