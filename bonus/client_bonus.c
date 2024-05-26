/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 00:15:00 by relamine          #+#    #+#             */
/*   Updated: 2024/05/26 06:58:31 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_bonus.h"

int main(int argc, char **argv)
{
	int pid_server;
	int i;
	int res;

	if (argc != 3)
		return (1);
	pid_server = ft_atoi(argv[1]);
	if (pid_server < 0)
		return (write(1, argv[1], ft_strlen(argv[1])), 1);
	while (*argv[2])
	{
		i = 7;
		while (i >= 0)
		{
			res = *argv[2] >> i & 1;
			if (res == 1)
				kill(pid_server, SIGUSR1);
			else
				kill(pid_server, SIGUSR2);
			i--;
			usleep(400);
		}
		i = 1;
		while (i <= 8)
		{
			kill(pid_server, SIGUSR2);
			usleep(400);
			i++;
		}
		argv[2]++;
	}
}


