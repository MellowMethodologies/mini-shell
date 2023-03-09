# ifndef _MINI_SHELL_H
# define _MINI_SHELL_H

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <termios.h>
#include <dirent.h>
#include <sys/stat.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <curses.h>

char path[1024];

typedef struct s_vars {
		int double_quotes;
		int single_quotes;
} t_vars;

size_t	ft_strlen(const char *str);
int		ft_printf(const char *format, ...);
void cd(char *str);

#endif