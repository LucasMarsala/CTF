#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av, char **env)
{
	char *str = NULL;

	if (ac != 2) {
		printf("%s\n", "program need one argument");
		return (1);
	}
	for (int i = 0; env[i]; ++i)
		if (strncmp(env[i], "LD_PRELOAD=", 10) == 0)
			return (1);
	if (av[1][0] == 'E' && av[1][3] == 't' && av[1][1] == 'p' && av[1][4] == '3' && av[1][2] == '1' && av[1][5] == 'c' && av[1][6] == 'h')
		return 0;
	else
			return 1;
	return (0);
}
