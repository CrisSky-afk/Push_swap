/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csuomins <csuomins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:38:13 by csuomins          #+#    #+#             */
/*   Updated: 2025/12/14 15:52:49 by csuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **stack_a)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	sort_three(t_node **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	push_min_to_b(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_b, stack_a);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	push_min_to_b(stack_a, stack_b);
	push_min_to_b(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}
