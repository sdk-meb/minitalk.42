/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:36:06 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/05/22 10:36:08 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "talk.h"

void    sig_handler(int signum)
{
    ft_printf("Inside handler function%d\n",signum %2 );
}

void    send_bit_by_bit(int pid, char data_c)
{
    int size_ascii;
    int bit;

    size_ascii = 8;
    while(size_ascii--)
    {
        bit = data_c % 2;
        data_c /= 2;
        if (bit)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(30);
    }
}

void dismantling_mes(int pid, char *message)
{
    int     index;

    index = 0;
    while (message[index])
    {
        send_bit_by_bit(pid, message[index++]);
    }
}

void reach(pid_t pid, char *message)
{
    dismantling_mes(pid, message);
}

int main(int l_parm, char **info)
{
    if (l_parm != 3)
    {
        ft_printf("The PID or the message has no selected\n");
        exit (0);
    }
    reach(ft_atoi(info[2]), info[1]);
    while(1);
    return 0;
}
