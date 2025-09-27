#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av) {
	char *pass = "E4sy1est_th4n_th3_e4s1er_?";

    if (ac > 2) {
        puts("Too many arguments");
        return EXIT_FAILURE;
    } else if (ac < 2) {
        puts("Need one argument");
        return EXIT_FAILURE;
    } else if (strcmp(av[1], pass) == 0) {
        puts("Congrats, you can validate the challenge using this password!");
        return EXIT_SUCCESS;
    }
    puts("Wrong password");
    return EXIT_FAILURE;
}
