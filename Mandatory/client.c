/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 00:15:00 by relamine          #+#    #+#             */
/*   Updated: 2024/06/26 00:58:24 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	main(int argc, char **argv)
{
	int	pid_server;
	int	i;
	int	res;

	if (argc != 3)
		return (write(1, "error in arguments", 18));
	pid_server = ft_atoi(argv[1]);
	if (pid_server < 0)
		return (write(1, "illegal pid: ", 13),
			write(1, argv[1], ft_strlen(argv[1])), 1);
	while (*argv[2])
	{
		i = 8;
		while (--i >= 0)
		{
			res = *argv[2] >> i & 1;
			if (res == 1)
				protect_kill(pid_server, SIGUSR1);
			else
				protect_kill(pid_server, SIGUSR2);
			usleep(400);
		}
		argv[2]++;
	}
}
