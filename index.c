/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csuomins <csuomins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:25:33 by csuomins          #+#    #+#             */
/*   Updated: 2025/12/14 14:27:14 by csuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int	*create_sort_array(int *arr, int size)
{
	int	*sorted;
	int	i;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	i = -1;
	while (++i < size)
		sorted[i] = arr[i];
	sort_array(sorted, size);
	return (sorted);
}

void	replace_with_index(t_node *stack, int *sorted, int size)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (i < size)
		{
			if (stack->value == sorted[i])
			{
				stack->value = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}

void	index_stack(t_node **stack)
{
	int	size;
	int	*arr;
	int	*sorted;

	size = list_size(*stack);
	arr = list_for_arr(*stack, &size);
	if (!arr)
		return ;
	sorted = create_sort_array(arr, size);
	if (!sorted)
	{
		free(arr);
		return ;
	}
	replace_with_index(*stack, sorted, size);
	free(arr);
	free(sorted);
}
