#include "push_swap.h"

void swap(t_node **head)
{
    t_node *first;
    t_node *second;
    if (!*head || !head || !(*head)->next)
        return ;
    first = *head;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *head = second;
}

void push(t_node **src, t_node **dest)
{
    t_node *temp;

    temp = remove_front(src);
    if (!temp)
        return ;
    insert_front(dest, temp);
}

void rotate(t_node **head)
{
    t_node *temp;

    temp = remove_front(head);
    if (!temp)
        return ;
    insert_back(head, temp);
}

void reverse_rotate(t_node **head)
{
    t_node *temp;

    temp = remove_back(head);
    if(!temp)
        return ;
    insert_front(head, temp);
}

void sa(t_node **stack_a)
{
    swap(stack_a);
    write(1, "sa\n", 3);
}

void sb(t_node **stack_b)
{
    swap(stack_b);
    write (1, "sb\n", 3);
}

void ss(t_node **stack_a, t_node **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    write (1, "ss\n", 3);
}

void pa(t_node **stack_b, t_node **stack_a)
{
    push(stack_b, stack_a);
    write (1, "pa\n", 3);
}

void pb(t_node **stack_a, t_node **stack_b)
{
    push(stack_a, stack_b);
    write (1, "pb\n", 3);
}

void ra(t_node **stack_a)
{
    rotate(stack_a);
    write (1, "ra\n", 3);
}

void rb(t_node **stack_b)
{
    rotate(stack_b);
    write (1, "rb\n", 3);
}

void rr(t_node **stack_a, t_node **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    write (1, "rr\n", 3);
}

void rra(t_node **stack_a)
{
    reverse_rotate(stack_a);
    write (1, "rra\n", 4);
}

void rrb(t_node **stack_b)
{
    reverse_rotate(stack_b);
    write (1, "rrb\n", 4);
}

void rrr(t_node **stack_a, t_node **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    write (1, "rrr\n", 4);
}