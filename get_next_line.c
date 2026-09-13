/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 09:27:16 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/09/13 22:09:38 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
 
//printf("%s\n", dst);
	return (l);
}
char	*stash_join(t_list *data, char *buffer, size_t len)
{
	char	*new_stash;
	size_t	i;
	size_t	j;

	new_stash = malloc(data->stash_len + len + 1);
	if (new_stash == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < data->stash_len)
	{
		new_stash[i] = data->stash[i];
		i++;
	}
	while (j < len)
	{
		new_stash[i + j] = buffer[j];
		j++;
	}
	new_stash[i + j] = '\0';
    free(data->stash);
    data->stash_len += len;
	return (new_stash);
}

char *get_stash(int fd, t_list *data)
{
    char buffer[BUFFER_SIZE + 1];
    ssize_t len;
    
    while (!ft_strchr(data->stash, '\n'))
    {
        len = read(fd, buffer, BUFFER_SIZE);
        if (len < 0)
            return (NULL);
        if (len == 0)
            break ;
        buffer[len] = '\0';
        data->stash = stash_join(data, buffer, (size_t) len);
        if(!data->stash)
            return(NULL);
    } 
    return(data->stash);
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
//ssize_t read(int fd, void *buf, size_t nbyte);
char *get_next_line(int fd)
{
    static t_list *data;
    //char    *line;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    if (!data)
    {
        data = malloc(sizeof(t_list));
        if (!data)
            return (NULL);
        data->stash = NULL;
		data->stash_len = 0;
		data->next = NULL;
    }
    data->stash = get_stash( fd, data);
    if (!(get_stash(fd, data)))
        deallocate(&data); 
    printf("%s", data->stash);
    return(NULL);
}

int main(int argc, char *argv[])
{
    int fd;
    char *line;
    char *message;  

    if (argc < 2)
    {
        message = "Error, missing filename\n";
        printf("%s", message);
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd >= 0)
    {
        line = get_next_line(fd);
        //printf("%s", line); 
    }
    else
    {
        perror("open");
        message = "Error, open() failed\n";
        printf("%s", message);
        close(fd);
        return (1);
    }
    close(fd);
    return(0);
}