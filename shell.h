#ifndef _SHELL_H_
#define _SHELL_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*==================================================*/
/*============     Shell_Init       ==============*/
/*==================================================*/

int main(int abc, char **avb, char **envb);
void prompts(void);
void handles(int signalss);
void _EOFs(char *buffers);
void shell_exits(char **commands);

/*==================================================*/
/*============     create_child       ==============*/
/*==================================================*/

void create_childs(char **commands, char *names, char **envs, int cicles);
int change_dir(const char *path);

/*==================================================*/
/*============        Execute       ==============*/
/*==================================================*/

void execute(char **command, char *name, char **env, int cicles);
void print_env(char **env);
char **_getPATH(char **env);
void msgerror(char *name, int cicles, char **command);

/*==================================================*/
/*============          Tokening      ==============*/
/*==================================================*/

char **tokening(char *buffer, const char *s);

/*==================================================*/
/*============     Free Memory      ==============*/
/*==================================================*/

void free_dp(char **command);
void free_exit(char **command);

/*==================================================*/
/*============  Auxiliar_Functions    ==============*/
/*==================================================*/

int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);

/*============ END      ==============*/

#endif /* _SHELL_H_ */
