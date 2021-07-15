/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:05:40 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/07/05 10:12:16 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

pid_t	check_and_return_pid(char *pid_str)
{
	pid_t	pid;

	pid = ft_atoi_plus(&pid_str);
	if (pid <= 0 || *pid_str != '\0')
	{
		write(2, "Error\nthe PID entered is not the PID of the server\n", 51);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	ft_sent_single_char(char c, pid_t pid)
{
	size_t	index_bit;
	int		ret;

	index_bit = 0;
	while (index_bit < 8)
	{
		if (c & (1 << index_bit))
			ret = kill(pid, SIGUSR2);
		else
			ret = kill(pid, SIGUSR1);
		if (ret == -1)
		{
			write(2, "Error occurred\n", 15);
			exit(EXIT_FAILURE);
		}
		usleep(50);
		index_bit++;
	}
}

void	ft_sent_string(pid_t pid, char *string)
{
	size_t	index_char;
	size_t	len;

	index_char = 0;
	len = ft_strlen(string);
	while (index_char < len + 1)
	{
		ft_sent_single_char(string[index_char], pid);
		index_char++;
	}
}

void	sig_handler(int sig)
{
	(void)sig;
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*ptr;

	if (argc != 3)
	{
		write(2, "Error\nUsage: <./client> <the server PID> <string>\n", 50);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, sig_handler);
	pid = check_and_return_pid(argv[1]);
	ptr = ft_itoa(getpid());
	ft_sent_string(pid, ptr);
	free(ptr);
	if (!(usleep(200)))
	{
		write(2, "Error\ncannot send the string to server\n", 39);
		exit(EXIT_FAILURE);
	}
	ft_sent_string(pid, argv[2]);
	write(1, "String received\n", 16);
	return (0);
}
