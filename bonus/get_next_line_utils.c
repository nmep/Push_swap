/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:33:14 by garfi             #+#    #+#             */
/*   Updated: 2023/12/15 18:38:15 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while ((char) *s != (char) c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *) s);
}

char	*ft_strjoin(char *line_static, char *buffer)
{
	char	*dest;
	int		i;
	int		j;

	if ((!line_static && !buffer))
		return (NULL);
	dest = malloc(((ft_strlen(line_static) + ft_strlen(buffer)) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (line_static && line_static[i])
	{
		dest[i] = line_static[i];
		i++;
	}
	j = -1;
	while (buffer && buffer[++j])
	{
		dest[i] = buffer[j];
		i++;
	}
	dest[i] = '\0';
	free(line_static);
	return (dest);
}

char	*ft_strdup(char *s, int len)
{
	char	*str;
	int		i;

	if (s == NULL || !*s)
		return (NULL);
	if (!len)
		return (free(s), NULL);
	str = malloc(sizeof(char) * (len + 2));
	if (!str)
		return (NULL);
	i = 0;
	while ((i < len) && (s[i]))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int	main()
// {
// 	char a[9] = "bonjo\nur";

// 	ft_cut_str(a);
// 	printf("%s\n", a);
// }