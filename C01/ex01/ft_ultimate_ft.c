#include <unistd.h>

void    ft_ft(int *********nbr)
{
    write(1, &nbr, 10);
}

int main(void)
{
  int   n;
  int*********  ptr;

  n = 4;
  ptr = &n;
  ft_ft(ptr);
}