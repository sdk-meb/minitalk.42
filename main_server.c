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

void receive_sig(int signum)
{
  static char     c;
  static short power;

  if (!power || power == 1)
    power++;
  else
    power *= 2;
  c += (signum % 2) * power;
  if (power == 128)
  {
    ft_printf("%c",c);
    c = 0;
    power = 0;
  }
}

int main()
{
  ft_printf("%d\n",getpid());
  signal(SIGUSR1, receive_sig);
  signal(SIGUSR2, receive_sig);
  while(1);
  return 0;
}
