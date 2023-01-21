/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_helpers_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:14:34 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/19 18:15:56 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if ((nb >= 0) && (nb <= 9))
	{
		ft_putchar(nb + '0');
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * (-1));
	}
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	numb;
	int					negative;

	i = 0;
	numb = 0;
	negative = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (str[i] == '-' && ++i)
		negative = 1 - negative;
	else if (str[i] == '+' && ++i)
		negative = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		numb = numb * 10 + str[i] - 48;
		i++;
		if (numb > 9223372036854775807 && negative)
			return (0);
		if (numb > 9223372036854775807)
			return (-1);
	}
	if (negative)
		numb = numb * (-1);
	return (numb);
}
