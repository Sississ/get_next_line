/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschofer <sschofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:45:10 by sschofer          #+#    #+#             */
/*   Updated: 2022/07/08 12:40:04 by sschofer         ###   ########.fr       */
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
