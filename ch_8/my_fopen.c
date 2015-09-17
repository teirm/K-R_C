#include <stdio.h>
#include <fcntl.h>
#include "syscalls.h"
#define PERMS 0666 /* RW for owner group others */

struct {
	unsigned int read	: 01;
	unsigned int write	: 02;
	unsigned int unbuf	: 04;
	unsigned int eof	: 010;
	unsigned int err	: 020;
} flags;



/* fopen: open fil,e return file ptr */
FILE *fopen(char *name, char *mode)
{
	int fd;
	FILE *fp;

	if (*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
		if ((fp->flag && (flags.read || flags.write)) == 0)
			break;		/* found free slot */
	if (fp >= _iob + OPEN_MAX)		/* no free slots */
		return NULL;

	if (*mode == 'w')
		fd = creat(name, PERMS);
	else if (*mode == 'a') {
		if ((fd = open(name, O_WRONLY, 0)) == -1)
			fd = creat(name, PERMS);
		lseek(fd, 0L, 2);
	} else
		fd = open(name, O_RDONLY, 0);
	if (fd == -1) 		/* couldn't access name */
		return NULL;
	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	fp->flag = (*mode == 'r') ? flags.read : flags.write;
	return fp;
}
