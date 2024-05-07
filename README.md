# 42-minishell

A long project at 42 in a group of two, the goal is to create  <br> 
a command interpreter that mimics the behavior of bash. <br> 

Minishell manages environment variables, launches programs and handles their return. <br> 
There are also have a number of built-in functions: <br> 

External functions accepted: <br>

 | function | lib |       prototype       | return | description |
| ------- | --------- | ----------------------------- | -------------| -------|
| readline | #include <stdio.h> <br> #include <readline/readline.h> <br> #include <readline/history.h>  |  char * readline (const char *prompt); | | reads a line from terminal | |
| rl_clear_history | | | | | 
| rl_on_new_line | | | | |
| rl_replace_line | | | | |
| rl_redisplay | | | | |
|  add_history | | | | |
| printf | #include <stdio.h> | int printf(const char *format, ...); | returns nbr of chars printed minus the null| | 
| malloc | | | | |
| free   | | | | |
| write  | | | | |
| access | | | | |
| open   | | | | |
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
| getcwd | | | | | 
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

### TODO

  Commands execution and 'simple' argument parsing 
 - [ ] /bin/ls should be the same as ls
 - [ ] ./exec should work

  History of command line
 - [ ] History (Arrow up, Arrow down)
 - [ ] line edit (Arrow right, Arrow left) echo

  Quote and double quotes (simple)
 - [ ] '\'ls -l\'' shouldn't be the same as 'ls -l' (no quotes)
 - [ ] 'ls -l' should be the same as 'ls        -l'
 - [ ] 'ls -l' should be the same as 'ls "-l"'
 - [ ] 'ls -l' should be the same as 'ls '-l''
 - [ ] 'ls -l' should not be the same as 'ls \'-l \''

  Multiple commands execution on single line
 - [ ] cmd1 ';' cmd2

  Quote and double quotes (hard)
 - [ ] nested quotes and double quotes
 - [ ] \\ character nullifies the quote end or start

  Built-ins (sorted by priority)(simple)
 - [ ] echo (with -n)
 - [ ] pwd (no args)
 - [ ] cd (handling of ~, '-', and no args)
 - [ ] exit (args aka return code otherwise last cmd exec otherwise 0)
 - [ ] env (-i, -u)
 - [ ] export
 - [ ] unset
  
  Redirection (simple)
 - [ ] '|' '>' '>>' '<' '>'
 - [ ] redirection simple with no duplicates of redirections or chaining
       ex :
       'ls > file' pipes the result of ls to file and truncates file
       'ls < file' pipes the contents of file to ls as stdin
       'ls | wc' pipes the result of ls to wc as stdin
       'ls >> file' pipes the result of ls to file and appends to file
       'ls > file' pipes stderr to file and prints stdout to stdout
       
  Variable substitution (simple)
 - [ ] $Field

  Subshell (simple if the rest is done)CTRL+z (SIGTSTP) (Bonus) echo
 - [ ] execute ( cmd ) in subshell (good test (cd))

  Signal handling (simple)
 - [ ] CTRL + C sigint
 - [ ] CTRL + D eof
 - [ ] CTRL + \ sigquit

  Redirection (hard)
 - [ ] any fd plus > or < or >>
 - [ ] redirect cmd to previous decl redirection
       e.g. >&fd redirect stdout to the same redirection as fd currently has.
       'ls > file >&1' pipes stdout to file and then pipes stderr to redirected stdout.
       'ls >&1 > file' pipes stderr to redirection of stdout and then pipes stdout to file.
 - [ ] redirections should be able to be chained
       'ls > file1 > file2' results in stdout being redirected to file2

  Variable substitution (hard)
 - [ ] single line variables
 - [ ] subshell substitution $( cmd1 )

  Signal handling (hard)
 - [ ] all other signals. (Bonus)
 - [ ] CTRL + Z sigtstp (Bonus)

  Norme
 - [ ] Norminette OK


<br>

### Author :bgoulard <br>
### Author : nrobinso <br>
