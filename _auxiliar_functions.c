#include "shell.h"

/**
 * _strcm_p - A funtion that compares two strings
 * @_s1: string 1
 * @_s2: string 2
 * Return: 1 if strings are the same, 0 if not
 */
int _strcm_p(char *_s1, char *_s2)
{
	unsigned int _i = 0;

	while (_s1[_i])
	{
		if (_s1[_i] != _s2[_i])
			return (0);
		_i++;
	}

	return (1);
}


/**
 * _strle_n - A function that finds the length of the string
 * @_s: The input string
 * Return: The length of the string
 */
unsigned int _strle_n(char *_s)
{
	unsigned int _len = 0;

	while (_s[_len])
		_len++;

	return (_len);
}


/**
 * _strcp_y - A function that copies a string to another string
 * @_dest: The pointer to the copyed string
 * @_src: The pointer to string to copy for
 * Return: A pointer to copied string
 */
char *_strcp_y(char *_dest, char *_src)
{
	char *_aux = _dest;

	while (*_src)
		*_dest++ = *_src++;
	*_dest = '\0';
	return (_aux);
}


/**
 * _strca_t - a function that concatenates two strings.
 * @_dest: an input string
 * @_src: an input string
 * Return: A pointer to the resulting string
 */
char *_strca_t(char *_dest, char *_src)
{
	char *_temp = _dest;

	while (*_dest)
		_dest++;

	*_dest++ = '/';
	while (*_src)
		*_dest++ = *_src++;
	return (_temp);
}


/**
 * _ato_i - a function that converts string to integer.
 * @_s: An input string.
 * Return: integer from conversion.
 */
int _ato_i(char *_s)
{
	int _sign = 1;
	unsigned int _total = 0;
	char _null_flag = 0;

	if (_s == NULL)
		return (0);
	while (*_s)
	{
		if (*_s == '-')
			_sign *= -1;
		if (*_s >= '0' && *_s <= '9')
		{
			_null_flag = 1;
			_total = _total * 10 + (*_s - '0');
		}
		else if (*_s < '0' || *_s > '9')
		{
			if (_null_flag == 1)
				break;
		}
		_s++;
	}
	if (_sign < 0)
		_total = (-1 * (_total));
	return (_total);
}
