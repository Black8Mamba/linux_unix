#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "tlpi_hdr.h"
#include "error_functions.h"
void perror(const char *msg);

void main(void)
{
	int fd;
	fd = open("tmp/test3", O_RDONLY);
	char *p = NULL;
	if (fd == -1)
	{
		perror("open ");
		p = strerror(errno);
		printf("%s\n\n\n", p);
		errMsg("tmp/test3\n\n");
		errExit("tmp/test3\n\n");
		err_exit("tmp/test3\n\n");
		errExitEN(errno, "tmp/test3\n\n");
		exit(EXIT_FAILURE);
	} 
}

