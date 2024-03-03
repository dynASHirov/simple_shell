#include "shell.h"

/**
 * main - A function that runs our shell.
 * @_ac: The number of inputed arguments.
 * @_av: The pointer to array of inputed arguments.
 * @_env: The pointer to array of enviromental variables.
 * Return: Always 0.
 */
int main(int _ac, char **_av, char **_env)
{
	char *_buffer = NULL, **_command = NULL;
	size_t _buf_size = 0;
	ssize_t _chars_readed = 0;
	int _cicles = 0;
	(void)_ac;

	while (1)
	{
		_cicles++;
		_prompt();
		signal(SIGINT, _handle);
		_chars_readed = getline(&_buffer, &_buf_size, stdin);
		if (_chars_readed == EOF)
			_EO_F(_buffer);
		else if (*_buffer == '\n')
			free(_buffer);
		else
		{
			_buffer[_strle_n(_buffer) - 1] = '\0';
			_command = _tokening(_buffer, " \0");
			free(_buffer);
			if (_strcm_p(_command[0], "exit") != 0)
				_shell_exit(_command);
			else
				if (_strcm_p(_command[0], "cd") != 0)
					_change_dir(_command[1]);
			else
				_create_child(_command, _av[0], _env, _cicles);
		}
		fflush(stdin);
		_buffer = NULL, _buf_size = 0;
	}
	if (_chars_readed == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * _prompt - A function that prints the prompt
 * Return: Nothing.
 */
void _prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "Hell_Shell>> ", 13);
}


/**
 * _handle - A function to handle Ctr + C signal.
 * @signals: The signal to handle.
 * Return: Nothing.
 */

void _handle(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\nHell_Shell>> ", 14);
}


/**
 * _EO_F - A function that chaecks if buffer is EOF
 * @_buffer: The pointer to the input string.
 * Return: Nothing
 */
void _EO_F(char *_buffer)
{
	if (_buffer)
	{
		free(_buffer);
		_buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(_buffer);
	exit(EXIT_SUCCESS);
}


/**
 * _shell_exit - A function that exits the shell.
 * @_command: The pointer to tokenized command.
 * Return: Nothing.
 */
void _shell_exit(char **_command)
{
	int _sta_tus = 0;

	if (_command[1] == NULL)
	{
		_free_dp(_command);
		exit(EXIT_SUCCESS);
	}

	_sta_tus = _ato_i(_command[1]);
	_free_dp(_command);
	exit(_sta_tus);
}
