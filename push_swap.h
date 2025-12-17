/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris_sky <cris_sky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:50:55 by csuomins          #+#    #+#             */
/*   Updated: 2025/12/15 15:56:15 by cris_sky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "./Libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

long	ft_atol(const char *str);
int		*list_for_arr(t_node *head, int *arr_size);
void	free_split(char **split);

int		is_int(const char *str, int *out);
int		is_duplicate(int *arr, int size);

t_node	*new_node(int x);
void	insert_front(t_node **head, t_node *n);
void	insert_back(t_node **head, t_node *n);
t_node	*remove_front(t_node **head);
t_node	*remove_back(t_node **head);
int		list_size(t_node *head);
void	free_list(t_node **head);
int		is_sorted(t_node *stack_a);

void	swap(t_node **head);
void	push(t_node **src, t_node **dest);
void	rotate(t_node **head);
void	reverse_rotate(t_node **head);

void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_b, t_node **stack_a);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

void	sort_two(t_node **stack_a);
void	sort_three(t_node **stack_a);
void	sort_four(t_node **stack_a, t_node **stack_b);
void	sort_five(t_node **stack_a, t_node **stack_b);
void	push_min_to_b(t_node **stack_a, t_node **stack_b);
void	radix_sort(t_node **stack_a, t_node **stack_b);
void	index_stack(t_node **stack);

char **handle_args(int argc, char **argv, int *start_i, int *is_split);
int *parse_args_to_array(char **args, int start, int is_split, int *size);
int	find_position(t_node *stack, int value);
#endif