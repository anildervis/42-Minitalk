#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// ---------- server.c ----------
void ft_itoa(int num);
void signal_take(int signal);

// ---------- client.c ----------
int ft_atoi(char *str);
void send(int pid, int chr);

#endif