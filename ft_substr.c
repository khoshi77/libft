#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*p;

	i = start;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (start + len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	p = malloc(sizeof (char) * (len + 1));
	if (p == NULL)
		return (NULL);
	else
	{
		j = 0;
		while (j < len)
		{
			p[j++] = s[i++];
		}
		p[j] = '\0';
	}
	return (p);
}
