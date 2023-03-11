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


typedef struct s_token{
	int		type;
	char	*value;
	struct s_token *next;
} t_token;

size_t	ft_strlen(const char *str);
int		ft_printf(const char *format, ...);
void	cd(char *str, char *home);
t_token	*ft_lstne(void *value, int type);
void	add_back(t_token **lst, t_token *new);
void lexer(char *str, t_token *lex);


#endif