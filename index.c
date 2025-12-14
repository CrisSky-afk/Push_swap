#include "push_swap.h"

int *create_sort_array(int *arr, int size)
{
    int *sorted;
    int i;
    int j;
    int tmp;

    sorted = malloc(sizeof(int) * size);
    if (!sorted)
        return (NULL);
    i = -1;
    while (++i < size)
        sorted[i] = arr[i];
    i = -1;
    while (++i < size - 1)
    {
        j = -1;
        while (++j < size - i - 1)
        {
            if (sorted[j] > sorted[j + 1])
            {
                tmp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = tmp;
            }
        }
    }
    return (sorted);
}

void replace_with_index(t_node *stack, int *sorted, int size)
{
    int i;

    while (stack)
    {
        i = 0;
        while (i < size)
        {
            if (stack->value == sorted[i])
            {
                stack->value = i;
                break;
            }
            i++;
        }
        stack = stack->next;
    }
}

void index_stack(t_node **stack)
{
    int size;
    int *arr;
    int *sorted;

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
