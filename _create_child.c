#include "shell.h"

/**
 * _create_child - A function that creates a sub process.
 * @_command: The pointer to tokenized command
 * @_name: The pointer to the name of shell.
 * @_env: The pointer to the enviromental variables.
 * @_cicles: Number of executed cicles.
 * Return: Nothing.
 */
void _create_child(char **_command, char *_name, char **_env, int _cicles)
{
	int _pid = 0;
	int _status = 0;
	int _wait_error = 0;

	_pid = fork();
	if (_pid < 0)
	{
		perror("Error: ");
		_free_exit(_command);
	}
	else if (_pid == 0)
	{
		_execute(_command, _name, _env, _cicles);
		_free_dp(_command);
	}
	else
	{
		_wait_error = waitpid(_pid, &_status, 0);
		if (_wait_error < 0)
		{
			_free_exit(_command);
		}
		_free_dp(_command);
	}
}


/**
  * _change_dir - Afunction that changes working directory.
  * @_path: The new current working directory.
  * Return: 0 on success, -1 on failure.
  */
int _change_dir(const char *_path)
{
	char *_buf = NULL;
	size_t _size = 1024;

	if (_path == NULL)
		_path = getcwd(_buf, _size);
	if (chdir(_path) == -1)
	{
		perror(_path);
		return (98);
	}
	return (1);
}
