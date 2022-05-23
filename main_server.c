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

void sig_handler(int signum){
  ft_printf("Inside handler function server %d\n",signum );
}

int main()
{
  signal(SIGUSR1,sig_handler);
  ft_printf("Inside main function server\n");
  ft_printf("\n__ %d __\n",getpid());
  while(1);
  return 0;
}