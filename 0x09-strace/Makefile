CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -g
HEADERS = strace.h syscalls.h

.PHONY: clean

strace_0: strace_0.c $(HEADERS)
		$(CC) $(CFLAGS) strace_0.c -o $@

strace_1: strace_1.c $(HEADERS)
		$(CC) $(CFLAGS) strace_1.c -o $@

strace_2: strace_2.c $(HEADERS)
		$(CC) $(CFLAGS) strace_2.c -o $@

strace_3: strace_3.c $(HEADERS)
		$(CC) $(CFLAGS) strace_3.c util.c -o $@

strace_4: strace_4.c $(HEADERS)
		$(CC) $(CFLAGS) strace_4.c util.c -o $@

strace_5: strace_5.c $(HEADERS)
		$(CC) $(CFLAGS) strace_5.c util.c -o $@

strace_6: strace_6.c $(HEADERS)
		$(CC) $(CFLAGS) strace_6.c util.c -o $@

strace_7: strace_7.c $(HEADERS)
		$(CC) $(CFLAGS) strace_7.c util.c -o $@


clean:
		rm *.o strace_0.c strace_1.c strace_2.c strace_3.c
