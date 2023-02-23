#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// ------- server_bonus.c -------
void signal_take(int signal);

// ------- client_bonus.c -------
void send(int pid, int chr);

// ------- minitalk_utils.c -------
void ft_itoa(int num);
int ft_atoi(char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);

#endif