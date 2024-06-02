#include <stdlib.h>

static int	check_same(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && check_same(s[i], c))
			i++;
		if (s[i])
			count++;
		while (s[i] && !check_same(s[i], c))
			i++;
	}
	return (count);
}

static char	*ft_put_split(char const *s, char c)
{
	int		i;
	int		len;
	char	*a;

	len = 0;
	while (s[len] && !check_same(s[len], c))
		len++;
	i = 0;
	a = malloc(sizeof(char) * (len + 1));
	if (a == NULL)
		return (NULL);
	while (i < len)
	{
		a[i] = s[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

static void	ft_free(char **string, int i)
{
	i -= 1;
	while (i >= 0)
	{
		free(string[i]);
		i--;
	}
	free(string);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**string;

	i = 0;
	if (s == NULL)
		return (NULL);
	string = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (string == NULL)
		return (NULL);
	while (*s)
	{
		while (*s && check_same(*s, c))
			s++;
		if (*s)
		{
			string[i] = ft_put_split(s, c);
			if (string[i] == NULL)
				ft_free(string, i);
			i++;
		}
		while (*s && !check_same(*s, c))
			s++;
	}
	string[i] = NULL;
	return (string);
}
