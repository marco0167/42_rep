#include <unistd.h>

int main(void)
{
    int c;

    c = 1;
    while (c <= 100)
    {
        if (c % 3 == 0 && c % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if (c % 3 == 0)
            write(1, "fizz", 4);
        else if (c % 5 == 0)
            write(1, "buzz", 4);
        else if (c < 10)
            write(1, &"0123456789"[c], 1);
        else if (c == 100)
            write(1, "100", 3);
        else
        {
            write(1, &"0123456789"[c / 10], 1);
            write(1, &"0123456789"[c % 10], 1);
        }
        write(1, "\n", 1);
        c++;
    }
}