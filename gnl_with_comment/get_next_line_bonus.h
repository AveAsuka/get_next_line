#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h> // open
# include <stdlib.h> // free, malloc
# include <unistd.h>

# include <stdio.h> // для проверок, потом удалить

char *get_next_line(int fd);
void get_next_line_utils();

#endif