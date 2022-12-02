#include "shell.h"

int main(void){
        char *buff;
        size_t buffsize = 32;
        pid_t pid;
        int val;
        char **cmd;

        buff = malloc(sizeof(char) * buffsize);
        if (buff == NULL)
                return (0);
        while (1)
        {
                PRINTER("$ ");
                getline(&buff, &buffsize, stdin);
                cmd = split(buff, " ");
                pid = fork();
                if (pid == -1)
                        return -1;
                if (pid == 0)
                {

                        val = execve(cmd[0], cmd, NULL);
                        if (val == -1)
                                perror("Error:555");
                }
                else
                {
                        wait(NULL);
                        printf("After execve\n");
                        printf("hi %s", cmd[0]);
                }
                return (0);
        }
}
