#include "minitalk_bonus.h"

int len;

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

void message_sent(int signal)
{
    static int i = 1;

    (void)signal;
    if (i == len)
    {
        write(1, "Message Sent!\n", 14);
        exit(1);
    }
    i++;
}

int main(int argc, char **argv)
{
    unsigned char *str;
    int pid;
    if (argc == 3)
    {
        signal(SIGUSR1, message_sent);
        pid = ft_atoi(argv[1]);
        str = (unsigned char *)argv[2];
        len = ft_strlen(argv[2]);
        while (*str)
            send(pid, *str++); 
    }
    else
        exit(1);
    return (0);
}