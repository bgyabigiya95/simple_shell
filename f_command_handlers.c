#include "shell.h"

/**
 * parse_user_input - Buidls an array of strings as arguments
 * @str_input: Command input given by the user
 * @delimiter: String od chars indicating the delimiters
 *
 * Return: Array of strings
 */
char **parse_user_input(char *str_input, char *delimiter)
{
	int i, args_count = 0;
	char **args;
	char *token, *tkn_ptr;
	char *str_copy;

	if (str_input == NULL)
		dispatch_error("Error while parsing the command\n");

	/* Count the number of arguments present in the input */
	args_count = count_args(str_input, delimiter);
	/* Allocate memory to hold eaach argument as a string */
	args = allocate_memory(sizeof(char *) * (args_count + 1));
	/* Store each argument as a string */
	str_copy = duplicate_string(str_input);
	tkn_ptr = str_copy;
	for (i = 0; i < args_count; i++)
	{
		token = _strtok(tkn_ptr, delimiter);
		if (token == NULL)
			break;
		tkn_ptr = NULL;
		/* store command as single string */
		args[i] = duplicate_string(token);
	}
	/* set the last element of array of arguments to NULL */
	args[i] = NULL;

	free(str_copy);

	return (args);
}

/**
 * count_args - Counts the number of arguments in a command string
 * @str_input: Command as a string
 * @delimiter: Delimiter by wich to separate the args
 *
 * Return: Number of arguments present in str_input
 */
int count_args(char *str_input, char *delimiter)
{
	char *tkn, *tkn_ptr;
	int count = 0;
	char *str_copy = duplicate_string(str_input);

	tkn_ptr = str_copy;
	while ((tkn = _strtok(tkn_ptr, delimiter)) != NULL)
	{
		count++;
		tkn_ptr = NULL;
	}

