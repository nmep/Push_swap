/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:40:03 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/16 13:55:47 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	do_instructions(char *str, t_list **a, t_list **b)
{
	if ((!ft_strncmp(str, "ss\n", 3)))
		ss_b(a, b);
	else if ((!ft_strncmp(str, "sa\n", 3)))
		sa_b(a);
	else if ((!ft_strncmp(str, "sb\n", 3)))
		sb_b(b);
	else if ((!ft_strncmp(str, "rr\n", 3)))
		rr_b(a, b);
	else if ((!ft_strncmp(str, "ra\n", 3)))
		ra_b(a);
	else if ((!ft_strncmp(str, "rb\n", 3)))
		rb_b(b);
	else if ((!ft_strncmp(str, "pa\n", 3)))
		pa_b(a, b);
	else if ((!ft_strncmp(str, "pb\n", 3)))
		pb_b(a, b);
	else if ((!ft_strncmp(str, "rrr\n", 3)))
		rrr_b(a, b);
	else if ((!ft_strncmp(str, "rra\n", 3)))
		rra_b(a);
	else if ((!ft_strncmp(str, "rrb\n", 3)))
		rrb_b(b);
	else
		return (-1);
	return (0);
}

int	get_error(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 4)
	{
		write(1, str, len);
		return (-1);
	}
	return (0);
}

int	stack_sorted_b(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		nb;

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

void	final_output(t_list **a)
{
	if (!stack_sorted_b(a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	*output;

	a = NULL;
	b = NULL;
	a = init_list(av[1], a, ac - 1, (av + 1));
	output = get_next_line(0);
	if (get_error(output) == -1)
		return (-1);
	while (output)
	{
		if ((do_instructions(output, &a, &b)) == -1 || get_error(output) == -1)
		{
			dealloc_list(&a);
			dealloc_list(&b);
			return (-1);
		}
		free(output);
		output = get_next_line(0);
	}
	final_output(&a);
	dealloc_list(&a);
}
