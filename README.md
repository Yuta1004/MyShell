# MyShell

## Build

```
$ make build-lib
$ make build
$ make run
```
or
```
$ make build-run
```
or
```
$ ./build.sh
```

## Features

- Default Commands
  - `cd`
  - `exit`
- Operator
  - `|`
  - `;`
  - `||`
  - `&&`

## Directories

- bin : Original commands such as help
- command : Functions for executing commands or successfully processing shell
- str : Original Library for process of string
- vector : Original Library which offer \"VECTOR\" data structure

## Usage

```
$ ./myshell_i17027
Hello nakagamiyuta(501)! (HomeDir: /homedir)
First, type './bin/help' to show some useful messages!

(0)[nakagamiyuta@localhost /path/to/C/MyShell] $ echo "Hello MyShell"
"Hello MyShell"

(0)[nakagamiyuta@localhost /path/to/C/MyShell] $ cd command

(0)[nakagamiyuta@localhost /path/to/C/MyShell/command] $ cat command.h
#ifndef MY_COMMAND_H
#define MY_COMMAND_H

#include <stdio.h>

#include "../vector/vector.h"

typedef enum ExecType ExecType;
enum ExecType {

~~~~~~~~~~~~~~

int change_directory(Command *argv);

#endif  // !MY_COMMAND_H

(0)[nakagamiyuta@localhost /path/to/C/MyShell/command] $ ls
Makefile	command.c	command.h	command.o	convert.c	convert.o	default_func.c	default_func.o	exec.c		exec.o		libcommand.o

(0)[nakagamiyuta@localhost /path/to/C/MyShell/command] $ cat command.h | wc -l
      40

(0)[nakagamiyuta@localhost /path/to/C/MyShell/command] $ cd command.c
Not a directory

(20)[nakagamiyuta@localhost /path/to/C/MyShell/command] $ exit
Bye...
```
