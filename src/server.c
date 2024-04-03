/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:26:25 by vacsargs          #+#    #+#             */
/*   Updated: 2023/06/25 15:33:40 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_function(int signal)
{
	static int	bit = 0;
	static int	i = 0;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		i = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	(void)argv;
	if (argc == 1)
	{
		i = getpid();
		ft_printf("proces id = [%d]\n", i);
		while (1)
		{
			signal(SIGUSR1, &sig_function);
			signal(SIGUSR2, &sig_function);
			pause();
		}
	}
	return (0);
}
