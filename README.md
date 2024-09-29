# 42-minishell

A long project at 42 in a group of two, the goal is to create  <br> 
a command interpreter that mimics the behavior of bash. <br> 

Minishell manages environment variables, launches programs and handles their return. <br> 
There are also have a number of built-in functions: <br> 

### TODO

  Commands execution and 'simple' argument parsing 
 - [x] /bin/ls should be the same as ls
 - [x] ./exec should work

  History of command line
 - [x] History (Arrow up, Arrow down)
 - [x] line edit (Arrow right, Arrow left) echo

  Quote and double quotes (simple)
 - [x] '\'ls -l\'' shouldn't be the same as 'ls -l' (no quotes)
 - [x] 'ls -l' should be the same as 'ls        -l'
 - [x] 'ls -l' should be the same as 'ls "-l"'
 - [x] 'ls -l' should be the same as 'ls '-l''
 - [x] 'ls -l' should not be the same as 'ls \'-l \''

  Multiple commands execution on single line
 - [ ] cmd1 ';' cmd2   (not asked for in Mandatory or Bonus)

  Quote and double quotes (hard)
 - [x] nested quotes and double quotes
 - [x] \\ character nullifies the quote end or start

  Built-ins (sorted by priority)(simple)
 - [x] echo (with -n)
 - [x] pwd with no options or arguments
 - [x] cd (handling of ~, '-', and no args)
 - [x] exit (args aka return code otherwise last cmd exec otherwise 0)
 - [x] env with no options or arguments
 - [x] export with no options
 - [x] unset with no options
  
  Redirection (simple)
 - [x] '|' '>' '>>' '<' '>'
 - [x] redirection simple with no duplicates of redirections or chaining
       ex :
       'ls > file' pipes the result of ls to file and truncates file
       'ls < file' pipes the contents of file to ls as stdin
       'ls | wc' pipes the result of ls to wc as stdin
       'ls >> file' pipes the result of ls to file in appends mode
       'ls > file' pipes stdout to file and prints stdout to stdout
       
  Variable substitution (simple)
 - [x] $Field

  Subshell (simple if the rest is done)CTRL+z (SIGTSTP) (Bonus) echo
 - [x] execute ( cmd ) in subshell (good test (cd))

  Signal handling (simple)
 - [x] CTRL + C sigint (extra message - to be removed)
 - [X] CTRL + D eof
 - [x] CTRL + \ sigquit

  Redirection (hard)
 - [x] any fd plus > or < or >>
    - [x] redirections of stdout and stderr
        ex :
        'ls 2> file' pipes stderr to file
        'ls 2> file1 1> file2' pipes stderr to file1 and stdout to file2
 - [x] redirect cmd to previous decl redirection
       e.g. >&fd redirect stdout to the same redirection as fd currently has.
       'ls > file >&1' pipes stdout to file and then pipes stderr to redirected stdout.
       'ls >&1 > file' pipes stderr to redirection of stdout and then pipes stdout to file.
 - [x] redirections should be able to be chained
       'ls > file1 > file2' results in stdout being redirected to file2

  Variable substitution (hard)
 - [ ] single line variables 
    ex:
        'let a=5; echo $a' should print 5 even if a is declared on the same line
 - [ ] subshell substitution $( cmd1 )

  Signal handling (hard)
 - [ ] all other signals. (not asked for in Mandatory or Bonus)
 - [ ] CTRL + Z sigtstp  (not asked for in Mandatory or Bonus)

  Norme
 - [x] Norminette OK <br>
  Leak
 - [x] Valgrind OK
    - [x] on normal lines
    - [x] on error lines

<br>

Author : bgoulard <br>
Author : nrobinso <br>

External functions accepted: <br>


