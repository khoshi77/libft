#include "libft.h"

static int	ft_same(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count_s(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_same(s1[i], set))
			break ;
		i++;
	}
	return (i);
}

static int	ft_count_f(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1);
	while (i > 0)
	{
		i--;
		if (!ft_same(s1[i], set))
			break ;
	}
	return (i);
}

static char	*ft_put_t(char *p, int len_s, int len_f, char const *s1)
{
	int		i;
	int		j;

	i = len_s;
	j = 0;
	while (i <= len_f)
	{
		p[j] = s1[i];
		j++;
		i++;
	}
	p[j] = '\0';
	return (p);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len_s;
	int		len_f;
	int		len;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	len_s = ft_count_s(s1, set);
	len_f = ft_count_f(s1, set);
	if (len_f - len_s > 0)
		len = len_f - len_s + 1;
	else
		len = 0;
	p = malloc(sizeof (char) * (len + 1));
	if (p == NULL)
		return (NULL);
	else
		p = ft_put_t(p, len_s, len_f, s1);
	return (p);
}
