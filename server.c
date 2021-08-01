/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 00:15:27 by jhleena           #+#    #+#             */
/*   Updated: 2021/08/01 11:43:46 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	make_word(int sig)
{
	static int		count = 0;
	static uint8_t	symb = 0b00000000;

	if (sig == SIGUSR1)
	{
		symb = symb + (0b00000001 << count);
		++count;
	}
	else if (sig == SIGUSR2)
		++count;
	if (count == 8)
	{
		write(1, &symb, 1);
		if (symb == '\0')
			write(1, "Message is delivered\n", 21);
		count = 0;
		symb = 0b00000000;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigemptyset(&(action.sa_mask));
	action.sa_flags = SA_SIGINFO;
	action.__sigaction_u.__sa_handler = make_word;
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
	}
	return (0);
}
