#include "main.h"

void execmd(char **argv)
{
	char *command = NULL, *act_cmd = NULL;

	if (argv)
	{
		command = argv[0];

		act_cmd = get_loc(command);

		if (execve(act_cmd, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
