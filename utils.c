/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris_sky <cris_sky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:54:02 by csuomins          #+#    #+#             */
/*   Updated: 2025/12/15 13:55:54 by cris_sky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	value;
	int		i;
	int		sign;

	value = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		value = value * 10 + (str[i++] - '0');
	return (value * sign);
}

int	*list_for_arr(t_node *head, int *arr_size)
{
	int	i;
	int	*arr;

	i = 0;
	if (!head)
	{
		*arr_size = 0;
		return (NULL);
	}
	*arr_size = list_size(head);
	arr = malloc(sizeof(int) * (*arr_size));
	if (!arr)
		return (NULL);
	while (head)
	{
		arr[i] = head->value;
		i++;
		head = head->next;
	}
	return (arr);
}

static int	find_min(t_node *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

void	push_min_to_b(t_node **stack_a, t_node **stack_b)
{
	int	min;
	int	pos;
	int	size;

	min = find_min(*stack_a);
	pos = find_position(*stack_a, min);
	size = list_size(*stack_a);
	while ((*stack_a)->value != min)
	{
		if (pos <= size / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}
