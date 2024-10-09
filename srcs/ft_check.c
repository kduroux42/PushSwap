

#include "../includes/ft_push_swap.h"

int	is_valid(char *str)
{
	int i;
	int j;
	char **res;

	res = ft_split(str, ' ');
	i = 0;
	while (res[i])
	{
		j = 0;
		while (res[i][j])
		{
			if ((res[i][j] >= 'a' && res[i][j] <= 'z') || (res[i][j] >= 'A' && res[i][j] <= 'Z'))
			{
				free_split(res);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_split(res);
	return (1);
}

int	int_min_max(int nbi, long nbl)
{
	if (nbi != nbl)
		return (1);
	return (0);
}

int	is_doublon(char *str)
{
	int i;
	int j;
	char **res;

	i = 0;
	res = ft_split(str, ' ');
	while (res[i])
	{
		j = 1 + i;
		while (res[j])
		{
			if (ft_atoi(res[i]) == ft_atoi(res[j]) || int_min_max(ft_atoi(res[j]), ft_atol(res[j])))
			{
				free_split(res);
				return (1);
			}
			j++;
	}
		i++;
	}
	free_split(res);
	return (0);
}

