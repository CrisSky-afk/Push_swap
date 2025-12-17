/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_and_create_arr.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris_sky <cris_sky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:56:22 by csuomins          #+#    #+#             */
/*   Updated: 2025/12/15 15:58:14 by cris_sky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

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

static int count_args(char **args, int start)
{
	int count;

	count = 0;
	while (args[start + count])
		count++;
	return (count);
}

static void	parse_error(int *arr, char **args, int is_split)
{
	write(2, "Error\n", 6);
	free(arr);
	if (is_split)
		free_split(args);
	exit(1);
}

int	*parse_args_to_array(char **args, int start,
				int is_split, int *size)
{
	int	i;
	int	j;
	int	temp;
	int	*arr;

	*size = count_args(args, start);
	arr = malloc(sizeof(int) * (*size));
	if (!arr)
		parse_error(NULL, args, is_split);
	i = start;
	j = 0;
	while (args[i])
	{
		if (!is_int(args[i], &temp))
			parse_error(arr, args, is_split);
		arr[j++] = temp;
		i++;
	}
	return (arr);
}
