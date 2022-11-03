#include <unistd.h>

int main(int argc, char **argv)
{
    int c;

    c = 0;
    if (argc > 1)
        while (argv[argc - 1][c])
            write(1, &argv[argc - 1][c++], 1);
    write(1, "\n", 1);
    return (0);
}