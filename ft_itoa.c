#include "libft.h"

static int	ketasuu(int n)
{
	int		keta;
	long	a;

	keta = 0;
	a = n;
	if (a < 0)
		a = -a;
	else if (a == 0)
		keta = 1;
	while (a >= 1)
	{
		a /= 10;
		keta++;
	}
	return (keta);
}

static void	ft_put(long n, char *a, int i)
{
	if (n >= 10)
		ft_put(n / 10, a, i - 1);
	a[i] = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	int		keta;
	long	num;
	char	*a;

	num = n;
	keta = ketasuu(num);
	if (n < 0)
	{
		a = malloc(sizeof(char) * (keta + 2));
		if (a == NULL)
			return (NULL);
		a[0] = '-';
		num = -num;
		ft_put(num, a, keta);
		a[keta + 1] = '\0';
	}
	else
	{
		a = malloc(sizeof(char) * (keta + 1));
		if (a == NULL)
			return (NULL);
		ft_put(num, a, keta - 1);
		a[keta] = '\0';
	}
	return (a);
}
