#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * create_file - Creates a file with the specifies name and
 * writes content to it.
 * @filename: The name of the file to create.
 * @text_content: A NULL-terminated string to write to the
 * file.
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
int fd, len, write_len;
if (!filename)
return (-1);
fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
if (fd == -1)
return (-1);
if (!text_content)
{
close(fd);
return (1);
}
len = 0;
while (text_content[len])
len++;
write_len = write(fd, text_content, len);
if (write_len == -1 || write_len != len)
{
close(fd);
return (-1);
}
close(fd);
return (1);
}
