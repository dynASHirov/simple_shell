#include "shell.h"

/**
 * _execute - A function that executes a command.
 * @_command: The pointer to tokienized command
 * @_name: The name of the shell.
 * @_env: The pointer to the enviromental variables.
 * @_cicles: Number of executed cicles.
 * Return: Nothing.
 */

void _execute(char **_command, char *_name, char **_env, int _cicles)
{
	char **_pathways = NULL, *_full_path = NULL;
	struct stat _st;
	unsigned int _i = 0;

	if (_strcm_p(_command[0], "env") != 0)
		print_env(_env);
	if (_stat(_command[0], &_st) == 0)
	{
		if (execve(_command[0], _command, _env) < 0)
		{
			perror(_name);
			_free_exit(_command);
		}
	}
	else
	{
		_pathways = _getPAT_H(_env);
		while (_pathways[_i])
		{
			_full_path = _strca_t(_pathways[_i], _command[0]);
			_i++;
			if (_stat(_full_path, &_st) == 0)
			{
				if (execve(_full_path, _command, _env) < 0)
				{
					perror(_name);
					_free_dp(_pathways);
					_free_exit(_command);
				}
				return;
			}
		}
		_msgerror(_name, _cicles, _command);
		_free_dp(_pathways);
	}
}

/**
 * _print_env - A function that prints all enviromental variables.
 * @_env: The pointer to enviromental variables.
 * Return: Nothing.
 */

void _print_env(char **_env)
{
	size_t _i = 0, _len = 0;

	while (_env[_i])
	{
		_len = _strle_n(_env[_i]);
		write(STDOUT_FILENO, _env[_i], _len);
		write(STDOUT_FILENO, "\n", 1);
		_i++;
	}
}

/**
 * _getPAT_H - A function to gets the full value from.
 * enviromental variable PATH.
 * @_env: The pointer to enviromental variables.
 * Return: All tokenized pathways for commands.
 */

char **_getPAT_H(char **_env)
{
	char *_pathvalue = NULL, **_pathways = NULL;
	unsigned int _i = 0;

	_pathvalue = strtok(_env[_i], "=");
	while (_env[_i])
	{
		if (_strcmp(_pathvalue, "PATH"))
		{
			_pathvalue = strtok(NULL, "\n");
			_pathways = _tokening(_pathvalue, ":");
			return (_pathways);
		}
		_i++;
		_pathvalue = strtok(_env[_i], "=");
	}
	return (NULL);
}

/**
 * _msgerror - A function that prints message not found.
 * @_name: The name of the shell.
 * @_cicles: Number of cicles.
 * @_command: The pointer to tokenized command.
 * Return: Nothing.
 */

void _msgerror(char *_name, int _cicles, char **_command)
{
	char _c;

	_c = _cicles + '0';
	write(STDOUT_FILENO, _name, _strle_n(_name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &_c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, _command[0], _strle_n(_command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
