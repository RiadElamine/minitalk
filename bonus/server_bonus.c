/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 00:14:58 by relamine          #+#    #+#             */
/*   Updated: 2024/06/24 15:23:35 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_bonus.h"

static void	ft_print(unsigned char *b)
{
	int	i;

	i = 0;
	while (b[i])
	{
		write(1, &b[i], 1);
		b[i] = '\0';
		i++;
	}
}

static int	ft_print_bytes(unsigned char *b, pid_t	si_pid)
{
	if (b[0] == 0)
		return (protect_kill(si_pid, SIGUSR2), 1);
	if (b[0] <= 127)
		return (ft_print(b), 1);
	if ((b[0] >= 194 && b[0] <= 223) && b[1] != '\0')
		return (ft_print(b), 1);
	if ((b[0] >= 224 && b[0] <= 239) && b[1] != '\0' && b[2] != '\0')
		return (ft_print(b), 1);
	if (b[0] >= 240 && b[1] != '\0' && b[2] != '\0' && b[3] != '\0')
		return (ft_print(b), 1);
	return (0);
}

static void	ft_rest(unsigned char *bytes, int *index,
	int *count, unsigned char	*byte)
{
	*index = 0;
	while (*index < 4)
		bytes[(*index)++] = '\0';
	*count = 0;
	*byte = 0;
	*index = 0;
}

static void	signal_handler(int signal, siginfo_t *info, void *others)
{
	static unsigned char	byte;
	static int				count;
	static pid_t			si_pid;
	static unsigned char	bytes[4];
	static int				index;

	(void)others;
	if (si_pid != info->si_pid)
	{
		ft_rest(bytes, &index, &count, &byte);
		si_pid = info->si_pid;
	}
	if (signal == SIGUSR1)
		byte = 128 >> count | byte;
	count++;
	if (count == 8)
	{
		bytes[index] = byte;
		index++;
		if (ft_print_bytes(bytes, si_pid))
			index = 0;
		count = 0;
		byte = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;
	pid_t				pid;

	pid = getpid();
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = signal_handler;
	(void)argv;
	if (argc != 1)
		exit(1);
	write(1, "The process ID is ", 18);
	ft_putnbr(pid);
	write(1, "\n", 1);
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		exit(1);
	while (1)
		pause();
}
