#include "shell.h"

void if_fun(char **cmd){
    	struct stat status;
        
    		if (cmd == NULL)
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
}
