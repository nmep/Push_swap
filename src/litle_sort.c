/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   litle_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:44:04 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/16 14:30:12 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	litle_sort(t_list **a)
{
	t_list	*highest;

	highest = find_highest(a);
	if ((*a) == highest)
		ra(a);
	else if ((*a)->next == highest)
		rra(a);
	if ((*a)->val > (*a)->next->val)
		sa(a);
}

void	sort_5(t_list **a, t_list **b)
{
	t_list	*small;

	while (lst_size(a) > 3)
	{
		small = smallest(a);
		while (small->index != 0)
		{
			if (small->index <= 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
	}
	litle_sort(a);
	if (lst_size(b) == 2)
	{
		pa(a, b);
		pa(a, b);
	}
	else
		pa(a, b);
}
