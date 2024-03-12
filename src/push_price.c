/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_price.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:52:02 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/14 19:48:45 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_push_price(t_list *a, t_list *b)
{
	t_list	*tmp_a;
	int		median_a;
	int		median_b;
	int		len_a;
	int		len_b;

	tmp_a = a;
	median_a = lst_size(&a) / 2;
	median_b = lst_size(&b) / 2;
	len_a = lst_size(&a);
	len_b = lst_size(&b);
	while (tmp_a)
	{
		if (tmp_a->index >= median_a && tmp_a->target->index >= median_b)
			tmp_a->push_price = (len_a - tmp_a->index)
				+ (len_b - tmp_a->target->index);
		else if (tmp_a->index <= median_a && tmp_a->target->index >= median_b)
			tmp_a->push_price = tmp_a->index + (len_b - tmp_a->target->index);
		else if (tmp_a->index >= median_a && tmp_a->target->index <= median_b)
			tmp_a->push_price = (len_a - tmp_a->index) + tmp_a->target->index;
		else
			tmp_a->push_price = tmp_a->index + tmp_a->target->index;
		tmp_a = tmp_a->next;
	}
}
