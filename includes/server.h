/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:19:09 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/06/30 12:03:35 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/types.h>

void	sig_handler(int sig);
void	collect_pid_and_sent_signal(char *c, int *bit_index, bool *flag);
void	collect_string_and_print(char *c, int *bit_index, bool *flag);
int		ft_atoi(const char *str);
void	*ft_reallocf(void *old_alloc, size_t old_size, size_t new_size);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_free_1d(char **str);
#endif
