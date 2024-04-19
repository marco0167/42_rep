#include <iostream>

int	main(int argc, char **argv)
{
	int	i = -1;
	int	c = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (argv[++c])
		{
			i = -1;
			while (argv[c][++i])
				argv[c][i] = (char)toupper(argv[c][i]);
			std::cout << argv[c];
		}
	}
	std::cout << "\n";
	return 0;
}
