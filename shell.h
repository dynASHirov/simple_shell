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

int main(int _ac, char **_av, char **_env);
void _prompt(void);
void _handle(int signals);
void _EO_F(char *_buffer);
void _shell_exit(char **_command_);

/*==================================================*/
/*============     create_child       ==============*/
/*==================================================*/

void _create_child(char **_command, char *_name, char **_env, int _cicles);
int _change_dir(const char *_path);

/*==================================================*/
/*============        Execute       ==============*/
/*==================================================*/

void _execute(char **_command, char *_name, char **_env, int _cicles);
void _print_env(char **_env);
char **_getPAT_H(char **_env);
void _msgerror(char *_name, int _cicles, char **_command);

/*==================================================*/
/*============          Tokening      ==============*/
/*==================================================*/

char **_tokening(char *_buffer, const char *_s);

/*==================================================*/
/*============     Free Memory      ==============*/
/*==================================================*/

void _free_dp(char **_command);
void _free_exit(char **_command);

/*==================================================*/
/*============  Auxiliar_Functions    ==============*/
/*==================================================*/

int _strcm_p(char *_s1, char *_s2);
unsigned int _strle_n(char *_s);
char *_strcp_y(char *_dest, char *_src);
int _ato_i(char *_s);
char *_strca_t(char *_dest, char *_src);

/*============ END      ==============*/

#endif /* _SHELL_H_ */
