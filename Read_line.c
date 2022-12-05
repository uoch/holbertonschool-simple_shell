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
	while (1)
	{
		PRINTER("$ ");
		if (getline(&buff, &buffsize, stdin) == -1)
		{
			if (feof(stdin))
				exit(EXIT_SUCCESS);
			else
			{
				
				buff= NULL;
				perror("");
				exit(1);
			}
		}
		cmd = split(buff, DELIM);
		if_fun(cmd);
		execmd(cmd);
	}
	free(buff);
	exit(EXIT_SUCCESS);
	return (0);
}
