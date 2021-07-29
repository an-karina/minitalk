/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 09:56:29 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/29 17:02:14 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(char *str);

#endif