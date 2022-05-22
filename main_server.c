/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:35:06 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/05/21 11:35:16 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "talk.h"

void gh(int g)
{
    ft_printf("\n%d\n",g);
}

void ds(int f)
{
    ft_printf ("%d\n",f);
    while (signal(1, gh)|| 1);
    exit (0);
}

int main()
{
    // signal();
    // sigemptyset();
    // sigaddset();
    // sigaction();
    ds(getpid());

    return (0);
}
