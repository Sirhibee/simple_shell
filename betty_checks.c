#include "shell.h"

/**
 * main - Entry point of the shell
 *
 * Return: Always 0 on success
 */
int main(void)
{
	display_prompt();

	return (0);
}

/**
 * display_prompt - Displays the shell prompt
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}
