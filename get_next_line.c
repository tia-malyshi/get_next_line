/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 09:27:16 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/09/12 16:43:46 by tmalyshi         ###   ########.fr       */
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
char *get_stash(int fd, char *stash)
{
    char buffer[BUFFER_SIZE + 1];
    ssize_t len;
    int i;

    i = 0;
    len = read(fd, buffer, BUFFER_SIZE);
    if (len <= 0)
        return (NULL);
    buffer[len] = '\0'; 
    stash = malloc(len + 1);
    ft_strlcpy(stash, buffer, len);
    return(stash);
}
//ssize_t read(int fd, void *buf, size_t nbyte);
char *get_next_line(int fd)
{
    static char *stash;
    //char *line;
    
    stash = get_stash(fd, stash);
    if 
    //return(line);
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
    if (fd > 0)
    {
        line = get_next_line(fd);
        printf("%s", line); 
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