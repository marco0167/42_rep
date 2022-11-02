//#include <stdio.h>

int ft_recursive_power(int nb, int power)
{
    if (nb < 0)
        return (0);
    if (power == 0)
        return (1);
    if (power > 1)
        return (nb * ft_recursive_power(nb, (power - 1)));
    return (nb);
}
/*
int main(void)
{
    printf("%d\n", ft_recursive_power(3, 5));
    printf("%d\n", ft_recursive_power(12, 1));
    printf("%d\n", ft_recursive_power(3, 0));
    return (0);
}
*/