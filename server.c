#include "minitalk.h"

void signal_take(int signal)
{
    static int bit = 7;
    static char chr = 0;

    if (signal == SIGUSR1)
        chr += 1 << bit;
    if (bit == 0)
    {
        write(1, &chr, 1);
        bit = 8;
        chr = 0;
    }
    bit--;
}

int main()
{
    write(1, "PID of the server:\n", 19);
    ft_itoa(getpid());
    write(1, "\n", 1);
    signal(SIGUSR1, signal_take);
    signal(SIGUSR2, signal_take);
    while (1)
        pause();
}