#include "push_swap.h"

int is_number(const char *str)
{
    int i;

    i = 0;
    while (str[i] && ft_isspace(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!ft_isdigit(str[i]))
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int is_int(const char *str, int *out)
{
    long n;

    if (!is_number(str))
        return (0);
    n = ft_atol(str);
    if (n > INT_MAX || n < INT_MIN)
        return (0);
    *out = (int)n;
    return (1);
}

int is_duplicate(int *arr, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] == arr[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}