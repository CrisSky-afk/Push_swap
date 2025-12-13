#include "push_swap.h"

t_node *new_node(int x)
{
    t_node *n;

    n = malloc(sizeof(t_node));
    if (!n)
        return (NULL);
    n->value = x;
    n->next = NULL;
    return (n);
}

void insert_front (t_node **head, t_node *n)
{
    if (!n)
        return ;
    n->next = *head;
    *head = n;
}

void insert_back(t_node **head, t_node *n)
{
    t_node *temp;

    if (!n)
        return ;
    if (!*head)
    {
        *head = n;
        return;
    }
    temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = n;
}

t_node *remove_front(t_node **head)
{
    t_node *first;

    if (!head || !*head)
        return (NULL);
    first = *head;
    *head = (*head)->next;
    first->next = NULL;
    return (first);
}

t_node *remove_back(t_node **head)
{
    t_node *last;
    t_node *temp;

    if (!head || !*head)
        return (NULL);
    if ((*head)->next == NULL)
    {
        last = *head;
        *head = NULL;
        return (last);
    }
    last = *head;
    while (last->next != NULL)
    {
        temp = last;
        last = last->next;
    }
    temp->next = NULL;
    return (last);
}

void print_list(t_node *head)
{
    while (head)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

t_node *last_node(t_node *head)
{
    if (!head)
        return (NULL);
    while (head->next)
        head = head->next;
    return (head);
}

int list_size(t_node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return (count);
}

void free_list(t_node **head)
{
    t_node *temp;

    while (*head)
    {
        temp = (*head)->next;
        free(*head);
        *head = temp;
    }
}
