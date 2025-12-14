/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csuomins <csuomins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:42:48 by csuomins          #+#    #+#             */
/*   Updated: 2025/12/14 14:59:01 by csuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (!*head || !head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	push(t_node **src, t_node **dest)
{
	t_node	*temp;

	temp = remove_front(src);
	if (!temp)
		return ;
	insert_front(dest, temp);
}

void	rotate(t_node **head)
{
	t_node	*temp;

	temp = remove_front(head);
	if (!temp)
		return ;
	insert_back(head, temp);
}

void	reverse_rotate(t_node **head)
{
	t_node	*temp;

	temp = remove_back(head);
	if (!temp)
		return ;
	insert_front(head, temp);
}

void	sa(t_node **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}
