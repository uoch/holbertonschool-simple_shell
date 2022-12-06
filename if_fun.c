#include "shell.h"

void if_fun(char **cmd)
{
	struct stat status;

	if (cmd == NULL)
	{
		exit(EXIT_SUCCESS);
	}
	if (strcmp(cmd[0], "exit") == 0)
	{
		freeArr(cmd);
		exit(EXIT_SUCCESS);
	}
	if (strcmp(cmd[0], "env") == 0)
	{
		print_env();
		freeArr(cmd);
	}
	if (stat(cmd[0], &status) != 0)
		bin(cmd); /** get the path*/
	if (cmd[0] == NULL)
		printf("Command not found\n");
	else
		execmd(cmd);
	freeArr(cmd);
}
