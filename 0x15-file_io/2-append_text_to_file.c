#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: The name of the file.
 * @text_content: The NULL-terminated string to add to the file.
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
int fd, write_len, append;
if (!filename)
return (-1);
fd = open(filename, O_WRONLY | O_APPEND);
if (fd == -1)
return (-1);
if (!text_content)
{
close(fd);
return (1);
}
append = 0;
while (text_content[append])
append++;
write_len = write(fd, text_content, append);
if (write_len == -1 || write_len != append)
{
close(fd);
return (-1);
}
close(fd);
return (1);
}
