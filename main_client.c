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

void sig_handler(int signum){
  ft_printf("Inside handler function%d\n",signum );
}

int main(int l_parm, char **info)
{
  pid_t pid = l_parm;

  signal(SIGUSR1,sig_handler);
  pid = ft_atoi(info[1]);
  kill(pid,SIGUSR1);
  ft_printf("Inside main function\n");
  while(1);
  return 0;
}
