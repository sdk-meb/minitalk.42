/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:36:06 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/05/25 15:55:00 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "talk.h"

void	received(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_printf("Your data has sent to server successful !!\n");
		exit (0);
	}
	else if (sig == SIGUSR1)
	{
		ft_printf("(...)Your data does not received completely by server !!\n");
		exit (1);
	}
	else if (sig == -1)
	{
		ft_printf("!!! your data does not received correctly by server !!!\n");
		exit (1);
	}
}

void	send_bit_by_bit(int pid, char data_c)
{
	int	size_ascii;

	size_ascii = 0;
	while (size_ascii < 8)
	{
		kill(pid, SIGUSR1 + ((data_c >> size_ascii++) & 1));
		usleep(70);
	}
}

void	dismantling_mes(int pid, char *message)
{
	int	index;

	index = 0;
	signal(SIGUSR1, received);
	signal(SIGUSR2, received);
	while (message[index])
	{
		send_bit_by_bit(pid, message[index++]);
	}
	send_bit_by_bit(pid, '\0');
	sleep(4);
	received(-1);
}

int	main(int l_parm, char **info)
{
	int pid;

	pid = ft_atoi(info[1]);
	if (l_parm != 3 || pid < 0)
	{
		ft_printf("The PID or the message has no selected !!!\n");
		exit (0);
	}
	dismantling_mes(pid, info[2]);
	received(-1);
	return (0);
}
