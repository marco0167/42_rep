#include <stdio.h>

char  dec_to_hex(char smbl)
{
  int dec;

  dec = smbl;
  printf("%d", dec);
}

void  ft_putstr_non_printable(char *str)
{
  printf("%s", dec_to_hex(str[0]));
}

int main(void)
{
  char  *str = "\n";

  ft_putstr_non_printable(str);
}