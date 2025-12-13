#include "push_swap.h"

int main (int argc, char *argv[])
{
    int i;
    int temp;
    int size;
    t_node *stack_a;
    t_node *stack_b;
    int *arr;
    int arr_size;

    i = 1;
    temp = 0;
    size = 0;
    stack_a = NULL;
    stack_b = NULL;
    arr_size = 0;
    if (argc == 1)
        exit(0);
    while (i < argc)
    {
        if (!is_int(argv[i], &temp))
        {
            write (2, "Error\n", 6);
            exit (1);
        }
        else
            insert_back(&stack_a, new_node(temp));
        i++;
    }
    arr = list_for_arr(stack_a, &arr_size);
    if (!arr)
    {
        free_list(&stack_a);
        exit(1);
    }
    if (is_duplicate(arr, arr_size))
    {
        write (2, "Error\n", 6);
        free(arr);
        free_list(&stack_a);
        exit (1);
    }
    free(arr);
    if (arr_size == 2)
        sort_two(&stack_a);
    else if (arr_size == 3)
        sort_three(&stack_a);
    print_list(stack_a);
    free_list(&stack_a);
    return (0);
}

// int main (void)
// {
//     int tamanho = 0;
//     t_node *lista = new_node(3);
//     insert_back(&lista, new_node(5));
//     insert_back(&lista, new_node(1));
//     insert_back(&lista, new_node(8));
//     int *meu_array = list_for_arr(lista, &tamanho);
//     print_list(lista);
//     int i = 0;
//     while (i < tamanho)
//     {
//         printf("%d ", meu_array[i]);
//         i++;
//     }
//     free(meu_array);
//     free_list(&lista);
// }