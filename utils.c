/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csuomins <csuomins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:54:02 by csuomins          #+#    #+#             */
/*   Updated: 2025/12/14 15:01:49 by csuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	value;
	int		i;
	int		sign;

	value = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
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
