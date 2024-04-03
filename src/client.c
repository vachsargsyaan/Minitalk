/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:36:33 by vacsargs          #+#    #+#             */
/*   Updated: 2023/06/25 15:34:21 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	num;

	num = 0;
	if (!str)
		return (0);
	if (*str == '+')
		++str;
	if (*str == '0')
	{
		ft_printf("Error\n");
		exit(1);
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (*str)
	{
		ft_printf("Error\n");
		exit(1);
	}
	return (num);
}

void	ft_ft(char a, int sig)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (a & (0x01 << bit))
			kill(sig, SIGUSR1);
		else
			kill(sig, SIGUSR2);
		usleep(500);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[2][i] != '\0')
		{
			ft_ft(argv[2][i], ft_atoi(argv[1]));
			i++;
		}		
	}
	return (0);
}
