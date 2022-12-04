#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
extern char **environ;

#include <linux/limits.h>
#define PRINTER(c) (write(STDOUT_FILENO, c, strlen(c)))
#define DELIM " \t\r\n\a"
char **split(char *raw_cmd, char *limit);
void get_absolute_path(char **cmd);
void print_env(void);
void execmd(char **cmd);


#endif
