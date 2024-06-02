#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*p;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(sizeof (char) * (len + 1));
	if (p == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (s1[i])
		{
			p[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
			p[i++] = s2[j++];
		p[i] = '\0';
	}
	return (p);
}
