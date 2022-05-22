/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:26:22 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/05/21 11:24:53 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	s;

	i = 0;
	s = 1;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' '
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
			i++;
	if (str[i] == '-' || str[i] == '+')
		s = 44 - str[i++];
	if (str[i] >= '0' && str[i] <= '9')
	{
		n = (str[i] - 48);
		while (i++, str[i] >= '0' && str[i] <= '9')
			n = (str[i] - 48) + (10 * n);
	}
	else
		return (0);
	return (n * s);
}
