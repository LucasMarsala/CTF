#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av, char **env)
{
	char *str = NULL;

	if (ac != 2) {
		printf("%s\n", "Program need only one argument !");
		return (1);
	}
	for (int i = 0; env[i]; ++i)
		if (strncmp(env[i], "LD_PRELOAD=", 10) == 0)
			return (1);
	if (av[1][0] == 'C' && av[1][3] == 'l' && av[1][1] == 'h' && av[1][4] == 'L' && av[1][2] == '4'
        && av[1][5] == 'e' && av[1][6] == 'n' && av[1][7] == 'G' && av[1][8] == '3' && strlen(av[1]) == 9)
		return (0);
    return (1);
}
