# 42-minishell

A long project at 42 in a group of two, the goal is to create  <br> 
a command interpreter that mimics the behavior of bash. <br> 

Minishell manages environment variables, launches programs and handles their return. <br> 
There are also have a number of built-in functions: <br> 

### TODO

  Commands execution and 'simple' argument parsing 
 - [ ] /bin/ls should be the same as ls
 - [ ] ./exec should work

  History of command line
 - [ ] History (Arrow up, Arrow down)
 - [ ] line edit (Arrow right, Arrow left)

  Quote and double quotes (simple)
 - [B] '\'ls -l\'' shouldn't be the same as 'ls -l' (no quotes)
 - [ ] 'ls -l' should be the same as 'ls        -l'
 - [ ] 'ls -l' should be the same as 'ls "-l"'
 - [ ] 'ls -l' should be the same as 'ls '-l''
 - [ ] 'ls -l' should not be the same as 'ls \'-l \''
CTRL+z (SIGTSTP) (Bonus)
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

  Subshell (simple if the rest is done)CTRL+z (SIGTSTP) (Bonus)
 - [ ] execute ( cmd ) in subshell (good test (cd))

  Signal handling (simple)
 - [ ] CTRL + C sigint
 - [ ] CTRL + D eof
 - [ ] CTRL + \ sigquit

  Redirection (hard)
 - [ ] any fd plus > or < or >>
 - [ ] redirect cmd to previous decl redirection
       e.g. >&fd redirect stdout to the same redirection as fd currently has.
       'ls > file 2>&1' pipes stdout to file and then pipes stderr to redirected stdout.
       'ls 2>&1 > file' pipes stderr to redirection of stdout and then pipes stdout to file.
 - [ ] redirections should be able to be chained
       'ls > file1 > file2' results in stdout being redirected to file2

  Variable substitution (hard)
 - [ ] single line variables
 - [ ] subshell substitution $( cmd1 )

  Signal handling (hard)
 - [ ] all other signals. (Bonus)
 - [ ] CTRL+z (SIGTSTP) (Bonus)

  Norme
 - [ ] Normeminette OK
