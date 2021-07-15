/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:06:19 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/06/30 12:02:57 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

int	ft_atoi(const char *str)
{
	long	nb;
	int		sign;

	sign = 1;
	nb = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		sign = sign * (-1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	if (nb < 0 && sign > 0)
		return (-1);
	if (nb < 0 && sign < 0)
		return (0);
	return (sign * nb);
}

void	*ft_reallocf(void *old_alloc, size_t old_size, size_t new_size)
{
	unsigned char	*old_alloc_t;
	unsigned char	*new_alloc;
	size_t			i;

	i = 0;
	if (old_alloc == NULL)
		return (malloc(new_size));
	old_alloc_t = (unsigned char *)old_alloc;
	new_alloc = (unsigned char *)malloc(new_size);
	if (new_alloc == NULL)
	{
		free(old_alloc);
		return (NULL);
	}
	while (i < old_size && i < new_size)
	{
		new_alloc[i] = old_alloc_t[i];
		i++;
	}
	free(old_alloc);
	return (new_alloc);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	n;

	if (nb < 0)
	{
		ft_putchar('-');
		n = nb * (-1);
	}
	else
		n = nb;
	if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
}

void	ft_free_1d(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}
