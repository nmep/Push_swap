/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:03:27 by garfi             #+#    #+#             */
/*   Updated: 2023/12/14 19:49:15 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_word(char *str)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*str)
	{
		if (*str != ' ' && flag == 0)
		{
			count++;
			flag = 1;
		}
		else if (*str == ' ')
			flag = 0;
		str++;
	}
	return (count);
}

char	*dup_word(char *str, int start, int end)
{
	char	*s;
	int		i;

	s = malloc(sizeof(char) * ((end - start) + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (start < end)
	{
		s[i] = str[start];
		i++;
		start++;
	}
	s[i] = '\0';
	return (s);
}

// split est utilise apres que l'entre est check
char	**split(char *str, int *size_tab)
{
	char	**tab;
	int		start_word;
	int		i;

	if (!str)
		return (NULL);
	tab = (char **) malloc(sizeof(char *) * (count_word(str) + 1));
	if (!tab)
		return (NULL);
	i = -1;
	start_word = -1;
	while (++i <= ft_strlen(str))
	{
		if (str[i] != ' ' && start_word < 0)
			start_word = i;
		else if ((str[i] == ' ' || i == ft_strlen(str)) && (start_word >= 0))
		{
			tab[(*size_tab)++] = dup_word(str, start_word, i);
			start_word = -1;
		}
	}
	tab[*size_tab] = NULL;
	return (tab);
}
/*
int	main(int ac, char **av)
{
 	char **tab;
	int	i = 0;
	int	size_tab = 0;
	tab = NULL;
 	tab = split(av[1], &size_tab);
	printf("SPLIT \n\n----------\nsize_tab = %d\n", size_tab);
	while (tab[i])
	{
		printf("tab[%d] = %s\n", i, tab[i]);
		i++;
	}
	free(tab);
}
*/
