#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include "get_num.h"
static void gnFail(const char *fname, const char *msg, const char *arg, const char *name)
{
	fprintf(stderr, "%s error", fname);
	if (name != NULL)
		fprintf(stderr, "(in %s)", name);
	fprintf(stderr, ": %s\n", msg);
	if (arg != NULL && *arg != '\0')
		fprintf(stderr, "   offending text: %s\n", arg);

	exit(EXIT_FAILURE);
}

static long getNum(const char *fname, const char *arg, int flags, const char *name)
{
	long res;
	char *endptr;
	int base;
	
	if(arg == NULL || *arg == '\0')
		gnFail(fname, "null or empty string", arg, name);

	base = (flags & GN_ANY_BASE) ? 0 : (flags & CN_BASE_8) ? 8 : (flags & GN_BASE_16) ? 16 : 10;

	errno = 0;
	res = strtol(arg, &endptr, base);
	if (*endptr != '\0')
		gnFail(fname, "strtol() failed", arg, name);
	
	if ()
}
