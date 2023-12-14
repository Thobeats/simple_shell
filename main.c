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
	char *delim = " ";
	char *token = strtok((char *)command, delim), *command_path;
	int i = 0, status;

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
		args[i] = NULL;

		command_path = NULL;
		command_path = get_location(command);
		printf("command path %s ", command_path);
		/** Execute the command */
		if (execve(command_path, args, environ) == -1)
		{
			perror(arg);
			exit(EXIT_FAILURE);
		}
		free(command_path);
	}
	else
	{
		/** Parent process */
		wait(&status);
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
		command = NULL;
		characters = getline(&command, &stream_len, stdin);
		if (characters == -1)
		{
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
		command_cpy = command;
		if (command_cpy == NULL)
		{
			perror("./hsh: Memory allocation error");
			return (-1);
		}
		execute_command(command_cpy, argv[0]);
		free(command_cpy);
		command = NULL;
		stream_len = 0;
	}
	return (0);
}
