#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * main - Entry point
 * @argc: The number of arguments.
 * @argv: The array of arguments
 * Return: 0 on success, 97 for usage error, 98 for read error
 */
int main(int argc, char **argv)
{
int fd_form, fd_to, bytes_read, bytes_written;
char buffer[1024];
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
fd_form = open(argv[1], O_RDONLY);
if (fd_form == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
return (98);
}
fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRUSR
| S_IRGRP | S_IWGRP | S_IROTH);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(fd_form);
return (99);
}
while ((bytes_read = read(fd_form, buffer, sizeof(buffer))) > 0)
{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(fd_form);
close(fd_to);
return (99);
}
}
if (bytes_read == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
close(fd_form);
close(fd_to);
return (98);
}
if (close(fd_form) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_form);
return (100);
}
if (close(fd_to) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
return (100);
}
return (0);
}
