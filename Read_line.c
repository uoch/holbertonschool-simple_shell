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
		return (0);
	while (isatty(STDIN_FILENO))
	{
		isatty(STDIN_FILENO);
		PRINTER("$ ");
		getline(&buff, &buffsize, stdin);
		cmd = split(buff, DELIM);
		if_fun(cmd);
		execmd(cmd);
	}

	exit(EXIT_SUCCESS);
	return (0);
}
