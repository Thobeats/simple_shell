#include "main.h"

/**
 * handle_command - Handle the commands before execution
 *
 * @command: The command to run
 * @args: The arguements involved
 *
 */

void handle_command(char *command, char **args)
{
	char *command_path;

	command_path = NULL;
	command = remove_space(command);

	if (_strcount(command) > 0)
	{
		command_path = get_location(command);
		if (command_path != NULL)
		{
			/** Execute the command */
			if (execve(command_path, args, environ) == -1)
			{
				perror(command_path);
				exit(2);
			}
		}
		free(command_path);
	}

	free(command);
}
