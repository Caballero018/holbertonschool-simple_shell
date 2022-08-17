![image](https://user-images.githubusercontent.com/106556798/184210844-03fd5274-8018-4764-bbb1-c4f654454d14.png)
# Proyect simple shell
## Description:
In this project what we will do is create a shell.
> ### What is a shell?
> Shell is the programming layer that understands and executes the commands that a user enters. On some systems, the shell is called a command interpreter. 

## Project Requirements (general)
* Allowed editors: ```vi```, ```vim```, ```emacs```.
* All your files will be compiled on Ubuntu 20.04 LTS using ```gcc```, using the options ```-Wall -Werror -Wextra -pedantic -std=gnu89```.
* All your files should end with a new line.
* A ```README.md``` file, at the root of the folder of the project is mandatory.
* Your code should use the ```Betty style```. It will be checked using ```betty-style.pl``` and ```betty-doc.pl```.
* Your shell should not have any memory leaks.
* No more than ```5 functions``` per file.
* All your header files should be include guarded.
* Use system calls only when you need to (why?).

## MORE info
> ### Output
* Unless specified otherwise, your program must have the exact same output as sh ```(/bin/sh)``` as well as the exact same error output.
* The only difference is when you print an error, the name of the program must be equivalent to your ```argv[0]``` (See below)
Example of error with sh:
```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```
Same error with your program hsh:
```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```
> ### List of allowed functions and system calls.

## Compilation
Your shell will be compiled this way:
> gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

___

## Steps to create the simple shell
1. We create the ```prompt``` (The indicator).
2. We create an ```infinite loop```.
3. We make a condition where we set the ```interactive``` and ```non-interactive``` mode, we use the ```satty()``` function.
4. We use getline to define the ```delimiter character```, which in this case is going to be the ```spaces```.
5. We split the command, using the ```strtok()``` function. We touch, better said, we divide the command, which in this case is ```separated by spaces```.
6. We verify if we are working in the shell that we have created.
7. We execute. We use the PATH and create a ```parent``` and ```child``` process via ```fork```.

<a href = 'https://www.github.com/Crisgrva'> <img width = '32px' align= 'center' src="https://raw.githubusercontent.com/rahulbanerjee26/githubAboutMeGenerator/main/icons/github.svg"/></a> [@Alejandro Caballero](https://github.com/Caballero018) | [@Juan García](https://github.com/JuanGarcia0418)

<a href = 'https://www.twitter.com/crisgrvc'> <img width = '32px' align= 'center' src="https://raw.githubusercontent.com/rahulbanerjee26/githubAboutMeGenerator/main/icons/twitter.svg"/></a> [@Alejandro](https://twitter.com/Alejand51178128) | [@Juan]()
