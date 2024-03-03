#include "shell.h"

/**
 * _free_dp - A function that frees all the memory allocated for command.
 * @_command: The pointer to allocated memory to free.
 * Return: Nothing.
 */
void _free_dp(char **_command)
{
	size_t _i = 0;

	if (_command == NULL)
		return;

	while (_command[_i])
	{
		free(_command[_i]);
		_i++;
	}

	if (_command[_i] == NULL)
		free(_command[_i]);
	free(_command);
}


/**
 * _free_exit - A function that frees all the memory allocated and exit.
 * @_command: The pointer to allocated command memory to free.
 * Return: Nothing.
 */
void _free_exit(char **_command)
{
	size_t _i = 0;

	if (_command == NULL)
		return;

	while (_command[_i])
	{
		free(_command[_i]);
		_i++;
	}

	if (_command[_i] == NULL)
		free(_command[_i]);
	free(_command);
	exit(EXIT_FAILURE);
}
