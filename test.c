#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MAX_ARGS 10 // maximum number of arguments in a command

int main(void)
{
    char *args[MAX_ARGS + 1]; // array to hold command and arguments
    char *line; // user input
    pid_t pid; // process id
    int fd[2]; // pipe file descriptor
    char buf[256]; // buffer to hold output from child process
    int nbytes; // number of bytes read from pipe

    while (1) {
        // read user input
        line = readline("shell> ");
        add_history(line);
        // tokenize input into command and arguments
        int i = 0;
        char *token = strtok(line, "\'\" \n");
        while (token != NULL && i < MAX_ARGS) {
            args[i++] = token;
            token = strtok(NULL, " \n");
        }
        args[i] = NULL;  

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        if (pipe(fd) == -1) {
            printf("Pipe failed\n");
            exit(1);
        }

        pid = fork();
        if (pid < 0) {
            printf("Fork failed\n");
            exit(1);
        } else if (pid == 0) {
            // child process
            close(fd[0]); // close unused read end of pipe
            dup2(fd[1], STDOUT_FILENO); // redirect standard output to pipe
            execvp(args[0], args);
            printf("Command not found\n");
            exit(1);
        } else {
            // parent process
            close(fd[1]); // close unused write end of pipe
            while ((nbytes = read(fd[0], buf, sizeof(buf))) > 0) {
                write(STDOUT_FILENO, buf, nbytes); // write output from child to standard output
            }
            close(fd[0]); // close read end of pipe
            wait(NULL); // wait for child to complete
        }

        // free memory used by readline
        free(line);
    }
}
