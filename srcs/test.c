#include "../mini_shell.h"

#define ARGS 10 

void handle(int signal)
{
	if (signal == SIGQUIT)
		exit(1);
}

void free_tokens(t_token *lst)
{
	t_token *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next; 
		free(tmp ->value);
	}
		tmp = NULL;
}

int main(int ac, char **av, char **env)
{
	int p = 0;
	int a = 0;
	char *args[ARGS + 1];
	char *line; 
	pid_t pid;
	t_token lex;
	//fd dyal input o loutput
	int fd[2];
	char buf[256];
	int nbytes;
	while (ft_strnstr(env[p], "PATH", 4) == NULL)
		p++;
	while (ft_strnstr(env[a], "HOME", 4) == NULL)
		a++;
	char **path = ft_split(5 + env[p], ':');
	int i = 0;
	int t = 0;
	signal(SIGQUIT,handle);
	signal(SIGINT,handle);
	while (1)
	{
		lex.type = 0;
    			lex.value = NULL;
    			lex.next = NULL;
		line = readline("shell> ");
		if (line == NULL)
			break;
		lexer(ft_strtrim(line, " "), &lex);
		add_history(line);
		char *token = strtok(line, " \n");
		if (token == NULL)
			continue;
		while (token != NULL && i < ARGS)
		{
			args[i++] = token;
			token = strtok(NULL, " \n");
		}
		args[i] = NULL;  
		if (strcmp(args[0], "exit") == 0)
			break;
		if (pipe(fd) == -1)
		{
			printf("Pipe failed\n");
			continue;
		}
		pid = fork();
		if (pid < 0)
		{
			printf("Fork failed\n");
			exit(1);
		}
		else if (pid == 0)
		{
			close(fd[0]);
			dup2(fd[1], 1);
			if (ft_strncmp(args[0], "cd",  2) == 0)
				cd(args[1], ft_strchr(env[a], '/'));
			else
			{
				if (ft_strchr(args[0], '/'))
					execv(args[0], args);
				else
					while(execv(ft_strjoin(path[t], ft_strjoin("/", args[0])), args) == -1 && path[t])
						t++;
				printf("shell: command not found: %s\n",args[0]);
				exit(1);
			}
			close(fd[1]);
		}
		else
		{
			close(fd[1]);
			while ((nbytes = read(fd[0], buf, sizeof(buf))) > 0)
				write(1, buf, nbytes);
			close(fd[0]);
			wait(NULL);
		}
		free(line);
		free_tokens(&lex);
		i = 0;
	}
}