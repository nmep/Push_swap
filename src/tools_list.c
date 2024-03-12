/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:35:39 by garfi             #+#    #+#             */
/*   Updated: 2023/12/14 19:57:33 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*str_tab_to_list(char **av, int *len, int ac)
{
	int		*tab;
	t_list	*lst;

	tab = NULL;
	if (ac == 1)
	{
		tab = str_to_int_str(av, len);
		if (!tab)
			return (NULL);
	}
	else if (ac >= 2)
	{
		tab = str_to_int_av(av, len);
		if (!tab)
			return (NULL);
	}
	lst = create_list_a(tab, len);
	free(tab);
	return (lst);
}

t_list	*find_highest(t_list **a)
{
	t_list	*tmp;
	t_list	*node;
	int		higher;

	if (!(*a))
		return (NULL);
	tmp = *a;
	higher = tmp->val;
	node = tmp;
	while (tmp)
	{
		if (higher < tmp->val)
		{
			node = tmp;
			higher = tmp->val;
		}
		tmp = tmp->next;
	}
	return (node);
}

int	stack_sorted(t_list **lst, int *len, char **av, int ac)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		nb;

	*lst = str_tab_to_list(av, len, ac);
	tmp = (*lst);
	tmp2 = tmp;
	while (tmp)
	{
		nb = tmp->val;
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (nb > tmp2->val)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

void	init_index_list(t_list **a)
{
	t_list	*tmp;
	int		index;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	index = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->index = index;
		tmp = tmp->next;
		index++;
	}
}

int	lst_size(t_list **lst)
{
	t_list	*tmp;
	int		count;

	if (!(*lst))
		return (0);
	tmp = (*lst);
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
