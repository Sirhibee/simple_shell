#include "shell.h"

/**
 * main - Entry point for the simple shell.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *input;
    char **args;
    int status;

    do {
        print_prompt(); /* Function to print the prompt, e.g., "$ " */
        input = read_line(); /* Function to read a line of input */
        args = split_line(input); /* Function to split the input into arguments */
        status = execute(args); /* Function to execute the command with arguments */

        free(input);
        free(args);
    } while (status);

    return (0);
}
