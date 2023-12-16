#include "main.h"

#define MAX_COMMAND_LENGTH 100

/**
* execute_command - Executes the command
* @arg: program name
* @command: The shell command
* Return: the exit status of the command
*/

int execute_command(char *command, char *arg)
{
	pid_t pid = fork();
	/** Tokenize the command into arguments */
	char *args[MAX_COMMAND_LENGTH];
	char *delim = " ";
	char *token = strtok((char *)command, delim);
	int i = 0, status, exit_status = 0;
	(void)arg;

	if (pid < 0)
	{
		perror("fork failed");
	}
	else if (pid == 0)
	{
		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		args[i] = NULL;
		handle_command(command, args);
	}
	else
	{
		/** Parent process */
		wait(&status);
		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
		}
	}

	return (exit_status);
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
	int exit_status;
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 3);
		command = NULL;
		if (getline(&command, &stream_len, stdin) == -1)
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
			free(command);
			exit_status = 1;
			break;
		}
		/** Execute the command */
		command_cpy = malloc(_strcount(command) + 1);
		if (command_cpy == NULL)
		{
			perror("./hsh: Memory allocation error");
			return (-1);
		}
		strcpy(command_cpy, command);
		exit_status = execute_command(command_cpy, argv[0]);
		free(command_cpy);
		free(command);
	}
	return (exit_status);
}

/**
 * exit_fnc - exit from the shell
 *
 * @stat_code: The status code of the last command
 */

void exit_fnc(int stat_code)
{
	exit(stat_code);
}
