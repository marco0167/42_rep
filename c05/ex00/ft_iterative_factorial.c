//#include <stdio.h>

int	ft_iterative_factorial(int nbr)
{
	//Deve ritornare undefined se va in overflow
	int c;

	c = nbr;
	if (nbr < 1)
		return (0);
	while (c > 2)
	{
		c--;
		nbr *= c;
	}
	return (nbr);
}
/*
int	main()
{
	printf("%d\n", ft_iterative_factorial(0));
}
*/