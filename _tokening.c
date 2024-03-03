#include "shell.h"

/**
 * _tokening - A function that split and create a full string command.
 * @_s: The delimiter for strtok.
 * @_buffer: The pointer to input string.
 * Return: A string with full command.
 */

char **_tokening(char *_buffer, const char *_s)
{
	char *_token = NULL, **_commands = NULL;
	size_t _bufsize = 0;
	int _i = 0;

	if (_buffer == NULL)
		return (NULL);

	_bufsize = _strlen(_buffer);
	_commands = malloc((_bufsize + 1) * sizeof(char *));
	if (_commands == NULL)
	{
		perror("Unable to allocate buffer");
		free(_buffer);
		_free_dp(_commands);
		exit(EXIT_FAILURE);
	}

	_token = strtok(_buffer, _s);
	while (_token != NULL)
	{
		_commands[_i] = malloc(_strle_n(_token) + 1);
		if (_commands[_i] == NULL)
		{
			perror("Unable to allocate buffer");
			_free_dp(_commands);
			return (NULL);
		}
		_strcp_y(_commands[_i], _token);
		_token = strtok(NULL, _s);
		_i++;
	}
	_commands[_i] = NULL;
	return (_commands);
}
