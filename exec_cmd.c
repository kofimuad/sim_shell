#include "main.h"
/**
 * exec_cmd - executes command
 * @command: the command to be executed
 * Return: nothing
 */
void exec_cmd(char *command)
{
	char *full_path = get_loc(command); /* Resolve full path of the command */
	char *argv[2]; /* Will not initialize here but in code block */

	pid_t child_pid;
	char *envp[] = {NULL};

	if (!full_path)
	{
		perror("Command not found");
		return;
	}

	argv[0] = full_path;
	argv[1] = NULL;


	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(full_path, argv, envp) == -1)
		{
			perror("Execve error");
			exit(EXIT_FAILURE);
		}
	}
	else if (child_pid > 0)
	{
		wait(NULL); /* Wait for child process */
	}
	else
	{
		perror("Fork error");
	}
	free(full_path); /* Assuming get_loc dynamically allocates the path */
}
