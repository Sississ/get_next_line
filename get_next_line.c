/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschofer <sschofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:54:57 by sschofer          #+#    #+#             */
/*   Updated: 2022/07/08 14:14:54 by sschofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*the_reader(int fd, char *storage)
{
	char	*text;
	int		n;

	text = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!text)
	{
		free (text);
		return (NULL);
	}
	n = 1;

	while (!ft_strchr(storage, '\n') && n != 0)
	{
		n = read(fd, text, BUFFER_SIZE);
		if(!storage)
			return text;
			printf("reader: text: %s\n", text);
		if (n == -1)
		{
			free (text); 
			return (NULL);
		}
		text[n] = '\0';
		storage = ft_strjoin(storage, text);
		printf("reader: joined string: %s\n", storage);
	}
	free(text);
	return (storage);
}

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

char	*left_overs(char *storage)
{
	char	*temp;
	int		i;
	int		j; 

	if (!storage)
	{
		free(storage);
		return (NULL);
	}
	j = ft_lenton(storage);
	temp = malloc(sizeof(char) * (ft_strlen(storage) - j + 1));
	// temp = malloc(sizeof(char) * (ft_strlen(storage) + 1));
	if (!temp)
	{
		free (temp);
		printf("no temp\n");
		return (NULL);
	}
	i = 0; 
	while (storage[i] && storage[i] != '\0')
	{
		temp[i] = storage[j];
		i++;
		j++;
	}
	temp[i] = '\0';
	printf("left overs temp: %s\n", temp);
	return (temp);
	free(temp);
	free(storage);
}

char	*get_next_line(int fd)
{ 
	static char	*storage;
	char		*line; 

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	storage = the_reader(fd, storage);
	printf("get_next_line, storage: %s\n", storage);
	if (!storage)
		return (NULL);
	line = line_transfer(storage);
	printf("get_next_line: %s\n", line);
	storage = left_overs(storage);
	printf("get_next_line, storage: %s\n", storage);
	return(line);
}

# include <fcntl.h>
# include <stdio.h>

int main()
{
    int    fd;
	char	*line; 
    fd = open("tyger.txt", O_RDONLY);
    if (fd == -1)
		printf("error at file opening: %d", fd);
	if (fd == 0)
		printf("end or empty: %d\n", fd);
	if (fd >= 1)
		printf("opened: %d\n", fd);
	line = get_next_line(fd);
	printf("line: %s\n", line);
	// close(fd);
}