#include "push_swap.h"

void sort_two(t_node **stack_a)
{
    if (!stack_a || !(*stack_a) || !(*stack_a)->next)
        return ;
    if((*stack_a)->value > (*stack_a)->next->value)
        sa(stack_a);
}

void sort_three(t_node **stack_a)
{
    int first = (*stack_a)->value;
    int second = (*stack_a)->next->value;
    int third = (*stack_a)->next->next->value;

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
        sa(stack_a), ra(stack_a);
    else if (first < second && second > third && first > third)
        rra(stack_a);
}

int find_min(t_node *stack)
{
    int min;

    min = stack->value;
    while (stack)
    {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return (min);
}

int find_position(t_node *stack, int value)
{
    int i;

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

void push_min_to_b(t_node **stack_a, t_node **stack_b)
{
    int min;
    int pos;
    int size;
    int i;

    min = find_min(*stack_a);
    pos = find_position(*stack_a, min);
    size = list_size(*stack_a);
    
    i = 0;
    while ((*stack_a)->value != min)
    {
        if (pos <= size / 2)
            ra(stack_a);
        else
            rra(stack_a);
        i++;
    }
    pb(stack_a, stack_b);
}

void sort_four(t_node **stack_a, t_node **stack_b)
{
    push_min_to_b(stack_a, stack_b);
    sort_three(stack_a);
    pa(stack_b, stack_a);
}

void sort_five(t_node **stack_a, t_node **stack_b)
{
    push_min_to_b(stack_a, stack_b);
    push_min_to_b(stack_a, stack_b);
    sort_three(stack_a);
    pa(stack_b, stack_a);
    pa(stack_b, stack_a);
}
