#include <unistd.h>

char *ft_rev_print (char *str)
{
    int     c;

    c = 0;
    while (str[c])
        c++;
    while (c >= 0)
        write(1, &str[c--], 1);
    return (str);
}

int main(int argc, char **argv)
{
    (void)  argc;

    ft_rev_print(argv[1]);
}