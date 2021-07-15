/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:08:19 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/06/30 12:03:17 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	sig_handler(int sig);
void	ft_sent_string(pid_t pid, char *string);
void	ft_sent_single_char(char c, pid_t pid);
pid_t	check_and_return_pid(char *pid_str);
char	*ft_itoa(int n);
int		ft_atoi_plus(char **str);
size_t	ft_strlen(const char *s);

#endif
