#include "main.h"
/**
 * get_loc - gets location of exec. file
 * @command: command to execute
 * Return: string - (the location)
 */
char *get_loc(char *command)
{
	char *path = getenv("PATH"), *path_cp, *token, *cmd_path;
	struct stat st;

	path_cp = strdup(path);

	if (!path || !(path_cp))
		return (NULL);

	for (token = strtok(path_cp, ":"); token; token = strtok(NULL, ":"))
	{
		cmd_path = malloc(strlen(token) + strlen(command) + 2);
		if (cmd_path)
		{
			sprintf(cmd_path, "%s/%s", token, command);
			if (stat(cmd_path, &st) == 0)/* Command Found*/
			{
				free(path_cp);
				return (cmd_path);
			}
			free(cmd_path);
		}
	}
	free(path_cp);
	return (NULL);
}
