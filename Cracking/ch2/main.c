#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <complex.h>
#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <fenv.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stddef.h>
#include <stdbool.h>

char *hacker(char **str)
{
	for (int i = 0; (*str)[i]; ++i) {
		if ((*str)[i] == 'e')
			(*str)[i] = '3';
		if ((*str)[i] == 'a')
			(*str)[i] = '4';
	}
	return (*str);
}

int main(int ac, char **av)
{
	char *pass = NULL;

	if (2 < ac) {
		write(1, "Too many arguments\n", 19);
		return (1);
	} else if (1 == ac) {
		write(1, "Need one argument\n", 18);
		return (1);
	}
	pass = malloc(13);
	pass[0] = 'E';
	pass[1] = 'a';
	pass[2] = 's';
	pass[3] = 'y';
	pass[4] = '_';
	pass[5] = 'r';
	pass[6] = 'e';
	pass[7] = 'v';
	pass[8] = 'e';
	pass[9] = 'r';
	pass[10] = 's';
	pass[11] = 'e';
	pass[12] = '\0';
	if (0 == strcmp(av[1], hacker(&pass)))
		write(1, "You can validate the challenge using this password", 51);
	else {
		write(1, "Sorry, bad password\n", 20);
		return (1);
	}
	return (0);
}
