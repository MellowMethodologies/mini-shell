 #include "../mini_shell.h"
 
char *parse()
{
	char *line = malloc(128); // we need to be able to increase the pointer
    char *origLine = line;
    fgets(line, 128, stdin);

    char command[20];
    sscanf(line, "%20s ", command);

    line = strchr(line, ' ');

    printf("The Command is: %s\n", command);

    unsigned argumentsCount = 0;
    char **arguments = malloc(sizeof(char *));

    while (1)
    {
        char arg[20];
        if (line && (sscanf(++line, "%20s", arg) == 1))
        {
            arguments[argumentsCount] = malloc(sizeof(char) * 20);
            strncpy(arguments[argumentsCount], arg, 20);

            argumentsCount++;

            arguments = realloc(arguments, sizeof(char *) * argumentsCount + 1);
            line = strchr(line, ' ');
        }
        else {
            break;
        }
}

 int main(int argc, char **argv) {

	char *cmdLine;
	char *info;
	(void)(argc);
	(void)(argv);
    while(1) {
       cmdLine = readline("shell >>");

       info  = parse(cmdLine);

       print_info(info);
    }

    free(info);
 }