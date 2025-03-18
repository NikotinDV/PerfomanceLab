CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -std=c11

task1p = task1/task1.c
task2p = task2/task2.c
task3p = task3/task3.c
task4p = task4/task4.c

task1: task1.out
	./task1.out

task1.out: $(task1p)
	$(CC) $(CFLAGS) $^ -o task1.out

task2: task2.out
	./task2.out

task2.out: $(task2p)
	$(CC) $(CFLAGS) $^ -o task2.out -lm

clean:
	rm -f *.out
