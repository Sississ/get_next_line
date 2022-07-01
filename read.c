#include "get_next_line.h"

char	*get_next(int fd)
{
	char	*t_read;

	t_read = 0; 
	read(fd, t_read, BUFFER_SIZE);
	printf("read: %s", t_read);
	return (t_read);
}

int main()
{
    int    fd;
	char *line;
    fd = open("tyger.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("failed to open file.\n");
		exit(1);
	}
    for (int i = 0; i < 3; i++)
    {
		line = get_next(fd);
		printf("\n i: %d the function output: %s\n", i, line);
    }
	close(fd);
}