/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 00:15:00 by relamine          #+#    #+#             */
/*   Updated: 2024/06/24 15:24:07 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_bonus.h"

static int	parsing_client(int argc, char **argv, int *pid_server)
{
	if (argc != 3)
		return (write(1, "error in arguments",
				ft_strlen("error in arguments")));
	*pid_server = ft_atoi(argv[1]);
	if (*pid_server < 0)
		return (write(1, argv[1], ft_strlen(argv[1])));
	return (0);
}

static	void	handle_sig(int sig)
{
	if (sig == SIGUSR2)
		write(1, "message has been received", 25);
}

int	main(int argc, char **argv)
{
	int	pid_server;
	int	i;
	int	len;
	int	j;

	pid_server = 0;
	if (parsing_client(argc, argv, &pid_server))
		return (1);
	len = ft_strlen((const char *)argv[2]);
	j = 0;
	signal(SIGUSR2, handle_sig);
	while (j <= len)
	{
		i = 8;
		while (--i >= 0)
		{
			if ((argv[2][j] >> i & 1) == 1)
				protect_kill(pid_server, SIGUSR1);
			else
				protect_kill(pid_server, SIGUSR2);
			usleep(400);
		}
		j++;
	}
}
