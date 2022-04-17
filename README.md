
# Epitech first year Minishell2

This project is an extension of the minishell1 project, I have put below the topics of both projects.

## Minishell1 subject

You have to program a UNIX command interpreter.
The interpreter is expected to display a prompt ( $> for example ) and then wait for you to write a command
line, which must be validated by a newline.
The prompt must be displayed again only after the command execution.
Only basic command lines are expected to executed; no pipes, redirections or any other advanced features.
The executables should be those found in the path, as indicated in the PATH variable.
If the executable cannot be found, you must display an error message and display the prompt again.
Errors must be dealt with and must display the appropriate message on the error output.
You must correctly handle the PATH and the environment (by copying and restoring the initial env).
You must implement the following builtins: cd, setenv, unsetenv, env, exit.
Your env builtin hasn’t to take any argument. Your unsetenv builtin hasn’t to support the “*” wildcard.

## Minishell2 subject
The goal of the project is to enrich your minishell1 project by adding semicolons (‘;’), pipes (‘|’), and the four
redirections (‘>’, ‘<’, ‘»’, ‘«’) management.



## Usage

### Build
```sh
make
```

### Run
```sh
./mysh
```


## Features 

|             Category            | Achievement |
|:-------------------------------:|:----------:|
|           Basic tests           |:heavy_check_mark:|
|          path handling          |:heavy_check_mark:|
|       setenv and unsetenv       |:heavy_check_mark:|
|            builtin cd           |:heavy_check_mark:|
| line formatting (space and tab) |:heavy_check_mark:|
|          error handling         |:heavy_check_mark:|
|            separator            |:heavy_check_mark:|
|           simple pipe           |:x:|
|          advanced pipe          |:x:|
|           redirection           |:heavy_check_mark:|
|       advanced redirection      |:heavy_check_mark:|
