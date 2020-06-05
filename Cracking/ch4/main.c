#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *flag(void)
{
	char *str = malloc(sizeof(char) * 8);

	str[0] = 'r';
	str[1] = 'e';
	str[2] = 'v';
	str[3] = '3';
	str[4] = 'r';
	str[5] = '5';
	str[6] = 'e';
	str[7] = '\0';
	return (str);
}
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
	if (strcmp(flag(), av[1]) == 0) {
		putchar('5');
		putchar('0');
		putchar('_');
		putchar('S');
		putchar('t');
		putchar('r');
		putchar('o');
		putchar('n');
		putchar('g');
	}
	return (0);
}
