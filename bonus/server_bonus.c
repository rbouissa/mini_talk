/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:13:39 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/19 18:16:07 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_server(int sign)
{
	static int	bit;
	static char	f;

	f |= (sign == SIGUSR1);
	if (++bit == 8)
	{
		ft_putchar(f);
		bit = 0;
		f = 0;
	}
	else
		f = f << 1;
}

int	main(void)
{
	pid_t	p;

	p = getpid();
	ft_putnbr(p);
	ft_putchar('\n');
	signal(SIGUSR1, signal_server);
	signal(SIGUSR2, signal_server);
	while (1)
		pause();
}
