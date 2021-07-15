/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:06:06 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/07/05 10:01:45 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	collect_pid_and_sent_signal(char *c, int *bit_index, bool *flag)
{
	static char	*str;
	static int	index;

	str = ft_reallocf(str, sizeof(char) * index, sizeof(char) * (index + 1));
	if (str == NULL)
	{
		write(2, "Error\ncannot allocate memory\n", 29);
		exit(EXIT_FAILURE);
	}
	if (*c == '\0')
	{
		str[index] = *c;
		usleep(100);
		kill(ft_atoi(str), SIGUSR1);
		ft_free_1d(&str);
		*flag = 1;
		index = -1;
	}
	else
		str[index] = *c;
	*c = '\0';
	*bit_index = 0;
	index += 1;
}

void	collect_string_and_print(char *c, int *bit_index, bool *flag)
{
	static char	*str;
	static int	index;

	str = ft_reallocf(str, sizeof(char) * index, sizeof(char) * (index + 1));
	if (str == NULL)
	{
		write(2, "Error\ncannot allocate memory\n", 29);
		exit(EXIT_FAILURE);
	}
	if (*c == '\0')
	{
		str[index] = *c;
		write(1, str, index + 1);
		write(1, "\n", 1);
		ft_free_1d(&str);
		*flag = 0;
		index = -1;
	}
	else
		str[index] = *c;
	*c = '\0';
	*bit_index = 0;
	index += 1;
}

void	sig_handler(int sig)
{
	static char	c;
	static int	bit_index;
	static bool	flag;

	if (sig == SIGUSR2)
		c |= 1 << bit_index;
	bit_index++;
	if (bit_index == 8 && flag == 0)
		collect_pid_and_sent_signal(&c, &bit_index, &flag);
	if (bit_index == 8 && flag == 1)
		collect_string_and_print(&c, &bit_index, &flag);
}

int	main(void)
{
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	write(1, "the PID of the server is: ", 26);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
