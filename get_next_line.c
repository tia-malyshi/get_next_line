/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 09:27:16 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/09/11 11:33:24 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 42

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

 //ssize_t read(int fd, void *buf, size_t nbyte);
char *get_next_line(int fd)
{
    static char *stash;
    char *line;
    void *buffer;
    int i;
    ssize_t len;
    int n;

    n = 10;
    while (*buffer)
    {
        len = read(fd, buffer, BUFFER_SIZE);
        if (stash && buffer)
            *stash++ =(char ) *buffer++;
    }
    while (i < len)
    {
        if (stash[i] != "\n")
            line = ft_strlcpy(line, stash, len);
        stash = ft_strchr(stash, '\n');
    }
    return(line);
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