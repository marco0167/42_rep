#define MAX 41

typedef struct {
	char	key[38];
	char	value[15];
}numbers;

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	add_key_value(char *psd_key, char  *psd_value, char *strc)
{
	strc.key = psd_key;
	strc.value = psd_value;
}

char	*get_value(char *psd_key, char *strc)
{
	int	c;
	
	c = 0;
	while (c < MAX)
	{
		if (ft_strcmp(strc[c].key, psd_key) == 0)
			return (strc[c].value);
	}
	return ("NOT FOUND");
}

int main()
{
    numbers number[MAX];
	int	c;

	c = 0;
	while (c < MAX)
	{
		add_key_value(key, value, nummber[c]);
		c++;
	}

}
