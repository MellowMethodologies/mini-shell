#include "../mini_shell.h"

#define ARGS 10 

int main(void)
{
	char *args[ARGS + 1];
	char *line; 
	pid_t pid;
	//fd dyal input o loutput
	int fd[2] = {0 , 1};
	char buf[256];
	int nbytes;
	int i = 0;

	while (1)
	{
		//readline ket9ra dak chi li t3taha fi terminalo ketrodo
		line = readline("shell> ");
		//add history ra ayna hiya meli ketla3 bi lashom ket3tak lcommand li derty 9bel
		add_history(line);
		char *token = strtok(line, " \n");
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
			exit(1);
		}
		char p[5] = "/bin/";
		char *t = ft_strjoin(p, args[0]);
		pid = fork();
		if (pid < 0)
		{
			printf("Fork failed\n");
			exit(1);
		}
		else if (pid == 0)
		{
			// close(fd[0]);
			dup2(fd[1], 1);
			//execute
			execv(t, args);
			printf("%s : Command not found\n",t);
			exit(1);
		}
		else
		{
			close(fd[1]);
			while ((nbytes = read(fd[0], buf, sizeof(buf))) > 0)
				write(1, buf, nbytes);
			close(fd[0]);
			wait(NULL);
		}

		free(t);
		free(line);
		i = 0;
	}
}
