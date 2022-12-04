#include <sys/fcntl.h>
#include "zeGnl/get_next_line.h"
#include "stdio.h"
#include <string.h>
#if __has_include(<bsd/string.h>)
# include <bsd/string.h>
#endif
//#include <bsd/string.h>

int main() {
	printf("hello\n");

	int fd = open("empty", O_RDONLY);
	printf("filedescriptor: %d\n", fd);
	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);

	printf("executing first call\n");
	printf("1: |%s|\n", get_next_line(fd));
	printf("executing second call\n");
	printf("2: |%s|\n", get_next_line(fd));
	/*printf("3: |%s|\n", get_next_line(fd));
	printf("4: |%s|\n", get_next_line(fd));
	printf("5: |%s|\n", get_next_line(fd));
	printf("6: |%s|\n", get_next_line(fd));
	printf("7: |%s|\n", get_next_line(fd));*/

	/*int i = 0;
	char *res = malloc(2);
	strlcpy(res, "a", 2);
	while (res)
	{
		free(res);
		res = get_next_line(fd);
		if (res)
			printf("Line %d: |%s|\n", i, res);
		i ++;
	}
	free(res);*/

	return (0);
}