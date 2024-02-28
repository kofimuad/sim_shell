#include "main.h"
/**
 * read_cmd - gets the line typed
 * @lineptr: stores the line typed
 * @n: size allocated to store the command
 * Return: command read
 */
ssize_t read_cmd(char **lineptr, size_t *n)
{
	char *prompt = "$ ";

	write(1, prompt, strlen(prompt));
	return (getline(lineptr, n, stdin));
}
