/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:31:03 by garfi             #+#    #+#             */
/*   Updated: 2023/12/14 19:48:59 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	finaly_order(t_list **a)
{
	t_list	*small;
	int		median_a;

	small = smallest(a);
	median_a = lst_size(a) / 2;
	if (small->index <= median_a)
	{
		while (small->prev != NULL)
			ra(a);
	}
	else if (small->index > median_a)
	{
		while (small->prev != NULL)
			rra(a);
	}
}

void	algo(t_list **a, t_list **b)
{
	pb(a, b);
	pb(a, b);
	pushing_to_b(a, b);
	sort_5(a, b);
	pushing_to_a(a, b);
}
