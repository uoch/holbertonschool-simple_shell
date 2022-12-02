#include "shell.h"
/**
 * split - function taht split the input in an array of string
 * @raw_cmd: the input
 * @limit: the delimenter
 * Return: array of string
 */
char **split(char *raw_cmd, char *limit)
{
	char *ptr = NULL;
	char **cmd = NULL;
	size_t idx = 0;

	ptr = strtok(raw_cmd, limit);

	while (ptr)
	{
		cmd = realloc(cmd, ((idx + 1) * sizeof(char *)));
		cmd[idx] = strdup(ptr);
		ptr = strtok(NULL, limit);
		++idx;
	}
	cmd = realloc(cmd, ((idx + 1) * sizeof(char *)));
	cmd[idx] = NULL;
	return (cmd);
}
