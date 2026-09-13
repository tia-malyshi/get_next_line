/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 11:12:37 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/09/13 15:04:45 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
# define BUFFER_SIZE 42
# endif

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    char           *stash;
    int                fd;
    int               stash_len;
    struct s_list   *next;
}               t_list; 

char *get_next_line(int fd);

# endif