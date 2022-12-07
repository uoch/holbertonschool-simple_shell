#include "shell.h"
/**
 * main - shell looping
 * Return: shell good
 */

int main(void)
{
	char *buff = NULL;
	size_t buffsize = 1;
	char **cmd;

	buff = malloc(sizeof(char) * buffsize);
	signal(SIGINT, SIG_N);
	if (buff == NULL)
	{
		perror("fault");
		return (EXIT_FAILURE);
	}
	while (getline(&buff, &buffsize, stdin) > 0)
	{
		cmd = split(buff, DELIM);
		if_fun(cmd);
	}
	free(buff);
	exit(EXIT_SUCCESS);
	return (0);
}
