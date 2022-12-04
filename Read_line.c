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
	struct stat status;

	buff = malloc(sizeof(char) * buffsize);
	if (buff == NULL)
		return (0);
	while (1)
	{
		PRINTER("#cisfun$ ");
		getline(&buff, &buffsize, stdin);
		cmd = split(buff, DELIM);
		if (!cmd )
			exit(EXIT_SUCCESS);
		if (strcmp(cmd[0], "exit") == 0)
		{
			free(cmd);
			exit(0);
		}
		if (strcmp(cmd[0], "env") == 0)
		{
			free(cmd);
			print_env();
			exit(EXIT_SUCCESS);
		}
		if (stat(cmd[0], &status) != 0)
			get_absolute_path(cmd); /** get the path*/
		execmd(cmd);
	}

	exit(EXIT_SUCCESS);
	return (0);
}
