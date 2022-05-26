/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:35:06 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/05/25 16:14:13 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "talk.h"

char	bit_assembly(bool bit, bool rest)
{
	int static				size_ascii;
	unsigned char static	c;

	if (rest)
	{
		size_ascii = 0;
		c = 0;
	}
	c |= bit << size_ascii;
	if (++size_ascii == 8)
	{
		size_ascii = 0;
		write(1, &c, 1);
		if (c == '\0')
			return (c);
		c = 0;
	}
	return (1);
}

void	receive_sig(int signum, siginfo_t *info, void *uap)
{
	int static	g_pid;

	(void )uap;
	if (!g_pid)
		g_pid = info->si_pid;
	if (g_pid != info->si_pid && info->si_pid)
	{
		kill(g_pid, SIGUSR1);
		bit_assembly(signum % 2, 1);
		g_pid = info->si_pid;
		return ;
	}
	if (!bit_assembly(signum % 2, 0))
	{
		kill (g_pid, SIGUSR2);
		g_pid = 0;
	}
}

void	icp_cl(void)
{
	struct sigaction	act;

	act.sa_sigaction = &receive_sig;
	ft_printf(" PROCESS NAME                 PID\n");
	ft_printf("   server                     %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
}

int	main(void)
{
	icp_cl ();
	return (0);
}
