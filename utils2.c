/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csuomins <csuomins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:56:22 by csuomins          #+#    #+#             */
/*   Updated: 2025/12/14 16:04:07 by csuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_node *stack)
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

int	find_position(t_node *stack, int value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == value)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
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
