/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:24:34 by mes-sadk          #+#    #+#             */
/*   Updated: 2021/12/12 16:49:22 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/***************************************\
*                FT_EOL                 *
\***************************************/
int	gt_eol(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		if (s[i++] == '\n')
			return (i);
	return (i);
}

/***************************************\
*          	 	FT_SANL 	            *
\***************************************/
void	gt_sanl(char *sr, int i)
{
	char	*p;

	p = sr + i;
	while (*p)
		*sr++ = *p++;
	while (sr < p)
		*sr++ = '\0';
}

/***************************************\
*             FT_STRDUP                 *
\***************************************/
char	*gt_strdup(const char *s)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc(gt_strlen((char *)s) + 1);
	if (!p)
		return (NULL);
	while (*s)
		p[i++] = *s++;
	p[i] = '\0';
	return (p);
}

/***************************************\
*			GET_NEXT_LINE			    *
\***************************************/
char	*get_line(int fd)
{
	static char	sr_fd[1024][BUFFER_SIZE + 1];
	char		*join;
	int			x;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	join = gt_strdup(sr_fd[fd]);
	while (!gt_memchr(join, '\n', BUFFER_SIZE) && join)
	{
		x = read (fd, sr_fd[fd], BUFFER_SIZE);
		if ((x == -1 && !*sr_fd[fd]) || !(x || join) || !(x || *join))
			return (gt_del(join));
		sr_fd[fd][x] = '\0';
		join = gt_strjoin(join, sr_fd[fd]);
		if (x < BUFFER_SIZE || !join)
			break ;
	}
	if (!join || !*join)
		return (gt_del(join));
	gt_sanl(sr_fd[fd], gt_eol(sr_fd[fd]));
	return (gt_substr(join, 0, gt_eol(join)));
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	return (get_line(fd));
}
