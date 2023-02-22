#include "minitalk.h"

int ft_atoi(char *str)
{
    int num;

    num = 0;
    while (*str)
    {
        if (*str >= '0' && *str <= '9')
            num = num * 10 + *str - '0';
        else
            exit(1); // + error message
        str++;
    }
    return (num);
}

void send(int pid, int chr)
{
    // int i;
    int bit;

    bit = 7;
    // i = 128;
    // while (i >= 1)
    while (bit >= 0)
    {
        if (chr >> bit & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        // if ((chr / i) % 2 == 0)
        //     kill(pid, SIGUSR2);
        // else
        //     kill(pid, SIGUSR1);
        usleep(100);
        bit--;
        // i /= 2;
    }
}

int main(int argc, char **argv)
{
    int pid;
    char *str;

    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        str = argv[2];
        while (*str)
            send(pid, *str++);
    }
    else
        exit(1); // + error message
    return (0);
}