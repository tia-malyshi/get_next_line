/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 19:13:24 by tmalyshi          #+#    #+#             */
/*   Updated: 2026/09/15 19:43:03 by tmalyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *ft_strchr(const char *s, int c)
{
    char ch;
    int i;

    i = 0;
    ch =(char )c;
    while (1)
    {
        if(s[i] == ch)
            return((char *)&s[i]);
        if (s[i] == '\0')
            break;
        i++;
    }
    
    return(NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	l;
    char *s;
    size_t i;

    s = (char *)src;

	l = ft_strlen(s);

    i = 0;
    if (size < 1)
        return(l);
    while ( s[i] && i < size - 1)
    {
        dst[i] = s[i];
        i++;
    }
    dst[i] = 0;
	return (l);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void deallocate(t_list **data)
{
    t_list  *temp;

    if (!(*data))
        return ;
    while( (*data)->next != NULL)
    {
        temp = (*data)->next;
        free((*data)->stash);
        free(data);
        *data = temp;
    }
    free(*data);
}

void list_init(t_list **data)
{

    (*data) = malloc(sizeof(t_list));
    if (!data)
        return ;
    (*data)->stash = NULL;
    (*data)->stash_len = 0;
    (*data)->next = NULL;
}

