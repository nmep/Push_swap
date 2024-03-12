/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:42:10 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/15 20:36:52 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_target_node(t_list **a, t_list **b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	t_list	*big;
	t_list	*small;

	if (!(*b))
		return ;
	tmp_a = (*a);
	while (tmp_a)
	{
		tmp_b = (*b);
		while (tmp_b)
		{
			big = bigger(b);
			small = smallest(b);
			if (tmp_a->val > big->val)
				tmp_a->target = big;
			else if (tmp_a->val < small->val)
				tmp_a->target = big;
			else if (tmp_a->val < big->val && tmp_a->val > small->val)
				tmp_a->target = bigger_smallest(b, tmp_a);
			tmp_b = tmp_b->next;
		}
		tmp_a = tmp_a->next;
	}
}

void	init_target_node_b(t_list **a, t_list **b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	t_list	*big;
	t_list	*small;

	tmp_b = (*b);
	while (tmp_b)
	{
		tmp_a = (*a);
		while (tmp_a)
		{
			big = bigger(a);
			small = smallest(a);
			if (tmp_b->val > big->val)
				tmp_b->target = small;
			else if (tmp_b->val < small->val)
				tmp_b->target = small;
			else if (tmp_b->val < big->val && tmp_b->val > small->val)
				tmp_b->target = smallest_bigger(a, tmp_b);
			tmp_a = tmp_a->next;
		}
		tmp_b = tmp_b->next;
	}
}

void	init_target_and_price(t_list **a, t_list **b)
{
	init_target_node(a, b);
	init_push_price(*a, *b);
}

void	init_target_and_price_b(t_list **a, t_list **b)
{
	init_target_node_b(a, b);
	init_push_price(*b, *a);
}

t_list	*find_cheapest(t_list **a)
{
	t_list	*tmp;
	t_list	*cheaper;

	tmp = (*a);
	cheaper = NULL;
	while (tmp)
	{
		if (cheaper == NULL || tmp->push_price <= cheaper->push_price)
			cheaper = tmp;
		tmp = tmp->next;
	}
	return (cheaper);
}
