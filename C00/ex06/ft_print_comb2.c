#include <unistd.h>

void ft_print_comb2(void)
{
  int i;
  int j;
  int k;
  int x;

  i = '0';
  j = '0';
  k = '0';
  x = '0';
  while (i <= '6')
  {
    while (j <= '7')
    {
      while (k <= '8')
      {
        while (x <= '9')
        {
          write(1, &i, 1);
          write(1, &j, 1);
          write(1, " ", 1);
          write(1, &k, 1);
          write(1, &x, 1);
          write(1, ",", 1);
          x++;
        }
        x = '0';
        k++;
      }
      k = '0';
      j++;
    }
    j = '0';
    i++;
  }
}

int main(void)
{
  ft_print_comb2();
}