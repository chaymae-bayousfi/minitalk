/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayousf <cbayousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:32:04 by cbayousf          #+#    #+#             */
/*   Updated: 2025/03/18 11:19:54 by cbayousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "printf/ft_printf.h"

static	int	tag(void)
{
	ft_printf("\n\n"
		"███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗\n"
		"████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝\n"
		"██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ \n"
		"██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ \n"
		"██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\n"
		"╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n\n"
		"\t\t\t   1 3 3 7\n\n");
	return (0);
}

static	void	handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				i = 7;
	static pid_t			pid;

	(void)context;
	if (info->si_pid != pid)
	{
		i = 7;
		c = 0;
		pid = info->si_pid;
	}
	if (signum == SIGUSR1)
		c |= (1 << i);
	i--;
	if (i < 0)
	{
		write(1, &c, 1);
		c = 0;
		i = 7;
	}
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sa;

	tag();
	(void)av;
	if (ac != 1)
		return (1);
	pid = getpid();
	ft_printf("PID : %d \n", pid);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		write(2, "Failed to set SIGUSR1 handler\n", 30);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		write(2, "Failed to set SIGUSR2 handler\n", 30);
	ft_printf("Le programme est en pause, attendez un signal...\n");
	while (1)
		pause();
	return (0);
}
