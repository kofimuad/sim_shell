#include "main.h"
/**
 * parse_cmd - parse and tokenize the command
 * @lineptr: the command typed in
 * Return: tokenized string.
 */

char *parse_cmd(char *lineptr)
{
	char *token;
	char **argv = NULL;
	char *delim = " \n";
	int num_token = 0;
	int i = 0;

	char *lineptr_cp = strdup(lineptr);

	if (!lineptr_cp)
		return (NULL);

	token = strtok(lineptr, delim);
	if (token != NULL)
	{
		num_token++;
		token = strtok(NULL, delim);
	}
	num_token++;

	argv = malloc(sizeof(char *) * num_token);

	if (!argv)
	{
		free(lineptr_cp);
		return (NULL);
	}
	token = strtok(lineptr_cp, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);

		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	return (*argv);
}
