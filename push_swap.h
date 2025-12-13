# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../Libft/libft.h"

typedef struct s_node {
    int value;
    struct s_node *next;
}   t_node;

int ft_isspace(char c);
long ft_atol(const char *str);
int is_int(const char *str, int *out);
int is_number(const char *str);
int is_duplicate(int *arr, int size);
t_node *new_node(int x);
void insert_front (t_node **head, t_node *n);
void insert_back(t_node **head, t_node *n);
t_node *remove_front(t_node **head);
t_node *remove_back(t_node **head);
int list_size(t_node *head);
int *list_for_arr(t_node *head, int *arr_size);
void print_list(t_node *head);
void free_list(t_node **head);
void swap(t_node **head);
void push(t_node **src, t_node **dest);
void rotate(t_node **head);
void reverse_rotate(t_node **head);
void sa(t_node **stack_a);
void sb(t_node **stack_b);
void ss(t_node **stack_a, t_node **stack_b);
void pa(t_node **stack_b, t_node **stack_a);
void pb(t_node **stack_a, t_node **stack_b);
void ra(t_node **stack_a);
void rb(t_node **stack_b);
void rr(t_node **stack_a, t_node **stack_b);
void rra(t_node **stack_a);
void rrb(t_node **stack_b);
void rrr(t_node **stack_a, t_node **stack_b);
void sort_two(t_node **stack_a);
void sort_three(t_node **stack_a);

#endif