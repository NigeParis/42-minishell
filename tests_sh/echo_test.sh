#!/bin/bash --posix 

echo""
echo 1."echo "\"hello world\"
echo hello world
/usr/bin/echo hello world
echo 1."real bash cmd"
echo""

echo 2."echo" \"hello'        'world\"
echo hello        world
/usr/bin/echo hello         world
echo 2."real bash cmd"
echo""

echo 3. "echo" \"this test will work\"
echo this test will work
/usr/bin/echo this test will work
echo 3."real bash cmd"
echo""

echo 4. "echo" \"-n no line return....\"
echo -n no line return....
/usr/bin/echo -n no line return....
echo 4."real bash cmd"
echo""

echo 5. "echo" \"-nnnnnnnn lots of "-nnnnnnnmn"....\"
echo -nnnnnnnn lots of "-nnnnnnnmn"....
/usr/bin/echo -nnnnnnnn lots of "-nnnnnnnmn"....
echo 5."real bash cmd"
echo""

echo 6. "echo" \"\"
echo ""
/usr/bin/echo ""
echo 6. "real bash cmd"
echo""


echo 7. "echo"
echo
/usr/bin/echo
echo 7. "real bash cmd"
echo""

echo 8. "echo -n"
echo -n
/usr/bin/echo -n
echo 8. "real bash cmd"

echo 9. "echo -n"
echo -n
/usr/bin/echo -n
echo 9. "real bash cmd"
echo""

echo 10. "echo" \"-nnnnnnnxnnn  this is a test printed....\"
echo echo -nnnnnnnxnnn  this is a test printed....
/usr/bin/echo echo -nnnnnnnxnnn  this is a test printed....
echo 10. "real bash cmd"
echo""

echo 11. "echo" \"-n -nnnnnnnxnnn  this is a test printed....\"
echo -n -nnnnnnnxnnn  this is a test printed....
/usr/bin/echo -n -nnnnnnnxnnn  this is a test printed....
echo 11. "real bash cmd"
echo""

echo 12. "echo" \"--n -nnnnnnnxnnn  this is a test printed....\"
echo --n -nnnnnnnxnnn  this is a test printed....
/usr/bin/echo --n -nnnnnnnxnnn  this is a test printed....
echo 12. "real bash cmd"
echo""

echo 13. "echo" \"'$USER'\"
echo $USER
/usr/bin/echo $USER
echo 13. "real bash cmd"
echo""

echo 14. "echo" \"'$USER word'\"
echo $USER word
/usr/bin/echo $USER word
echo 14. "real bash cmd"
echo""

echo 14. "echo" \"'$USER $'\"
echo $USER $
/usr/bin/echo $USER $
echo 14. "real bash cmd"
echo""

echo 15. "echo" \"'$USER$' '| cat -e'\"
echo $USER$ | cat -e
/usr/bin/echo $USER$ | cat -e
echo 15. "real bash cmd"
echo""

echo 16. "echo" \"'$'\"
echo $
/usr/bin/echo $
echo 16. "real bash cmd"
echo""
