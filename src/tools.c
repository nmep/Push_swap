/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:12:11 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/15 20:36:08 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strlen(char *str)
{
	char	*p;

	if (!str)
		return (0);
	p = str;
	while (*str)
		str++;
	return (str - p);
}

long long int	ft_atoi(char *str)
{
	int					s;
	int					i;
	long long int		res;

	s = 1;
	res = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * s);
}

int	check_sign(char *str)
{
	int	flag;

	flag = 0;
	while (*str)
	{
		if (*str == '-' || *str == '+')
			flag++;
		str++;
	}
	if (flag > 1)
	{
		write (1, "trop de signe sur le meme int\n", 30);
		return (FALSE);
	}
	return (TRUE);
}

int	check_s_nbr(char *str)
{
	int	flag;

	flag = 0;
	while (*str)
	{
		if ((*str >= '0' && *str <= '9')
			&& (*(str + 1) == '-' || *(str + 1) == '+'))
		{
			write (1, "signe mal place\n", 16);
			return (FALSE);
		}
		str++;
	}
	return (TRUE);
}

int	is_int(long long int nb)
{
	if (nb >= INT_MIN && nb <= INT_MAX)
		return (1);
	write (1, "un nombre entre n'est pas un int\n", 33);
	return (0);
}
