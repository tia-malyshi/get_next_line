/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 11:12:37 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/09/14 19:46:09 by tmalyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
# define BUFFER_SIZE 5
# endif

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    char           *stash;
    int                fd;
    size_t               stash_len;
    struct s_list   *next;
}               t_list; 

char *get_next_line(int fd);
char *get_stash(int fd, t_list *data);
char	*stash_join(t_list *data, char *buffer, size_t len);
char *extract_line(t_list *data);

char *ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
void deallocate(t_list **data);

# endif