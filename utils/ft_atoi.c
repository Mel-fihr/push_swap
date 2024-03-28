#include "../push_swap.h"

void check_input(const char *s)
{
    int i = 0;

    while (s[i] == ' ')
        i++;
}

void min_max(long long n)
{
	if (n > 2147483647 || n < -2147483648)
        error();
}

int	ft_atoi(const char *s)
{
    int			i;
    int			sg;
    long long	n;

    i = 0;
    n = 0;
    sg = 1;
	check_input(s);
    if (s[i] == '+' && s[i + 1] >= '0' && s[i + 1] <= '9')
        i++;
    else if (s[i] == '-' && s[i + 1] >= '0' && s[i + 1] <= '9')
    {
        sg = -1;
        i++;
    }
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9' || s[i] == '\t' || s[i] == '\n')
            error();
        n = n * 10 + (s[i] - '0');
        i++;
    }
    n = n * sg;
    min_max(n);
    return (n);
}	
