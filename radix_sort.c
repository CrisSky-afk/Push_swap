#include "push_swap.h"

int get_max_bits(int size)
{
    int max_bits;

    max_bits = 0;
    while ((size - 1) >> max_bits != 0)
        max_bits++;
    return (max_bits);
}

void sort_by_bit(t_node **stack_a, t_node **stack_b, int bit, int size)
{
    int j;

    j = 0;
    while (j < size)
    {
        if ((((*stack_a)->value >> bit) & 1) == 0)
            pb(stack_a, stack_b);
        else
            ra(stack_a);
        j++;
    }
    while (*stack_b)
        pa(stack_b, stack_a);
}

void radix_sort(t_node **stack_a, t_node **stack_b)
{
    int size;
    int max_bits;
    int i;

    size = list_size(*stack_a);
    max_bits = get_max_bits(size);
    i = 0;
    while (i < max_bits)
    {
        sort_by_bit(stack_a, stack_b, i, size);
        i++;
    }
}
