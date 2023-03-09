#include "../mini_shell.h"

#define ARGS 10 

void handle(int signal)
{
	if (signal == SIGQUIT)
		exit(1);
}

int main(int ac, char **av, char **env)
{
	char *args[ARGS + 1];
	char *line; 
	pid_t pid;
	//fd dyal input o loutput
	int fd[2];
	char buf[256];
	int nbytes;
	char **path = ft_split(5+env[6], ':');
	int i = 0;
	int t = 0;
	signal(SIGQUIT,handle);
	signal(SIGINT,handle);
	while (1)
	{
		//readline ket9ra dak chi li t3taha fi terminalo ketrodo
		line = readline("shell> ");
		//add history ra ayna hiya meli ketla3 bi lashom ket3tak lcommand li derty 9bel
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
				cd(args[1]);
			else
			{
				if (ft_strchr(args[0], '/'))
				{
					printf("smile LLL");
					execv(args[0], args);
				}
				else
					while(execv(ft_strjoin(path[t], ft_strjoin("/", args[0])), args) == -1 && path[t])
						t++;
				printf("shell: command not found: %s\n",args[0]);
				exit(1);
			}
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
		i = 0;
	}
}
