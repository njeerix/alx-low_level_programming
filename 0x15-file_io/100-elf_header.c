#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
/**
* print_elf_header - Print information from the ELF header.
* @header: Pointer to the ELF header.
*/
void print_elf_header(Elf32_Ehdr *header)
{
int i;
printf("ELF Header:\n");
printf(" Magic:  ");
for (i = 0; i < EI_NIDENT; i++)
printf("%02x ", header->e_ident[i]);
printf("\n");
printf("  Class:  ");
switch (header->e_ident[EI_CLASS])
{
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown>\n");
}
printf("  Data:  ");
switch (header->e_ident[EI_DATA])
{
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown>\n");
}
printf("  Version: %d (current)\n", header->e_ident[EI_VERSION]);
printf("  OS/ABI:  ");
switch (header->e_ident[EI_OSABI])
{
case ELFOSABI_SYSV:
printf("UNIX - System V\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_ARM:
printf("UNIX - ARM\n");
break;
default:
printf("<unknown: %d>\n", header->e_ident[EI_OSABI]);
}
printf("  ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
printf("  Types:  ");
switch (header->e_type)
{
case ET_NONE:
printf("NONE (Unknown)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (core file)\n");
break;
default:
printf("<unknown>\n");
}
}
/**
* main - Entry point of the program
* @argc: The number of command-line arguments.
* @argv: An array of strings containing the arguments.
* Return: 0 on success, 1 on error.
*/
int main(int argc, char **argv)
{
int fd;
Elf32_Ehdr elf_header;
if (argc != 2)
{
fprintf(stderr, "Usage: %s <elf_file>\n", argv[0]);
return (1);
}
fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
perror("Error opening ELF file");
return (1);
}
if (read(fd, &elf_header, sizeof(Elf32_Ehdr)) != sizeof(Elf32_Ehdr))
{
perror("Error reading ELF header");
close(fd);
return (1);
}
print_elf_header(&elf_header);
close(fd);
return (0);
}
