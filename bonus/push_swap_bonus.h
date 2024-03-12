/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:03:22 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/15 20:40:39 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3

# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../include/push_swap.h"

char	*get_next_line(int fd);
char	*get_line_after_n(int fd, char *line_static);
char	*get_line_res(char **line_static);
int		ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *line_static, char *buffer);
char	*ft_strdup(char *s, int len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// instructions

void	pa_b(t_list **stack_a, t_list **stack_b);
void	pb_b(t_list **stack_a, t_list **stack_b);
void	ra_b(t_list **stack_a);
void	rb_b(t_list **stack_b);
void	rr_b(t_list **stack_a, t_list **stack_b);
void	rra_b(t_list **stack_a);
void	rrb_b(t_list **stack_a);
void	rrr_b(t_list **stack_a, t_list **stack_b);
void	sa_b(t_list **stack_a);
void	sb_b(t_list **stack_b);
void	ss_b(t_list **stack_a, t_list **stack_b);

// f

int		get_error(char *str);
int		stack_sorted_b(t_list **lst);
int		do_instructions(char *str, t_list **a, t_list **b);
void	init_list_from_av(char **av, t_list **a);
void	init_list_from_str(char *str, t_list **a);
t_list	*init_list(char *str, t_list *a, int ac, char **av);

void	init_index_list_b(t_list **a);
void	ft_free_b(char **tab);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
