/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 09:27:16 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/09/10 11:04:42 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd)
{
    //static char *stash;
    char *line;

    ssize_t read(int fd, void *buf, size_t nbyte);

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
        line = get_next_line(fd);  
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