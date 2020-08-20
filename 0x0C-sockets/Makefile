CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

TASK0 = todo_api_0
TASK1 = todo_api_1
TASK2 = todo_api_2

$(TASK0): $(TASK0).c sockets_http.h server.c
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: todo_api_0 clean

clean:
	rm $(TASK0) $(TASK1) $(TASK2)

betty:
	betty *.c *.h
