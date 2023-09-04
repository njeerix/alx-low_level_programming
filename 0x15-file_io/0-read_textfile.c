#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
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
if (filename == NULL)
{
perror("read_textfile");
return (0);
}
fd = open(filename, O_RDONLY);
if (fd == -1)
{
perror("read_textfile");
return (0);
}
buffer = (char *)malloc(sizeof(char) * letters);
if (buffer == NULL)
{
perror("read_textfile");
close(fd);
return (0);
}
n_read = read(fd, buffer, letters);
if (n_read == -1)
{
perror("read_textfile");
free(buffer);
close(fd);
return (0);
}
n_written = write(STDOUT_FILENO, buffer, n_read);
if (n_written == -1 || n_written != n_read)
{
perror("read_textfile");
free(buffer);
close(fd);
return (0);
}
free(buffer);
close(fd);
return (n_read);
}
