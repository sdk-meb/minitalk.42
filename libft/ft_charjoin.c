/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:10:52 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/05/25 16:05:55 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_charjoin(const char *str, char c)
{
	char	*strj;
	int		len;

	if (!str)
		len = 0;
	else
		len = ft_strlen(str);
	strj = malloc(len + 2);
	if (!strj)
		return ((char *) str);
	strj[len + 1] = '\0';
	if (str)
	{
		ft_memmove((void *)strj, str, len + 1);
		free ((void *) str);
	}
	strj[len] = c;
	return (strj);
}
