#include "shell.h"
/**
 * main - shell looping
 * Return: shel good
 */
int main(void)
{
	char *buff;
	size_t buffsize = 32;
	pid_t pid;
	int val;
	char **cmd;
	int status = 0;

	buff = malloc(sizeof(char) * buffsize);
	if (buff == NULL)
		return (0);
	while (1)
	{
		PRINTER("$ ");
		getline(&buff, &buffsize, stdin);
		cmd = split(buff, DELIM);
		if (strcmp(cmd[0], "exit") == 0)
		{
			free_array(cmd);
			exit(0);
		}
		pid = fork();
		if (pid == -1)
		{
			return (-1);
		}
		get_absolute_path(cmd);
		if (pid == 0)
		{

			val = execve(cmd[0], cmd, NULL);
			if (val == -1)
				perror("Error:555");
		}
		else
		{
			waitpid(pid, &status, 0);
			kill(pid, SIGTERM);
			free_array(cmd);
		}
	}
	free_buff(buff);
	exit(EXIT_SUCCESS);
	return (0);
}
