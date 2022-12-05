#include "shell.h"
/**
 * main - shell looping
 * Return: shel good
 */

int main(void)
{
	char *buff;
	size_t buffsize = 32;
	char **cmd;

	buff = malloc(sizeof(char) * buffsize);
	if (buff == NULL)
	{
		return (0);
	}
	while (getline(&buff, &buffsize, stdin) > 0)
	{
		cmd = split(buff, DELIM);
		if_fun(cmd);
		execmd(cmd);
	}
	free(buff);
	exit(EXIT_SUCCESS);
	return (0);
}
