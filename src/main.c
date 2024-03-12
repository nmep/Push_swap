/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:54:59 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/16 13:55:40 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_list		*a;
	t_list		*b;
	int			size_tab;

	a = NULL;
	b = NULL;
	size_tab = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]) || ac > 501)
	{
		write (1, "errors\n", 7);
		return (0);
	}
	if (!stack_sorted(&a, &size_tab, av, ac - 1))
	{
		if (size_tab == 2)
			sa(&a);
		else if (size_tab == 3)
			litle_sort(&a);
		else if (size_tab <= 5)
			sort_5(&a, &b);
		else
			algo(&a, &b);
	}
	dealloc_list(&a);
}
