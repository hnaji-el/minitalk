/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:05:55 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/06/30 12:02:11 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

static int	numb(int nb)
{
	if (nb == 0)
		return (1);
	return (1 + numb(nb / 10));
}

static char	*affect(char *s, int num, int i)
{
	unsigned int	l;

	l = 0;
	if (num == 0)
		*s = num + 48;
	else if (num < 0)
	{
		*s = '-';
		l = num * (-1);
	}
	else
		l = num;
	s[i + 1] = '\0';
	while (l != 0)
	{
		s[i] = l % 10 + 48;
		l = l / 10;
		i--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*dst;

	if (n > 0)
		len = numb(n) - 1;
	else
		len = numb(n);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
	{
		write(2, "Error\ncannot allocate memory\n", 29);
		exit(EXIT_FAILURE);
	}
	return (affect(dst, n, len - 1));
}

int	ft_atoi_plus(char **str)
{
	long	nb;
	int		sign;

	sign = 1;
	nb = 0;
	while ((**str >= 9 && **str <= 13) || **str == 32)
		(*str)++;
	if (**str == '-')
		sign = sign * (-1);
	if (**str == '-' || **str == '+')
		(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		nb = nb * 10 + (**str - '0');
		(*str)++;
	}
	if (nb < 0 && sign > 0)
		return (-1);
	if (nb < 0 && sign < 0)
		return (0);
	return (sign * nb);
}

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
