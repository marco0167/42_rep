#include <unistd.h>

void    ft_swap(int *a, int *b)
{
    int* appoggio;
    
    appoggio = a;
    a = b;
    b = appoggio;
}

int main(void)
{
    int val_a;
    int val_b;
    int* ptr_a;
    int* ptr_b;

    val_a = 5;
    val_b = 6;
    ptr_a = &val_a;
    ptr_b = &val_b;
    ft_swap(ptr_a, ptr_b);
}