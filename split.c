#include "shell.h"
/**
 * get_absolute_path - function that read the path
 * @cmd: the commande
 */
void get_absolute_path(char **cmd)
{
	int i, j;
	char *path;
	char *PATH;
	char *bin = NULL;
	char **path_split = NULL;

	PATH = getenv("PATH");
	j = strlen(PATH);
	path = malloc(sizeof(char)*j);
	path = strdup(PATH);
	if (path == NULL) /*if the path NULL we will create one*/
		path = strdup("/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin:");
	/* if cmd isnt the path we will find it in the bunary with env path*/
	if (cmd[0][0] != '/' && strncmp(cmd[0], "./", 2) != 0)
	{
		/* split path for verif if found it*/
		path_split = split(path, ":");
		free(path);
		path = NULL;
		for (i = 0; path_split[i]; i++)
		{
			/* alloc len path + '//' + len  binaire + 1 for the '\0' */
			bin = calloc(sizeof(char),(strlen(path_split[i]) + 1 + strlen(cmd[0]) + 1));
			if (bin == NULL)
				break;
			strcat(bin, path_split[i]); /* concat path , the '//' and cmd */
			strcat(bin, "/");
			strcat(bin, cmd[0]);
			/* verf if the file exist and exit the loop if the acc=> 0 */
			if (access(bin, F_OK) == 0)
				break;
			/* free freee it */
			free(bin);
			bin = NULL;
		}
		for (i = 0; path_split[i]; i++)
		free(path_split[i]);
		/* replace cmd with  path or  NULL if cmd not found */
		free(cmd[0]);
		cmd[0] = bin;
	}
	else
	{
		free(path);
		path = NULL;
	}
}

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
void print_env(void)
{
	size_t c;
	int len;

	for (c = 0; environ[c] != NULL; c++)
	{
		len = strlen(environ[c]);
		write(1, environ[c], len);
		write(STDOUT_FILENO, "\n", 1);
	}

}

