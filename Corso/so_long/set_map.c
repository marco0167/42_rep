#include "main.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*char_src;
	char	*char_dest;

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

int	ft_strlen2(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	if (s[i - 1] == '\n'){
		i--;
		s[i] = 0;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	len_s1;
	char	*s2;

	len_s1 = ft_strlen2((char *)s1);
	s2 = (char *)malloc(sizeof(char) * (len_s1));
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, (len_s1 + 1));
	return (s2);
}

char	*checker(t_game *game)
{
	int	line_len;
	int	i;
	int j;

	i = 0;
	line_len = ft_strlen(game->map.map[i]);
	while(game->map.map[i])
	{
		if (line_len != ft_strlen(game->map.map[i]))
			return ("map not rectangle");
		j = 0;
		while(*game->map.map[i])
		{
			if(game->map.map[0] || game->map.map[game->map.height - 1])
			{
				if(game->map.map[i][j] != 1)
					return ("mappa non circondata di muri");//qua ce errore
			}
			else
				if(game->map.map[i][0] != 1 || game->map.map[i][line_len - 1])
					return ("mappa non circondata di muri");
		}
		i++;
	}
	return (0);
}

void	set_map_matrix(t_game *game)
{
	int		i;
	int		fd;
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
	while(i < game->map.height)
	{
		game->map.map[i] = ft_strdup(get_next_line(fd));
		i++;
	}
	game->map.map[i] = 0;

	i = 0;
	while(game->map.map[i] != 0)
	{
		printf("string = %s\n", game->map.map[i]);
		i++;
	}
	printf("CHECKER %s", checker(game));

}
