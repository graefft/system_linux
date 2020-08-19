# SYSTEM_LINUX

Mostly C projects - attempts to recreate parts of standard programs like `ls`, `getline`, and `strace`  
Also exploring signals in C, CPython, and basic multithreading  
One folder devoted to x86 Assembly

![strace](images/strace_ss.png?raw=true "Strace")

DIRECTORY | DESCRIPTION
----|----
[0x00-ls](./0x00-ls) | Implement simple `ls` in C
[0x01-getline](./0x01-getline) | Implement `getline` in C
[0x03-proc_filesystem](./0x03-proc_filesystem) | Exploring `proc` filesystem and manipulating via `maps` and `mem`
[0x05-libasm](./0x05-libasm) | A few functions in x86 assembly, `strlen`, `memcpy`, `puts`
[0x06-signals](./0x06-signals) | Creating and retrieving signals using `SIGINT`, `SIGKILL`, etc.
[0x08-CPython](./0x08_CPython) | Using the `python.h` header to print information about PyObjects in C
[0x09-strace](./0x09-strace) | Using `ptrace` to trace programs and print info about their syscalls
[0x0A-multithreading](./0x0A-multithreading) | Work in progress: making threads and trying to implement Gaussian Blur in C
[0x0C-sockets](./0x0C-sockets) | Using `sys/socket.h` to create and bind sockets, listen, connect, and accept, send & recv, etc

### Author
Thomas Graeff
