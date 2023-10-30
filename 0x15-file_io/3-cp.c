#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * open_file - Opensa file with specified flags and mode.
 * @filename: the name of the file to open.
 * @flags: flags to use when opening the file.
 * @mode: mode to set when creating a new file.
 * Return: the file descriptor or -1 on error.
 */
int open_file(const char *filename, int flags, mode_t mode)
{
int fd = open(filename, flags, mode);
if (fd == -1)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
}
return (fd);
}
/**
 * copy_file - copies the content of one file to another.
 * @fd_from: file descriptor of the source file.
 * @fd_to: file descriptor of the destination file.
 * Return: 0 on success, 1 on error.
 */
int copy_file(int fd_from, int fd_to)
{
ssize_t bytes_read;
ssize_t bytes_written;
char buffer[1024];
while ((bytes_read = read(fd_from, buffer, sizeof(buffer)) > 0))
{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
{
fprintf(stderr, "Error: Can't write to file\n");
return (1);
}
}
if (bytes_read == -1)
{
fprintf(stderr, "Error: Can't read from file\n");
return (1);
}
return (0);
}
/**
* main - Entry point
* @argc: The number of arguments.
* @argv: The array of arguments
* Return: 0 on success, 97 for usage error, 98 for read error
*/
int main(int argc, char **argv)
{
int copy_result;
int fd_from, fd_to;
if (argc != 3)
{
fprintf(stderr, "Usage: cp file_from file_to\n");
return (97);
}
fd_from = open(argv[1], O_RDONLY, 0);
if (fd_from == -1)
{
return (98);
}
fd_to = open_file(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
S_IRUSR | S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IROTH);
if (fd_to == -1)
{
close(fd_from);
return (99);
}
copy_result = copy_file(fd_from, fd_to);
if (close(fd_from) == -1)
{
fprintf(stderr, "Error: Can't close fd %d\n", fd_from);
return (100);
}
if (close(fd_to) == -1)
{
fprintf(stderr, "Error: Can't close fd %d\n", fd_to);
return (100);
}
return (copy_result);
}
