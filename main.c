#include "main.h"

#define MAX_COMMAND_LENGTH 100

/**
* execute_command - Executes the command
* @arg: program name
* @command: The shell command
*/

void execute_command(char *command, char *arg)
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
			perror(arg);
			exit(EXIT_FAILURE);
		}

		free(command);
		free(token);

	}
	else
	{
		/** Parent process */
		wait(NULL);
	}
}


/**
* main - The Entry point of the shell
* @argc: arg count
* @argv: arguements
* Return: 0 on success
*
*/

int main(int argc, char *argv[])
{
	char *command, *command_cpy;
	size_t stream_len = 0, command_length;
	ssize_t characters;
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 3);
		characters = getline(&command, &stream_len, stdin);
		if (characters == -1)
		{
			free(command);
			break;
		}
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
		command_cpy = malloc(sizeof(char) * characters);

		if (command_cpy == NULL)
		{
			perror("./hsh: Memory allocation error");
			return (-1);
		}
		command_cpy = _strcpy(command, command_cpy);
		execute_command(command_cpy, argv[0]);
	}
	return (0);
}
