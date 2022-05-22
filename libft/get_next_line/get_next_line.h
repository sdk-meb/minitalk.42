/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:25:22 by mes-sadk          #+#    #+#             */
/*   Updated: 2021/12/12 16:54:06 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/uio.h>

size_t	gt_strlen(const char *s);
void	*gt_del(const char *s);
char	*gt_strjoin(char const *s1, char const *s2);
int		gt_memchr(const void *s, int c, size_t len);
char	*gt_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif
