# 0x0C. Sockets


## Objectives
What is a socket and how it is represented on a Linux/UNIX system  
What are the different types of sockets  
What are the different socket domains  
How to create a socket  
How to bind a socket to an address/port  
How to listen and accept incoming traffic  
How to connect to a remote application  
What is the the HTTP protocol  
How to create a simple HTTP server  


## Environment
<strong>OS:</strong> Ubuntu 14.04 LTS  
<strong>Style:</strong> [Betty](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) style  
<strong>Compiler:</strong> gcc 4.8.4 -Wall -Werror -Wextra -pedantic  


## Files
FILE | DESCRIPTION
----|----
[0. Listen](./0-server.c) | Program that opens an `IPv4/TCP` socket and listens to traffic on port `12345`
[1. Accept](./1-server.c) | Program that opens an `IPv4/TCP` socket and accepts an entering connection
[2. Client](./2-client.c) | Program that connects to a listening server
[3. Roger](./3-server.c) | Program that opens a socket, accepts an entering connection, prints the IP address of client, waits for and receives message from connected client
[4. REST API - The Request](./Makefile) | Opens socket, listens, accepts, waits, prints request, sends back response, closes connection

----

### Author
Thomas Graeff

