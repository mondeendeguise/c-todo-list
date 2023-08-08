CC=gcc
CFLAGS=-Wall

build: src/main.c
	$(CC) $(CFLAGS) -o taskmgr src/main.c src/task_list.c

clean: build
	rm taskmgr data
