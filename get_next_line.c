/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 09:27:16 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/09/16 17:01:59 by tmalyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *extract_line(t_list *data)
{
    char *line;
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    if(!data || !data->stash)
        return (NULL);
    while (data->stash[i] && (data->stash[i] != '\n'))
        i++;
    if (data->stash[i] == '\n')
        i++;
    line = malloc(i + 1);
    if (!line)
        return (NULL);
    ft_strlcpy(line, data->stash, i + 1);
    data->stash_len -= i;
    while (data->stash[i] != '\0')
        data->stash[j++] = data->stash[i++];
    data->stash[j] = '\0';
    return(line);
}

char	*stash_join(t_list *data, char *buffer, size_t len)
{
	char	*new_stash;
	size_t	i;
	size_t	j;

    i = 0;
	j = 0;
	new_stash = malloc(data->stash_len + len + 1);
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
    char *buffer;
    ssize_t len;

    buffer = malloc ((size_t)BUFFER_SIZE + 1);
    if (!buffer)
        return(NULL);
    while (!data->stash || !ft_strchr(data->stash, '\n'))
    {
        len = read(fd, buffer, BUFFER_SIZE);
        if (len < 0)
        {
            free(buffer);
            return (NULL);
        }
        if (len == 0)  
            break ; 
        buffer[len] = '\0';
        data->stash = stash_join(data, buffer, (size_t) len);
        if(!data->stash)
            return(NULL);
    }
    free(buffer);
    return(data->stash);
}

char *get_next_line(int fd)
{
    static t_list *data;
    char    *line;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    if (!data)
        list_init(&data);
    if (!data->stash || !ft_strchr(data->stash, '\n'))
        data->stash = get_stash(fd, data);
    line = extract_line(data);
    if (!line)
    {
        deallocate(&data);
        return (NULL);
    }
    if (data->stash_len == 0)
    {
        free(data->stash);
        data->stash = NULL;
    }
    return(line);
}

// int main(int argc, char *argv[])
// {
//     int fd;
//     char *line;
//     char *message;  

//     if (argc < 2)
//     {
//         message = "Error, missing filename\n";
//         printf("%s", message);
//         return (1);
//     }
//     fd = open(argv[1], O_RDONLY);
//     printf("argv[1] = [%s]\n", argv[1]);
//     printf("fd = %d\n", fd);
//     if (fd >= 0)
//     {
//         line = get_next_line(fd);
//         while (line) 
//         {
//             free(line);
//             line = get_next_line(fd);
//         }
//         //printf("%s", line); 
//     }
//     else
//     {
//         perror("open");
//         message = "Error, open() failed\n";
//         printf("%s", message);
//         close(fd);
//         return (1);
//     }
//     free(line);
//     close(fd);
//     return(0);
// }