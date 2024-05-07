# 42-minishell

A long project at 42 in a group of two, the goal is to create 
a command interpreter that mimics the behavior of bash.

Minishell manages environment variables, launches programs and handles their return. 
There are also have a number of built-in functions:

for example :
cd, 
echo, 
env, 
exit, 
export, 
pwd,
unset.

and 
Signal handling :

- CTRL + C sigint
- CTRL + D eof
- CTRL + \ sigquit
