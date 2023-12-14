#include "main.h"

#define MAX_COMMAND_LENGTH 100

/**
* execute_command - Executes the command
*
* @command: The shell command
*/

void execute_command(const char *command)
{
	pid_t pid = fork();
	/** Tokenize the command into arguments */
	char *args[MAX_COMMAND_LENGTH];
	char *token = strtok((char *)command, " ");
	int i = 0;

	if (pid < 0)
	{
		perror("fork failed");
	}
	else if (pid == 0)
	{
		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}

		/** Execute the command */
		if (execve(args[0], args, environ) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}

	}
	else
	{
		/** Parent process */
		wait(NULL);
	}
}


/**
* main - The Entry point of the shell
*
* Return: 0 on success
*
*/

int main(int argc, char *argv[])
{
	char *command;
	size_t stream_len = 0;
	size_t command_length;
	char *prgname = malloc(sizeof(char) * (_strcount(argv[0]) + 1));
	
	prgname = _strcpy(argv[0], prgname);
	(void)argc;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			_prompt(&prgname);
		if (getline(&command, &stream_len, stdin) == -1)
		{
			free(command);
			/** Handle end of file (Ctrl+D) */
			write(STDOUT_FILENO, "\nExiting simple shell.\n", 24);
			break;
		}

		/** Remove trailing newline character */
		command_length = _strcount(command);
		if (command_length > 0 && command[command_length - 1] == '\n')
		{
			command[command_length - 1] = '\0';
		}

		/** Check for the exit command */
		if (_strcmp(command, "exit") == 0)
		{
			write(STDOUT_FILENO, "Exiting simple shell.\n", 22);
			break;
		}

		/** Execute the command */
		execute_command(command);

	}

	return (0);
}
