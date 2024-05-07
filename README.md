# 42-minishell

 File: minishell_scope.txt
───────┼──────────────────────────────────────────────────────────────────────────────
   1   │ ```txt
   2   │ :: MINISHELL SCOPE ::
   3   │ 
   4   │ bgoulard
   5   │ nrobinso
   6   │ 
   7   │ :: GOAL ::
   8   │ 
   9   │ Commands execution and 'simple' argument parsing
  10   │ - /bin/ls should be the same as ls
  11   │ - ./exec should work
  12   │  File: minishell_scope.txt
───────┼──────────────────────────────────────────────────────────────────────────────
   1   │ ```txt
   2   │ :: MINISHELL SCOPE ::
   3   │ 
   4   │ bgoulard
   5   │ nrobinso
   6   │ 
   7   │ :: GOAL ::
   8   │ 
   9   │ Commands execution and 'simple' argument parsing
  10   │ - /bin/ls should be the same as ls
  11   │ - ./exec should work
  12   │ 
  13   │ quote and double quotes (simple)
  14   │ - '\'ls -l\'' shouldn't be the same as 'ls -l' (no quotes)
  15   │ - 'ls -l' should be the same as 'ls        -l'
  16   │ - 'ls -l' should be the same as 'ls "-l"'
  17   │ - 'ls -l' should be the same as 'ls '-l''
  18   │ - 'ls -l' should not be the same as 'ls \'-l \''
  19   │ 
  20   │ Multiple commands execution on single line
  21   │ - cmd1 ';' cmd2
  22   │ 
  23   │ quote and double quotes (hard)
  24   │ - nested quotes and double quotes
  25   │ - \\ character nullifies the quote end or start
  26   │ 
  27   │ Built-ins (sorted by priority)(simple)
  28   │ - echo (with -n)
  29   │ - pwd (no args)
  30   │ - cd (handling of ~, '-', and no args)
  31   │ - exit (args aka return code otherwise last cmd exec otherwise 0)
  32   │ - env (-i, -u)
  33   │ - export
  34   │ - unset
  35   │ 
  36   │ Redirection (simple)
  37   │ - '|' '>' '>>' '<' '2>'
  38   │ - redirection simple with no duplicates of redirections or chaining
  39   │     a.k.a.
  40   │      'ls > file' pipes the result of ls to file and truncates file
  41   │      'ls < file' pipes the contents of file to ls as stdin
  42   │      'ls | wc' pipes the result of ls to wc as stdin
  43   │      'ls >> file' pipes the result of ls to file and appends to file
  44   │      'ls 2> file' pipes stderr to file and prints stdout to stdout
  45   │ 
  46   │ Variable substitution (simple)
  47   │ - $Field
:


  13   │ quote and double quotes (simple)
  14   │ - '\'ls -l\'' shouldn't be the same as 'ls -l' (no quotes)
  15   │ - 'ls -l' should be the same as 'ls        -l'
  16   │ - 'ls -l' should be the same as 'ls "-l"'
  17   │ - 'ls -l' should be the same as 'ls '-l''
  18   │ - 'ls -l' should not be the same as 'ls \'-l \''
  19   │ 
  20   │ Multiple commands execution on single line
  21   │ - cmd1 ';' cmd2
  22   │ 
  23   │ quote and double quotes (hard)
  24   │ - nested quotes and double quotes
  25   │ - \\ character nullifies the quote end or start
  26   │ 
  27   │ Built-ins (sorted by priority)(simple)
  28   │ - echo (with -n)
  29   │ - pwd (no args)
  30   │ - cd (handling of ~, '-', and no args)
  31   │ - exit (args aka return code otherwise last cmd exec otherwise 0)
  32   │ - env (-i, -u)
  33   │ - export
  34   │ - unset
  35   │ 
  36   │ Redirection (simple)
  37   │ - '|' '>' '>>' '<' '2>'
  38   │ - redirection simple with no duplicates of redirections or chaining
  39   │     a.k.a.
  40   │      'ls > file' pipes the result of ls to file and truncates file
  41   │      'ls < file' pipes the contents of file to ls as stdin
  42   │      'ls | wc' pipes the result of ls to wc as stdin
  43   │      'ls >> file' pipes the result of ls to file and appends to file
  44   │      'ls 2> file' pipes stderr to file and prints stdout to stdout
  45   │ 
  46   │ Variable substitution (simple)
  47   │ - $Field
:


