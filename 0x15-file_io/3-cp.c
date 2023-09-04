#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
/**
 * main - Copy the content of one file to another file.
 * @argc: The number of argument strings.
 * Return: 0 on success, or exit with the appropriate error code.
 */
int main(int argc, char *argv[])
{
int fd_form, fd_to, n_read, n_written;
char buffer[1024];
if (argc != 3)
{
dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
return (97);
}
fd_form = open(argv[1], O_RDONLY);
if (fd_form == -1)
{
dprintf(2, "Error: Can't read from file %s\n", argv[1]);
return (98);
}
fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
if (fd_to == -1)
{
dprintf(2, "Error: Can't write to %s\n", argv[2]);
close(fd_form);
return (99);
}
while ((n_read = read(fd_form, buffer, sizeof(buffer))) > 0)
{
n_written = write(fd_to, buffer, n_read);
if (fd_to == -1 || n_written != n_read)
{
dprintf(2, "Error: Can't write to %s\n", argv[2]);
close(fd_form);
close(fd_to);
return (99);
}
}
if (n_read == -1)
{
dprintf(2, "Error: Can't read from file %s\n", argv[1]);
close(fd_form);
close(fd_to);
return (98);
}
if (close(fd_form) == -1)
{
dprintf(2, "Error: Can't close fd %d\n", fd_form);
return (100);
}
if (close(fd_to) == -1)
{
dprintf(2, "Error: Can't close fd %d\n", fd_to);
return (100);
}
return (0);
}
