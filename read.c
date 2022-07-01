#include "get_next_line.h"

// char	*get_next(int fd)
// {
// 	char	*t_read;

// 	t_read = 0; 
// 	read(fd, t_read, BUFFER_SIZE);
// 	printf("read: %s", t_read);
// 	return (t_read);
// }

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
		printf("error res: %d\n", res);
	if (res == 0)
		printf("end of file. ret: %d\n", res);
	if (res > 0)
		printf("bytes read: %d\n", res);
	printf("read: %s\n", line);
	close(fd);
}

// int main()
// {
//     int    fd;
// 	char *line;
//     fd = open("tyger.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("failed to open file.\n");
// 		exit(1);
// 	}
//     for (int i = 0; i < 3; i++)
//     {
// 		line = get_next(fd);
// 		printf("\n i: %d the function output: %s\n", i, line);
//     }
// 	close(fd);
// }