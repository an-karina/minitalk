/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 00:28:22 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/29 17:02:30 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_atoi(char *str)
{
	int			i;
	long int	result;
	int			sign;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\r') ||
			(str[i] == '\v') || (str[i] == '\n') || (str[i] == '\f'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		sign = (str[i] == '-') ? (-1) : (1);
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		if ((result > 2147483647) && (sign == 1))
			return (-1);
		if ((result > 2147483648) && (sign == -1))
			return (0);
		result = 10 * result + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
