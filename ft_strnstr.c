#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str)
		return (NULL);
	if (to_find[0] == '\0' || to_find == NULL)
		return ((char *)str);
	while (str[i] && i < n)
	{
		j = 0;
		while (to_find[j] && to_find[j] == str[j + i] && i + j < n)
			j++;
		if (to_find[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
