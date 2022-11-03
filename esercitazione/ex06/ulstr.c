#include <unistd.h>

int main(int argc, char **argv)
{
    int c;
    if (argc == 2)
    {
        c = 0;
        while (argv[1][c])
        { 
            if (argv[1][c] >= 'a' && argv[1][c] <= 'z')
                argv[1][c] -= 32;
            else if (argv[1][c] >= 'A' && argv[1][c] <= 'Z')
                argv[1][c] += 32;
            write(1, &argv[1][c], 1);
            c++;
        }
    }
    write(1, "\n", 1);
    return (0);
}