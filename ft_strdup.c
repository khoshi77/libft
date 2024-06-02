#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*p;
	int		i;

	len = ft_strlen(s);
	p = malloc(sizeof (char) * (len + 1));
	if (p == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (i < len)
		{
			p[i] = s[i];
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}
