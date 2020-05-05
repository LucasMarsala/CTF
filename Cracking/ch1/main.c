#include <string.h>
#include <stdio.h>

int main(int ac, char **av)
{
	char *pass = "E4sy1est_th4n_th3_e4s1er_?";

	if (2 < ac) {
		printf("%s\n", "Too many argument");
		return (1);
	} else if (1 == ac) {
		printf("%s\n", "Need one argument");
		return (1);
	} else if (0 == strcmp(av[1], pass)) {
		printf("%s\n", "Congrats, you can validate the challenge using this password !");
		return (0);
	}
	return (0);
}