| function | include lib | prototype | return | description |
| ------- | --------- | ------------------------------------------------------------------------ | -------------| -------|
| rl_clear_history | <readline/readline.h> | void rl_clear_history(void); | none | clears the history list |
| rl_on_new_line | <readline/readline.h> | int rl_on_new_line(void); | 0 on success, -1 on error | informs the readline library that the cursor is on a new line |
| rl_replace_line | <readline/readline.h> | int rl_replace_line(const char *text, int clear_undo); | 0 on success, -1 on error | replaces the contents of the current line with text |
| rl_redisplay | <readline/readline.h> | void rl_redisplay(void); | none | redisplays the current line |
| add_history | <readline/readline.h> | void add_history(const char *line); | none | adds line to the history list |
| read | <unistd.h> | ssize_t read(int fd, void *buf, size_t count); | number of bytes read, or -1 on error | reads up to count bytes from file descriptor fd into the buffer starting at buf |
| close | <unistd.h> | int close(int fd); | 0 on success, -1 on error | closes a file descriptor |
| fork | <unistd.h> | pid_t fork(void); | child's PID to parent, 0 to child, or -1 on error | creates a new process by duplicating the calling process |
| wait | <sys/wait.h> | pid_t wait(int *wstatus); | PID of child that exited, or -1 on error | waits for a child process to change state |
| waitpid | <sys/wait.h> | pid_t waitpid(pid_t pid, int *wstatus, int options); | PID of child that exited, or -1 on error | waits for a specific child process to change state |
| wait3 | <sys/wait.h> | pid_t wait3(int *wstatus, int options, struct rusage *rusage); | PID of child that exited, or -1 on error | waits for a child process to change state and returns resource usage information |
| wait4 | <sys/wait.h> | pid_t wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage); | PID of child that exited, or -1 on error | waits for a specific child process to change state and returns resource usage information |
| signal | <signal.h> | sighandler_t signal(int signum, sighandler_t handler); | previous handler on success, SIG_ERR on error | sets a function to handle signal signum |
| sigaction | <signal.h> | int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact); | 0 on success, -1 on error | examines and changes a signal action |
| sigemptyset | <signal.h> | int sigemptyset(sigset_t *set); | 0 on success, -1 on error | initializes the signal set to exclude all defined signals |
| sigaddset | <signal.h> | int sigaddset(sigset_t *set, int signum); | 0 on success, -1 on error | adds a signal to a signal set |
| kill | <signal.h> | int kill(pid_t pid, int sig); | 0 on success, -1 on error | sends a signal to a process or a group of processes |
| exit | <stdlib.h> | void exit(int status); | none | causes normal process termination |
| chdir | <unistd.h> | int chdir(const char *path); | 0 on success, -1 on error | changes the current working directory |
| stat | <sys/stat.h> | int stat(const char *path, struct stat *buf); | 0 on success, -1 on error | gets file status |
| lstat | <sys/stat.h> | int lstat(const char *path, struct stat *buf); | 0 on success, -1 on error | gets file status, does not follow symbolic links |
| fstat | <sys/stat.h> | int fstat(int fd, struct stat *buf); | 0 on success, -1 on error | gets file status for an open file descriptor |
| unlink | <unistd.h> | int unlink(const char *pathname); | 0 on success, -1 on error | deletes a name from the filesystem |
| execve | <unistd.h> | int execve(const char *pathname, char *const argv[], char *const envp[]); | does not return on success, -1 on error | executes a program |
| dup | <unistd.h> | int dup(int oldfd); | new file descriptor, or -1 on error | duplicates a file descriptor |
| dup2 | <unistd.h> | int dup2(int oldfd, int newfd); | new file descriptor, or -1 on error | duplicates a file descriptor to a specific descriptor number |
| pipe | <unistd.h> | int pipe(int pipefd[2]); | 0 on success, -1 on error | creates a pipe |
| opendir | <dirent.h> | DIR *opendir(const char *name); | pointer to directory stream, or NULL on error | opens a directory stream |
| readdir | <dirent.h> | struct dirent *readdir(DIR *dirp); | pointer to directory entry, or NULL on error | reads a directory entry |
| closedir | <dirent.h> | int closedir(DIR *dirp); | 0 on success, -1 on error | closes a directory stream |
| strerror | <string.h> | char *strerror(int errnum); | pointer to error message string | returns a string describing the error code |
| perror | <stdio.h> | void perror(const char *s); | none | prints a descriptive error message to stderr |
| isatty | <unistd.h> | int isatty(int fd); | 1 if fd is an open file descriptor referring to a terminal, 0 otherwise | tests whether a file descriptor refers to a terminal |
| ttyname | <unistd.h> | char *ttyname(int fd); | pointer to terminal name, or NULL on error | returns the name of the terminal associated with a file descriptor |
| ttyslot | <unistd.h> | int ttyslot(void); | slot number, or -1 on error | returns the index of the current user's terminal in the utmp file |

