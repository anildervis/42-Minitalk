#include "minitalk_bonus.h"

void signal_take(int sig, siginfo_t *info, void *ucontext)
{
    static int bit = 7;
    static char chr = 0;

    (void)ucontext;
    if (sig == SIGUSR1)
        chr += 1 << bit;
    if (bit == 0)
    {
        write(1, &chr, 1);
        bit = 8;
        chr = 0;
        kill (info->si_pid, SIGUSR1);
    }
    bit--;
}

void set_signal_action(void)
{
	struct sigaction	act;
	ft_bzero(&act, sizeof(act));
    act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = signal_take;
    while (1)
    {
        sigaction(SIGUSR1, &act, NULL);
        sigaction(SIGUSR2, &act, NULL);
        pause();
    }
}

int main()
{
    write(1, "PID of the server:\n", 19);
    ft_itoa(getpid());
    write(1, "\n", 1);
    set_signal_action();
}