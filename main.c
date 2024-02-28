#include "main.h"
/**
 * main - program starts here
 * @ac: argument count (not used)
 * @argv: argument vector (not used here)
 * Return: interger
 */
int main(int ac, char **argv)
{
	char *lineptr = NULL;
	size_t n = 0;
	(void)ac; /* Ignore unused parameter */
	(void)argv; /* Potentially unused in this context */

	while (read_cmd(&lineptr, &n) != -1)
	{
		char *command = parse_cmd(lineptr);

		if (command)
		{
			exec_cmd(command);
		}
	}
	free(lineptr);
	return (0);
}
