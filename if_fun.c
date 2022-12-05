#include "shell.h"

void if_fun(char **cmd)
{
	struct stat status;
	char *cd ;
	cd = *cmd;

	if (cmd == NULL)
		exit(EXIT_SUCCESS);
	if (strcmp(cmd[0], "exit") == 0)
	{
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	if (strcmp(cmd[0], "env") == 0)
	{
		free(cmd);
		print_env();
	}
	if (strcmp(cmd[0], "env") == 0)
	{
		free(cmd);
		print_env();
	}
	int changeDirectory(char* cd);
	if (stat(cmd[0], &status) != 0)
		get_absolute_path(cmd); /** get the path*/
}
