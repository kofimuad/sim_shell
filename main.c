#include "main.h"

int main(int ac, char **argv)
{
	char *prompt = "$ ", *lineptr = NULL, *lineptr_cp = NULL, *token;
	size_t n = 0;
	ssize_t nc_read;
	const char *delim = " \n";
	int num_token = 0, i;
	pid_t child_pid;

	/* declaring void variables */
	(void)ac;

	while (1)
	{
		write(1, prompt, strlen(prompt));
		nc_read = getline(&lineptr, &n, stdin);
		if (nc_read == -1)
		{
			perror("Error, exiting shell...\n");
			return (-1);
		}

		lineptr_cp = malloc(sizeof(char) * nc_read);
		if (lineptr_cp == NULL)
		{
			perror("malloc allocation failed");
			return (-1);
		}

		strcpy(lineptr_cp, lineptr);

		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			num_token++;
			token = strtok(NULL, delim);
		}
		num_token++;

		argv = malloc(sizeof(char *) * num_token);

		token = strtok(lineptr_cp, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("forking failed!");
		}
		if (child_pid == 0)
		{
			execmd(argv);
		}
		wait(NULL);
	}

	free(lineptr_cp);
	free(lineptr);

	return (0);
}
