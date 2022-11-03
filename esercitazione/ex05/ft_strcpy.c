#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int c;

    c = 0;
    while (s2[c])
    {
        s1[c] = s2[c];
        c++;
    }
    s1[c] = '\0';
    return (s1);
}

int main(void)
{
    char    s1[4];
    char    s2[] = "ciao";
    printf("%s\n", ft_strcpy(s1, s2));
}