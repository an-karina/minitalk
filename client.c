#include "minitalk.h"
#include <stdlib.h>
int	send_sym(int pid, char sym)
{
	uint8_t mask;

	mask = 0b000001;
	printf("%c\n", sym);
	while (mask)
	{
		if (mask & sym)
		{

			if (kill(pid, SIGUSR1) != 0)//if this bit is 1
				return (write(2, "error with kill()\n", 18), -1);
		}
		else
		{
			if (kill(pid, SIGUSR2) != 0)//if this bit is 0
				return (write(2, "error with kill()\n", 18), -1);
		}
		mask = mask << 1;
		usleep(600);
	}
	return (0);
}

void	send_msg(int pid, char **str)
{
	while (*str)
	{
		while (**str)
		{
			send_sym(pid, **str);
			++(*str);
		}
		exit(1);
		++str;
	}
}

int	main(int argc, char **argv)
{
	int pid;

	if (argc != 3)
	{
		write(2, "Arguments are wrong\n", 20);
		return (-1);
	}
	pid = ft_atoi(*(argv + 1));
	send_msg(pid, argv + 2);
	write(1, "Message is sent\n", 16);
}
