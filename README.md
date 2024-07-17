# 42-minishell

A long project at 42 in a group of two, the goal is to create  <br> 
a command interpreter that mimics the behavior of bash. <br> 

Minishell manages environment variables, launches programs and handles their return. <br> 
There are also have a number of built-in functions: <br> 

### TODO

  Commands execution and 'simple' argument parsing 
 - [x] /bin/ls should be the same as ls
 - [ ] ./exec should work

  History of command line
 - [x] History (Arrow up, Arrow down)
 - [x] line edit (Arrow right, Arrow left) echo

  Quote and double quotes (simple)
 - [ ] '\'ls -l\'' shouldn't be the same as 'ls -l' (no quotes)
 - [ ] 'ls -l' should be the same as 'ls        -l'
 - [ ] 'ls -l' should be the same as 'ls "-l"'
 - [ ] 'ls -l' should be the same as 'ls '-l''
 - [ ] 'ls -l' should not be the same as 'ls \'-l \''

  Multiple commands execution on single line
 - [ ] cmd1 ';' cmd2

  Quote and double quotes (hard)
 - [x] nested quotes and double quotes
 - [ ] \\ character nullifies the quote end or start

  Built-ins (sorted by priority)(simple)
 - [x] echo (with -n)
 - [x] pwd (no args)
 - [x] cd (handling of ~, '-', and no args)
 - [x] exit (args aka return code otherwise last cmd exec otherwise 0)
 - [ ] env (-i, -u)
 - [x] export
 - [x] unset
  
  Redirection (simple)
 - [ ] '|' '>' '>>' '<' '>'
 - [ ] redirection simple with no duplicates of redirections or chaining
       ex :
       'ls > file' pipes the result of ls to file and truncates file
       'ls < file' pipes the contents of file to ls as stdin
       'ls | wc' pipes the result of ls to wc as stdin
       'ls >> file' pipes the result of ls to file in appends mode
       'ls > file' pipes stdout to file and prints stdout to stdout
       
  Variable substitution (simple)
 - [ ] $Field

  Subshell (simple if the rest is done)CTRL+z (SIGTSTP) (Bonus) echo
 - [ ] execute ( cmd ) in subshell (good test (cd))

  Signal handling (simple)
 - [ ] CTRL + C sigint
 - [X] CTRL + D eof
 - [ ] CTRL + \ sigquit

  Redirection (hard)
 - [ ] any fd plus > or < or >>
    - [ ] redirections of stdout and stderr
        ex :
        'ls 2> file' pipes stderr to file
        'ls 2> file1 1> file2' pipes stderr to file1 and stdout to file2
 - [ ] redirect cmd to previous decl redirection
       e.g. >&fd redirect stdout to the same redirection as fd currently has.
       'ls > file >&1' pipes stdout to file and then pipes stderr to redirected stdout.
       'ls >&1 > file' pipes stderr to redirection of stdout and then pipes stdout to file.
 - [ ] redirections should be able to be chained
       'ls > file1 > file2' results in stdout being redirected to file2

  Variable substitution (hard)
 - [ ] single line variables 
    ex:
        'let a=5; echo $a' should print 5 even if a is declared on the same line
 - [ ] subshell substitution $( cmd1 )

  Signal handling (hard)
 - [ ] all other signals. (Bonus)
 - [ ] CTRL + Z sigtstp (Bonus)

  Norme
 - [ ] Norminette OK
  Leak
 - [ ] Valgrind OK
    - [ ] on normal lines
    - [ ] on error lines

<br>

Author :bgoulard <br>
Author : nrobinso <br>

External functions accepted: <br>

 | function | include lib |       prototype                                                              | return | description |
| ------- | --------- | ------------------------------------------------------------------------ | -------------| -------|
| readline | <stdio.h> <br> <readline/readline.h> <br> <readline/history.h>  |  char * readline (const char *prompt); | | reads a line from terminal | |
| rl_clear_history | | | | | 
| rl_on_new_line | | | | |
| rl_replace_line | | | | |
| rl_redisplay | | | | |
|  add_history | | | | |
| printf | <stdio.h> | int printf(const char *format, ...); | nbr of chars minus the null | | 
| malloc | <stdlib.h> | void *malloc(size_t size);| pointer to first byte |allocates size bytes of memory |
| free   | <stdlib.h> | void free(void *ptr);| no value. | frees the memory pointed to by ptr |
| write  | <unistd.h> | ssize_t write(int fildes, const void *buf, size_t nbyte);| nbytes written|writes nbytes from buf to file asso |
| access | <unistd.h> | int access(const char *pathname, int mode); |0:success -1:error | checks acces to file |
| open   |<sys/stat.h> <br> <fcntl.h> | int open(const char *path, int oflag, ... ); |fd or -1:fail | opens a file  |
| read   | | | | |
| close  | | | | |
| fork   | | | | |
| wait   | | | | |
| waitpid | | | | |
| wait3 | | | | |
| wait4 | | | | |
| signal | | | | |
| sigaction | | | | | 
| sigemptyset | | | | | 
| sigaddset | | | | |
| kill | | | | |
| exit | | | | |
| getcwd | <unistd.h> | char *getcwd(char *buf, size_t size); | ptr to str with path / NULL and ERRNO set | absolute pathname of the current working directory to the array | 
| chdir | | | | |
| stat | | | | |
| lstat | | | | |
| fstat | | | | |
| unlink | | | | |
| execve | | | | |
| dup | | | | |
| dup2 | | | | |
| pipe | | | | |
| opendir | | | | |
| readdir | | | | |
| closedir | | | | |
| strerror | | | | |
| perror | | | | |
| isatty | | | | |
| ttyname | | | | |
| ttyslot | | | | |
| ioctl | | | | |
| getenv | | | | |
| tcsetattr | | | | |
| tcgetattr | | | | |
| tgetent | | | | |
| tgetflag | | | | |
| tgetnum | | | | |
| tgetstr | | | | |
| tgoto | | | | |
| tputs | | | | |
