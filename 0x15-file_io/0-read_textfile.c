#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
/**
 * read_textfile - Reads and prints a text file to the POSIX
 * standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 * Return: The actual number of letters read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t n_read, n_written;
char *buffer;
if (!filename)
{
dprintf(STDERR_FILENO, "read_textfile: No such file or directory\n");
return (0);
}
fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);
buffer = malloc(sizeof(char) * (letters));
if (!buffer)
return (0);
n_read = read(fd, buffer, letters);
n_written = write(STDOUT_FILENO, buffer, n_read);
close(fd);
free(buffer);
return (n_written);
}
