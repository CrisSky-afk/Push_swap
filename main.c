/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csuomins <csuomins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:32:54 by csuomins          #+#    #+#             */
/*   Updated: 2025/12/14 15:26:22 by csuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**handle_args(int argc, char **argv, int *start_i, int *is_split)
{
	char	**args;

	*is_split = 0;
	*start_i = 1;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
		{
			if (args)
				free_split(args);
			write(2, "Error\n", 6);
			exit(1);
		}
		*is_split = 1;
		*start_i = 0;
		return (args);
	}
	return (argv);
}

void	parse_and_fill_stack(char **args, int start,
		t_node **stack_a, int is_split)
{
	int	i;
	int	temp;

	i = start;
	while (args[i])
	{
		if (!is_int(args[i], &temp))
		{
			write(2, "Error\n", 6);
			free_list(stack_a);
			if (is_split)
				free_split(args);
			exit(1);
		}
		insert_back(stack_a, new_node(temp));
		i++;
	}
}

void	check_duplicates(t_node **stack_a)
{
	int	*arr;
	int	arr_size;

	arr_size = 0;
	arr = list_for_arr(*stack_a, &arr_size);
	if (!arr)
	{
		free_list(stack_a);
		exit(1);
	}
	if (is_duplicate(arr, arr_size))
	{
		write(2, "Error\n", 6);
		free(arr);
		free_list(stack_a);
		exit(1);
	}
	free(arr);
}

void	sort_stack(t_node **stack_a, t_node **stack_b, int size)
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

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**args;
	int		start_i;
	int		is_split;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit(0);
	args = handle_args(argc, argv, &start_i, &is_split);
	parse_and_fill_stack(args, start_i, &stack_a, is_split);
	check_duplicates(&stack_a);
	if (is_sorted(stack_a))
	{
		if (is_split)
			free_split(args);
		free_list(&stack_a);
		return (0);
	}
	sort_stack(&stack_a, &stack_b, list_size(stack_a));
	if (is_split)
		free_split(args);
	free_list(&stack_a);
	return (0);
}
