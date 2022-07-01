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
	printf("read: %s\n", line);
	res = read(fd, line, BUFFER_SIZE);
	if (res == -1)
		printf("error at reading: %d\n", res);
	if (res == 0)
		printf("end of file. ret: %d\n", res);
	if (res > 0)
		printf("bytes read: %d\n", res);
	printf("read: %s\n", line);
	close(fd);
	free(line);
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