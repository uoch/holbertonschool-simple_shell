#include "shell.h"

void execmd(char **cmd)
{

    int val;
    int status = 0;
    pid_t pid;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
    }
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
        free(cmd);
    }
}
