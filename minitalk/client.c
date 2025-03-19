/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayousf <cbayousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:12:05 by cbayousf          #+#    #+#             */
/*   Updated: 2025/03/18 11:16:19 by cbayousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "printf/ft_printf.h"

static	void	check_atoi(int signe, long long c)
{
	if ((signe == 1 && c > INT_MAX) || (signe == -1 && (-c) < INT_MIN))
	{
		write(2, "Invalid PID range!\n", 19);
		exit(1);
	}
}

static int	ft_atoi(const char *str)
{
	int			i;
	long long	c;
	int			signe;

	i = 0;
	c = 0;
	signe = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		c = c * 10 + (str[i] - '0');
		check_atoi(signe, c);
		i++;
	}
	return ((int)(signe * c));
}

static int	invalid_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3 || av[2][0] == '\0')
	{
		write(2, "Invalid arguments! Usage: ./client <pid> <message>\n", 54);
		return (1);
	}
	if (av[1][0] == '+')
		i++;
	while (av[1][i])
	{
		if (av[1][i] < '0' || av[1][i] > '9')
		{
			write(2, "Invalid PID!\n", 13);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	send_message(int pid, char str)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((str >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(2, "Error sending SIGUSR1\n", 23);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(2, "Error sending SIGUSR2\n", 23);
				exit(1);
			}
		}
		usleep(500);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	if (invalid_args(ac, av))
		return (1);
	pid = ft_atoi(av[1]);
	if (pid < 100 || pid > PID_MAX_LIMIT)
	{
		write(2, "Invalid PID range!\n", 19);
		return (1);
	}
	i = 0;
	while (av[2][i])
	{
		send_message(pid, av[2][i]);
		i++;
	}
	send_message(pid, '\0');
	return (0);
}
