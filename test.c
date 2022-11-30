#include <sys/fcntl.h>
#include "zeGnl/get_next_line.h"
#include "stdio.h"
#include <string.h>

int main() {
	printf("hello\n");

	int fd = open("nl", O_RDONLY);
	printf("filedescriptor: %d\n", fd);
	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);

	/*printf("1: |%s|\n", get_next_line(fd));
	printf("2: |%s|\n", get_next_line(fd));
	printf("3: |%s|\n", get_next_line(fd));
	printf("4: |%s|\n", get_next_line(fd));
	printf("5: |%s|\n", get_next_line(fd));
	printf("6: |%s|\n", get_next_line(fd));
	printf("7: |%s|\n", get_next_line(fd));*/

	int i = 0;
	char *res = malloc(2);
	strlcpy(res, "a", 2);
	while (res)
	{
		res = get_next_line(fd);
		if (res)
			printf("Line %d: |%s|\n", i, res);
		i ++;
	}

	return (0);
}