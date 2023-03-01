/*
readline: Reads a line of input from the user, handling things like line editing and history.

rl_clear_history: Clears the history list maintained by readline. // rare use

rl_on_new_line: Tells readline that the cursor has moved to a new line. // rare use

rl_replace_line: Replaces the current line of input with a new line. // rare use

rl_redisplay: Updates the display after changes have been made to the input.

add_history: Adds a line to the history list maintained by readline.

printf: Formats and prints output to the console.

malloc: Allocates a block of memory on the heap.

free: Deallocates a block of memory on the heap.

write: Writes data to a file descriptor.

access: Checks whether a file exists and whether the user has permission to access it.

open: Opens a file and returns a file descriptor.

read: Reads data from a file descriptor.

close: Closes a file descriptor.

fork: Creates a new process by duplicating the calling process.

wait: Waits for a child process to exit.

waitpid: Waits for a specific child process to exit.

wait3: Similar to waitpid, but provides more information about the child process.

wait4: Similar to waitpid, but allows for specifying additional options.

signal: Sets a signal handler for a specific signal.

sigaction: Sets a signal handler for a specific signal, with more control over the behavior of the handler.

sigemptyset: Initializes an empty signal set.

sigaddset: Adds a signal to a signal set.

kill: Sends a signal to a process.

exit: Terminates the calling process.

getcwd: Gets the current working directory.

chdir: Changes the current working directory.

stat: Gets information about a file.

lstat: Gets information about a file, but doesn\'t follow symbolic links.

fstat: Gets information about a file descriptor.

unlink: Deletes a file.

execve: Replaces the current process with a new process specified by a file.

dup: Duplicates a file descriptor.

dup2: Duplicates a file descriptor and sets it to a specific value.

pipe: Creates a pipe for inter-process communication.

opendir: Opens a directory and returns a directory stream.

readdir: Reads a directory entry from a directory stream.

closedir: Closes a directory stream.

strerror: Gets a string describing an error code.

perror: Prints a string describing an error code to the console.

isatty: Determines whether a file descriptor is associated with a terminal.

ttyname: Gets the name of the terminal associated with a file descriptor.

ttyslot: Gets the slot number of the current terminal.

ioctl: Performs a control operation on a file descriptor.

getenv: Gets the value of an environment variable.

tcsetattr: Sets terminal attributes.

tcgetattr: Gets terminal attributes.

tgetent: Initializes the terminfo database.

tgetflag: Gets the value of a boolean capability in the terminfo database.

tgetnum: Gets the value of a numeric capability in the terminfo database.

tgetstr: Gets the value of a string capability in the terminfo database.

tgoto: Constructs a cursor movement string for the current terminal.

tputs: Writes a string of terminal control characters to the console.
*/