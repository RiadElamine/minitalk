/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:26:53 by relamine          #+#    #+#             */
/*   Updated: 2024/06/26 01:05:39 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_atoi(const char *str)
{
	int			res;

	res = 0;
	if ((*str >= 9 && *str <= 13) || *str == 32)
		return (-1);
	if (*str == '-' || *str == '+')
		return (-1);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (-1);
		if ((res > (2147483647 / 10)) || (res == (2147483647
					/ 10) && *str > '7'))
			return (-1);
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putnbr(int n)
{
	char	a;

	a = '\0';
	if (n > 9)
	{
		ft_putnbr((n / 10));
		ft_putnbr((n % 10));
	}
	else
	{
		a = (n + 48);
		write(1, &a, 1);
	}
}

void	protect_kill(int pid_server, int signal)
{
	if (kill(pid_server, signal))
		exit(1);
}
