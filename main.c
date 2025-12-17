/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris_sky <cris_sky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:32:54 by csuomins          #+#    #+#             */
/*   Updated: 2025/12/16 18:59:22 by cris_sky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void build_stack_from_array(int *arr, int size, t_node **stack_a)
{
	int i;

	i = 0;
	while (i < size)
	{
		insert_back(stack_a, new_node(arr[i]));
		i++;
	}
}

static void	sort_stack(t_node **stack_a, t_node **stack_b, int size)
{
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
	{
		index_stack(stack_a);
		radix_sort(stack_a, stack_b);
	}
}

static t_node *init_stack(int argc, char **argv, int *is_split)
{
	char	**args;
	int		start_i;
	int		*values;
	int		size;
	t_node	*stack_a;

	stack_a = NULL;
	args = handle_args(argc, argv, &start_i, is_split);
	values = parse_args_to_array(args, start_i, *is_split, &size);
	if (is_duplicate(values, size))
	{
		write(2, "Error\n", 6);
		free(values);
		if (*is_split)
			free_split(args);
		exit(1);
	}
	build_stack_from_array(values, size, &stack_a);
	free(values);
	if (*is_split)
		free_split(args);
	return (stack_a);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		is_split;

	if (argc == 1)
		return (0);
	stack_a = init_stack(argc, argv, &is_split);
	stack_b = NULL;

	if (is_sorted(stack_a))
	{
		free_list(&stack_a);
		return (0);
	}
	sort_stack(&stack_a, &stack_b, list_size(stack_a));
	free_list(&stack_a);
	return (0);
}
