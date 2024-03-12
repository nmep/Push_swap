/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:50:57 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/15 19:54:34 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*smallest(t_list **lst)
{
	t_list	*tmp;
	t_list	*res;

	tmp = (*lst);
	res = tmp;
	while (tmp)
	{
		if (tmp->val < res->val)
			res = tmp;
		tmp = tmp->next;
	}
	return (res);
}

t_list	*bigger(t_list **b)
{
	t_list	*tmp;
	t_list	*biggest;

	tmp = (*b);
	biggest = NULL;
	while (tmp)
	{
		if (biggest == NULL || tmp->val > biggest->val)
			biggest = tmp;
		tmp = tmp->next;
	}
	return (biggest);
}

t_list	*smallest_bigger(t_list **b, t_list *node)
{
	t_list	*tmp;
	t_list	*res;

	tmp = (*b);
	res = NULL;
	while (tmp)
	{
		if ((tmp->val > (*node).val) && (res == NULL || tmp->val < res->val))
			res = tmp;
		tmp = tmp->next;
	}
	return (res);
}

t_list	*bigger_smallest(t_list **b, t_list *node)
{
	t_list	*tmp;
	t_list	*res;

	tmp = (*b);
	res = NULL;
	while (tmp)
	{
		if ((tmp->val < (*node).val) && (res == NULL || tmp->val > res->val))
			res = tmp;
		tmp = tmp->next;
	}
	return (res);
}
