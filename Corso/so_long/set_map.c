#include "main.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	char *char_src;
	char *char_dest;

	if (!dest && !src)
		return ((void *)0);
	char_src = (char *)src;
	char_dest = (char *)dest;
	i = 0;
	while (i < n)
	{
		char_dest[i] = char_src[i];
		// printf("|char = %d-%c| ", char_dest[i], char_dest[i]);
		i++;
	}
	// printf("\n");
	return (dest);
}

int ft_strlen2(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	if (s[i - 1] == '\n')
	{
		i--;
		s[i] = 0;
	}
	return (i);
}

char *ft_strdup(const char *s1)
{
	size_t len_s1;
	char *s2;

	len_s1 = ft_strlen2((char *)s1);
	s2 = (char *)malloc(sizeof(char) * (len_s1));
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, (len_s1 + 1));
	return (s2);
}

char	*dimension_checker(t_game *game)
{
	int i;

	i = 0;
	while (game->map.map[i])
	{
		if (game->map.width != ft_strlen(game->map.map[i]))
			return ("map not rectangle");
		i++;
	}
	return (0);
}

char *wall_cheker(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		if (i == 0 || i == (game->map.height - 1))
		{
			while (game->map.map[i][j])
			{
				if (game->map.map[i][j] != '1')
				{
					return ("mappa non circondata di muri qui");
				}
				j++;
			}
		}
		else
			if (game->map.map[i][0] != '1' || game->map.map[i][game->map.width - 1] != '1')
				return ("mappa non circondata di muri");
		i++;
	}
	return (0);
}

char	*obj_checker_scd(t_game *game, int p, int e)
{
	if (p != 1)
		return ("Player error");
	if (e < 1)
		return ("Exit error");
	if (game->collectable.qnt < 1)
		return ("Collectable error");
	return (0);
}

char	*obj_checker(t_game *game)
{
	int	i;
	int	j;
	int	p;
	int	e;

	i = 1;
	p = 0;
	e = 0;
	game->collectable.qnt = 0;
	while (i < game->map.height - 1)
	{
		j = 1;
		while (j < game->map.width - 1)
		{
			if (game->map.map[i][j] == 'P')
				p++;
			else if (game->map.map[i][j] == 'E')
				e++;
			else if (game->map.map[i][j] == 'C')
				game->collectable.qnt++;
			j++;
		}
		i++;
	}
	return (obj_checker_scd(game, p, e));
}

void set_map_matrix(t_game *game)
{
	int i;
	int fd;
	char *line;

	game->map.height = 0;
	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		game->map.height++;
	}
	close(fd);
	i = 0;
	fd = open("map.ber", O_RDONLY);
	game->map.map = malloc(sizeof(char *) * game->map.height + 1);
	while (i < game->map.height)
	{
		game->map.map[i] = ft_strdup(get_next_line(fd));
		i++;
	}
	game->map.map[i] = 0;
	game->map.width = ft_strlen(game->map.map[0]);
	i = 0;
	while (game->map.map[i] != 0)
	{
		printf("string = %s\n", game->map.map[i]);
		i++;
	}
	printf("dimension %s\n", dimension_checker(game));
	printf("wall %s\n", wall_cheker(game));
	printf("obj %s\n", obj_checker(game));
}
