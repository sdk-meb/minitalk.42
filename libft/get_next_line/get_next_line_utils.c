/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:36:00 by mes-sadk          #+#    #+#             */
/*   Updated: 2021/12/11 12:31:30 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/***************************************\
*              FT_STLEN                 *
\***************************************/
size_t	gt_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/***************************************\
*               FT_DEL                  *
\***************************************/
void	*gt_del(const char *s)
{
	int	len;

	if (!s)
		return (NULL);
	len = gt_strlen(s);
	while (len--)
		*(char *)(s + len) = 0;
	free((void *)s);
	return (NULL);
}

/***************************************\
*              FT_MEMCHR                *
\***************************************/
int	gt_memchr(const void *s, int c, size_t len)
{
	char	*h;
	int		i;

	i = 0;
	if (!s)
		return (0);
	h = (char *)s;
	i = gt_strlen(s) - 1;
	while (i >= 0 && h[i] && len--)
		if (h[i--] == (char) c)
			return (1);
	return (0);
}

/***************************************\
*                FT_STRJOIN             *
\***************************************/
char	*gt_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*rjoin;
	int		ss1;

	if (!s1)
		return (NULL);
	ss1 = gt_strlen((char *)s1);
	join = malloc(ss1 + gt_strlen(s2) + 1);
	rjoin = join;
	while (*s1)
		*join++ = *s1++;
	gt_del(s1 - ss1);
	while (*s2)
		*join++ = *s2++;
	*join = '\0';
	return (rjoin);
}

/***************************************\
*                FT_SUBSTR              *
\***************************************/
char	*gt_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	n;

	if (!s)
		return (NULL);
	n = gt_strlen(s);
	if (start > n)
		n = 0;
	else if (len + start > n)
		n = n - start;
	else
		n = len;
	sub = malloc(n + 1);
	if (!sub)
		return (gt_del(s));
	sub[n] = '\0';
	while (n--)
		sub[n] = s[start + n];
	gt_del(s);
	return ((char *)sub);
}
