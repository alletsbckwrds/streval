# streval.h
I tried to recreate streval() from Ch shell ( https://www.softintegration.com/docs/ch/shell/ ), because system() does not return the command's output string.<br/>
But this has its differences from Ch's version (other than the syntax (this does not require the \` symbols to access the shell commands)).<br/>
The main difference is that the shell does not retain variables, so if you do something like streval("_var=\\"hello\\"") and then try to read it with streval("echo $_var"), you won't get anything.<br/>
EDIT: another big difference is that streval("1+1") will not return 2... There are other libraries that include evaluation for numerical expressions... 

## How to use
You need to include <stdlib.h> and <stdio.h> and "streval.h" of course.<br/>
Remember that if you want to see the output of something you need to use printf() (or cout if you wanna use C++)<br/>
In this example i used CERN's Root to have the most "Ch-like" experence. You can also use Cling, or just plain old compiled C/C++.<br/>
In this example i also used std::string because it's quicker, but the function actually returns a C string.
![example](examples/root.png)

## Return
This function returns a char* and takes a char* as input:<br/>
char* streval(char* in)

## Suggestions
If you want to work with variables, do not use "echo" but "printf", otherwise it will add a new line.<br/>
If anything goes wrong, the function will return NULL, so check for that.<br/>
STDERR is not caught, so if you need it, please use ".... 2>&1"

## Why am i doing this?
With MAC randomisation, nowadays Ch struggles to understand if your license is still valid. So i want an alternative.<br/>
(Also, Ch is super closed source).
