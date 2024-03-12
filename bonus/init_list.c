/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:25:30 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/15 20:40:52 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	init_list_from_str(char *str, t_list **a)
{
	char	**tab_char;
	int		*tab;
	int		len;
	int		i;

	len = 0;
	i = -1;
	tab_char = split(str, &len);
	tab = malloc(sizeof (int) * len);
	if (!tab)
		return ;
	while (tab_char[++i])
		tab[i] = (int)ft_atoi(tab_char[i]);
	ft_free (tab_char);
	*a = create_list_a(tab, &len);
	free(tab);
}

void	init_list_from_av(char **av, t_list **a)
{
	char	**tab_char;
	int		*tab;
	int		i;
	int		len;

	i = -1;
	tab_char = av;
	len = 0;
	while (tab_char[len])
		len++;
	tab = malloc(sizeof(int) * (len + 1));
	if (!tab)
		return ;
	while (tab_char[++i])
		tab[i] = (int) ft_atoi(tab_char[i]);
	*a = create_list_a(tab, (&(len)));
}

t_list	*init_list(char *str, t_list *a, int ac, char **av)
{
	if (ac == 1)
		init_list_from_str(str, &a);
	else if (ac >= 2)
		init_list_from_av(av, &a);
	return (a);
}
