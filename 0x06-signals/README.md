# 0x06. C - Signals

## About
Solved tasks from Holberton School's Linux Programming curriculum

----

### Description
What is a signal?  
Why do they exist?  
When are they delivered and by whom?  
How to set up a handler for a signal  
How to send signals  
What signals can't be caught  

----

### Requirements
* <b>OS:</b>Ubuntu 14.04 LTS  
* <b>Compiler:</b>gcc 4.8.4 (-Wall -Werror -Wextra -pedantic)
* <b>Style:</b>[Betty code style](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl)

----

### Files
FILE | DESCRIPTION
----|----
[signals.h](./signals.h) | Header file for project
[0. Handle Signal](./0-handle_signal.c) | Function that sets a handler for the signal `SIGINT`
[1. Current Handler - Signal](./1-current_handler_signal.c) | Function that retrieves the current handler of the signal `SIGINT`
[2. Gotta Catch Them All](./2-handle_sigaction.c) | Function that sets a handler for the signal `SIGINT` where `<signum>` must be replaced with the signal number that was caught
[3. Current Handler - Sigaction](./3-current_handler_sigaction.c) | Function that retrieves the current handler of the signal `SIGINT`
[4. Who Said That?!](./4-trace_signal_sender.c) | Function that defines a handler for the signal `SIGQUIT`
[5. Description](./5-signal_describe.c) | Program that prints a description of a given signal
[6. Catch a Single Time](./6-suspend.c) | Program that sets a handler for the signal `SIGINT` and exits right after the signal is received and handled
[7. Sending a Signal](./7-signal_send.c) | Program that sends the signal `SIGINT` to a process given its PID
[8. Sending a Signal in a Shell](./8-signal_send.sh) | `sh` script that sends the signal `SIGQUIT` to a process given its PID
[9. Catch with sh](./9-handle_signal.sh) | `sh` script that sets a handler for the signals `SIGABRT`, `SIGIO`, and `SIGTERM`
[10. Does it Exist?](./10-pid_exist.c) | Function that tests if a process exists given its PID
[11. Blog Post](./) | Blog post about signals

--------------

### Author
Thomas Graeff
`
