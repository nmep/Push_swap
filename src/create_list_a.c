/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:11:35 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/14 19:47:50 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*create_list_a(int *tab, int *size)
{
	t_list	*lst;
	t_list	**tmp;
	t_list	*prev;
	int		len;

	lst = NULL;
	tmp = &lst;
	prev = NULL;
	len = *size;
	while (len > 0)
	{
		*tmp = malloc(sizeof(t_list));
		(*tmp)->val = *tab;
		(*tmp)->prev = prev;
		if ((*tmp)->prev == NULL)
			((*tmp)->index = 0);
		else
			(*tmp)->index = (*tmp)->prev->index + 1;
		prev = *tmp;
		tmp = &(*tmp)->next;
		tab++;
		len--;
	}
	*tmp = NULL;
	return (lst);
}

void	dealloc_list(t_list **lst)
{
	t_list	*prev;
	t_list	*tmp;

	tmp = (*lst);
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		free (prev);
	}
}
