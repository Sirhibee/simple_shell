#include "shell.h"

/**
 * main - Entry point
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
    info_t info[] = {INFO_INIT};
    int file_descriptor = 2;  /* Default file descriptor for standard error */

    /* Example of using inline assembly to modify file_descriptor */
    asm ("mov %1, %0\n\t"
        "add $3, %0"
        : "=r" (file_descriptor)
        : "r" (file_descriptor));

    if (ac == 2)
    {
        file_descriptor = open(av[1], O_RDONLY);
        if (file_descriptor == -1)
        {
            if (errno == EACCES)
                exit(EXIT_FAILURE + 1);  /* 126: Permission denied */
            if (errno == ENOENT)
            {
                _eputs(av[0]);
                _eputs(": 0: Can't open ");
                _eputs(av[1]);
                _eputchar('\n');
                _eputchar(BUF_FLUSH);
                exit(EXIT_FAILURE + 2);  /* 127: Command not found */
            }
            return EXIT_FAILURE;
        }
        info->readfd = file_descriptor;
    }

    populate_env_list(info);
    read_history(info);
    hsh(info, av);

    return EXIT_SUCCESS;
}
