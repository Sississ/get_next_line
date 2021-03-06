/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschofer <sschofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:45:10 by sschofer          #+#    #+#             */
/*   Updated: 2022/07/08 13:19:34 by sschofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*the_reader(int fd, char *buffer)
{
	char	*text;
	int		n;

	printf("fd in reader: %d\n", fd);
	printf("the reader:buffer before: %s\n", buffer);
	text = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!text)
	{
		free (text);
		return (NULL);
	}
	n = 1;
	printf("the reader: bytes before read: %d\n",n);
	while (!ft_strchr(buffer, '\n') && n != 0)
	{
		n = read(fd, text, BUFFER_SIZE);
		printf("the reader: bytes read: %d\n",n);
		printf("the reader:text: %s\n", text);
		if(!buffer)
			return text;
		if (n == -1)
		{
			free (text); 
			return (NULL);
		}
		text[n] = '\0';
		buffer = ft_strjoin(buffer, text);
	}
	printf("the reader: buffer content: %s\n", buffer);
	free(text);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*storage;

	// storage = "n";
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	printf("fd in get: %d\n", fd);
	printf("anything there?, %s\n", storage);
	storage = the_reader(fd, storage);
	printf("get read returned, %s\n", storage);
	if (!storage)
		return (NULL);
	return(storage);
}

#include "get_next_line.h"

int main()
{
    int    	fd;
	int		res; 
	char	*line; 

    line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (0);
	fd = open("tyger.txt", O_RDONLY);
    if (fd == -1)
		printf("error at file opening: %d \n", fd);
	if (fd >= 0)
		printf("fd opened: %d\n", fd); 
	res = read(fd, line, BUFFER_SIZE);
	if (res == -1)
		printf("error at reading: %d\n", res);
	if (res == 0)
		printf("end of file. ret: %d\n", res);
	if (res > 0)
		printf("bytes read: %d\n", res);
	printf("read before get: %s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("line after get: %s\n", line); 
	close(fd);
	free(line);
}

// int main()
// {
//     int    fd;
// 	char	*line; 
//     fd = open("tyger.txt", O_RDONLY);
//     if (fd == -1)
// 		printf("error at file opening: %d", fd);
// 	if (fd == 0)
// 		printf("end or empty: %d\n", fd);
// 	if (fd >= 1)
// 		printf("opened: %d", fd);
// 	line = get_next_line(fd);
// 	printf("line: %s\n", line);
// 	for (int i = 0; i < 5; i++)
//     {
//         printf("\n i: %d the function output: %s\n", i, get_next_line(fd));
//     }
// 	close(fd);
// }

// char	*left_overs(char *storage)
// {
// 	char	*temp;
// 	int		i;

// 	if (!storage)
// 	{
// 		free(storage);
// 		return (NULL);
// 	}
// 	printf("storage at entry: %s", storage);
// 	temp = malloc(sizeof(char) * (ft_lenton(storage) + 1));
// 	printf("address of temp: %p\n", &temp);
// 	if (!temp)
// 	{
// 		free (temp);
// 		printf("no temp\n");
// 		return (NULL);
// 	}
// 	i = 0; 
// 	while (storage[i] && storage[i] != '\0')
// 	{
// 		temp[i] = storage[i];
// 		i++;
// 	}
// 	printf("temporary string after filling: %s\n", temp);
// 	return (temp);
// 	free(temp);
// 	free(storage);
// }

// // need to figure out how to solve lenton if no n in the case of memcpy. maybe use strchr instead. 

// int main ()
// {
// 	static char	*teststr;
// 	char		*returnstr;

// 	teststr = "office hours \n and later on\n";
// 	returnstr = left_overs(teststr);
// 	printf("returned string: %s\n",returnstr);

// }

	// while (*storage++ != '\0')
	// {
	// 	temp = storage;
	// 	temp++;
	// }

// # include <fcntl.h>
// # include <stdio.h>

// int main()
// {
//     int    fd;
// 	char	*line; 
//     fd = open("tyger.txt", O_RDONLY);
//     if (fd == -1)
// 		printf("error at file opening: %d", fd);
// 	if (fd == 0)
// 		printf("end or empty: %d\n", fd);
// 	if (fd >= 1)
// 		printf("opened: %d", fd);
// 	line = get_next_line(fd);
// 	printf("line: %s\n", line);
// 	for (int i = 0; i < 5; i++)
//     {
//         printf("\n i: %d the function output: %s\n", i, get_next_line(fd));
//     }
// 	close(fd);
// }


// char	*left_overs(char *storage)
// {
// 	char	*temp;

// 	if (!storage)
// 	{
// 		free(storage);
// 		return (NULL);
// 	}
// 	printf("storage at entry: %s", storage);
// 	temp = malloc(sizeof(char) * (ft_lenton(storage) + 1));
// 	ft_memcpy(temp, storage, (size_t)(storage + ft_lenton(storage)));
// 	if (!temp)
// 	{
// 		free (temp);
// 		return (NULL);
// 	}
// 	printf("temporary string after filling: %s", temp);
// 	free(storage);
// 	printf("storage after freeing: %s", storage);
// 	return (temp);
// 	free(temp);
// }

//get_next_line takes a fd, and sends back one line for each time it is run.

	// printf("temporary string after filling: %s\n", temp);

		// printf("address of temp: %p\n", &temp);

//When the buffer variable arrives to this function it contains left overs from 
//the previous round and what was read last(length controlled by buffer size).   
//Here everything that was copied into line should be removed. 
// That is everything up to '\n' or ... '\0' end of line. 
// I think the easiest way is using a tepmporary variable, temp. 
//fill temp using ... a libftfunction. either strchr to look for \n, then duplicating with memcpy?  
//or ft_substr setting ft_strlenton as start. 
//do I need to free my buffer variable? 


// char	*the_reader(int fd, char *storage)
// {
// 	char	*t_read;
// 	int		n_read;

// 	t_read = (malloc(sizeof(char) * BUFFER_SIZE + 1));
// 	if (!t_read)
// 	{
// 		return (NULL);
// 	}
// 	n_read = 1;
// 	while (!ft_strchr(storage, '\n') && n_read > 0)
// 	{
// 		n_read = read(fd, t_read, BUFFER_SIZE);
// 		if (n_read == -1)
// 		{
// 			free (t_read); 
// 			return (NULL);
// 		}
// 		t_read[n_read] = '\0';
// 		storage = ft_strjoin(storage, t_read);
// 	}
// 	printf("the reader: storage: %s\n", storage);
// 	free(t_read);
// 	return (storage);
// }

//Copies the line from the buffer until it meets a new line symbol, 
//or the end of the document. ('\0'). returns the (next) line to the main function. 
//Uses malloc to allocate space for line and my ft_lenton. 
//Adds a new line (if there is one in the text doc) and a null terminator to the end of line. 

	// printf("the reader: buffer content: %s\n", buffer);

			// printf("the reader: bytes read: %d\n",n);
		// printf("the reader:text: %s\n", text);

	// printf("fd in reader: %d\n", fd);
	// printf("the reader:buffer before: %s\n", buffer);
			// printf("the reader: bytes before read: %d\n",n);
