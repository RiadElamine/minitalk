/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:23:11 by relamine          #+#    #+#             */
/*   Updated: 2024/06/24 15:14:14 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_BONUS_H
# define HEAD_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_putnbr(int n);
void	protect_kill(int pid_server, int signal);

#endif