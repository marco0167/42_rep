#include <stdio.h>
#include <stdlib.h>

int len(long nb)
{
	int len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
char *ft_itoa(int nb)
{
	char *str;
	long n;
	int i;

	n = nb;
	i = len(n);
	if (!(str = (char *)malloc(i + 1)))
		return (0);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n /= 10;
		i--;
	}
	return (str);
}

void condition_one(char *nbr, long *var, char *lng_nbr)
{
	if (nbr[var[0] - 2] == '1')
	{
		if (var[3] != 1)
		{
			lng_nbr = ft_itoa(var[3]);
			var[2] = var[2] + 1;
		}
		lng_nbr[0] = nbr[var[0] - 2];
		lng_nbr[1] = nbr[var[0] - 1];
		var[2] = var[2] + 1;
		var[0] = var[0] - 1;
		var[1] = var[1] + 1;
		var[3] *= 10;
	}
	else if (nbr[var[0] - 1] != '0')
	{
		if (var[3] != 1)
		{
			lng_nbr = ft_itoa(var[3]);
			var[2] = var[2] + 1;
		}
		lng_nbr[0] = nbr[var[0] - 1];
		var[2] = var[2] + 1;
	}
}

void condition_two(char *nbr, long *var, char *lng_nbr)
{

}

char **divider(char *nbr)
{
	char **lng_nbr = malloc(74 * sizeof(char *));
	long	var[4];

	var[0] = 0;
	var[1] = 1;
	var[2] = 0;
	var[3] = 1;
	while (var[0] < 74)
	{
		lng_nbr[var[0]] = malloc(40 * sizeof(char));
		var[0] = var[0] + 1;
	}
	var[0] = 0;
	while (nbr[var[0]] != '\0')
	{
		var[0] = var[0] + 1;
	}
	while (nbr[var[0] - 1])
	{
		if (var[1] == 1)
		{
			condition_one(nbr, var, lng_nbr[var[2]]);
		}
		else if (var[1] == 2 && nbr[var[0] - 1] != '1' && nbr[var[0] - 1] != '0')
		{
			lng_nbr[var[2]][0] = nbr[var[0] - 1];
			lng_nbr[var[2]][1] = '0';
			var[2] = var[2] + 1;
		}
		else if (var[1] == 3)
		{
			if (nbr[var[0] - 1] != '0')

			{
				if (nbr[var[0] - 1] == '1')
				{
					lng_nbr[var[2]] = "100";
					var[2] = var[2] + 1;
				}
				else
				{
					lng_nbr[var[2]] = "100";
					var[2] = var[2] + 1;
					lng_nbr[var[2]][0] = nbr[var[0] - 1];
					var[2] = var[2] + 1;
				}
			}
			var[1] = 0;
		}
		var[1] = var[1] + 1;
		var[0] = var[0] - 1;
		var[3] *= 10;
	}

	var[0] = 0;
	while (lng_nbr[var[0]] != 0 && (lng_nbr[var[0]][0] >= '0' && lng_nbr[var[0]][0] <= '9'))
	{
		printf("%s\n", lng_nbr[var[0]]);
		var[0] = var[0] + 1;
	}
	return (lng_nbr);
}

int	main()
{

	char	**arr = divider("2147483647");
	int	c = 0;

	while (arr[c] != 0 && (arr[c][0] >= '0' && arr[c][0] <= '9'))
	{
		printf("%s\n", arr[c]);
		c++;
	}
}
