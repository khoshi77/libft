#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	ans;
	long	check;

	i = 0;
	sign = 1;
	ans = 0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' '))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i++] == '-')
			sign = -1;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		check = ans;
		ans = ans * 10 + sign * (nptr[i++] - '0');
		if (ans > check && sign < 0)
			return ((int)LONG_MIN);
		if (ans < check && sign > 0)
			return ((int)LONG_MAX);
	}
	return (ans);
}
