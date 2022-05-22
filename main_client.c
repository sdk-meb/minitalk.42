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

void ds(int pid, int mes)
{
   kill(pid, mes);
    while (1);
    exit (0);
}

int main(int c ,char **t)
{
   ft_printf("\n%s\n",t[1]);
    c = ft_atoi(t[1]);
    ds(getpid(), c);

    return (0);
}
