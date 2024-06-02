#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*a;

	if (nmemb > 0 && SIZE_MAX / nmemb < size)
		return (NULL);
	a = malloc(nmemb * size);
	if (a == NULL)
		return (NULL);
	else
		ft_bzero(a, nmemb * size);
	return (a);
}
