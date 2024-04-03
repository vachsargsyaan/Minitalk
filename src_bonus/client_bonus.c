/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:14:17 by vacsargs          #+#    #+#             */
/*   Updated: 2023/06/25 19:54:13 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

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

int	sig_count(void (*signal))
{
	static int	i = 0;

	if ((int)signal == SIGUSR1)
		i++;
	return (i);
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
			signal(SIGUSR1, (void *)&sig_count);
			signal(SIGUSR2, (void *)&sig_count);
			ft_ft(argv[2][i], ft_atoi(argv[1]));
			i++;
		}
		if (ft_strlen(argv[2]) == sig_count((void *)signal))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(1);
	}
}
