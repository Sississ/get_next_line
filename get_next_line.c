/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschofer <sschofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:54:57 by sschofer          #+#    #+#             */
/*   Updated: 2022/07/01 09:47:12 by sschofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*the_reader(int fd, char *storage)
{
	char	*t_read;
	int		n_read;

	t_read = (malloc(sizeof(char) * BUFFER_SIZE + 1));
	if (!t_read)
	{
		free (t_read);
		return (NULL);

	}
	n_read = read(fd, t_read, BUFFER_SIZE);
	while (!ft_strchr(storage,'\n') && n_read > 0)
	{
		
		if (n_read == -1)
			free (t_read); 
			return (NULL);
		storage = ft_strjoin(storage, t_read);
	}
	storage[n_read] = '\0';
	free(t_read);
	return (storage);
}

//Copies the line from the buffer until it meets a new line symbol, 
//or the end of the document. ('\0'). returns the (next) line to the main function. 
//Uses malloc to allocate space for line and my ft_lenton. 
//Adds a new line (if there is one in the text doc) and a null terminator to the end of line. 
char *line_transfer(char *storage)
{
	char	*line;
	int		i; 

	if (!storage)
		return (NULL);
	line = malloc(sizeof(char) * (ft_lenton(storage) + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
if (storage[i] == '\n')
	line[i] = '\n';
line[i + 1] = '\0';
return (line);
}

//When the buffer variable arrives to this function it contains left overs from 
//the previous round and what was read last(length controlled by buffer size).   
//Here everything that was copied into line should be removed. 
// That is everything up to '\n' or ... '\0' end of line. 
// I think the easiest way is using a tepmporary variable, temp. 
//fill temp using ... a libftfunction. either strchr to look for \n, then duplicating with memcpy?  
//or ft_substr setting ft_strlenton as start. 
//do I need to free my buffer variable? 
char	*left_overs(char *storage)
{
	char	*temp;

	if (!storage)
	return (NULL);
	temp =  storage; 
	printf("storage at entry: %s", storage);
	printf("temporary string after filling: %s", temp);
	free(storage);
	ft_memcpy(storage, temp, (size_t)(temp + ft_lenton(temp)));
	printf("storage after freeing: %s", storage);
	free(temp);
	printf("storage after refilling: %s", storage);
	printf("temp after freeing: %s", temp);
	return (storage);
}

//get_next_line takes a fd, and sends back one line for each time it is run.
char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line; 

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	storage = the_reader(fd, storage);
	if (!storage)
		return (NULL);
	line = line_transfer(storage);
	storage = left_overs(storage);
	return(line);
}

# include <fcntl.h>
# include <stdio.h>

int main()
{
    int    fd;
    fd = open("tyger.txt", O_RDONLY);
    for (int i = 0; i < 5; i++)
    {
        printf("\n i: %d the function output: %s\n", i, get_next_line(fd));
    }
	close(fd);
}