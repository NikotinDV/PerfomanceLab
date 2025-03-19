CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -std=c11

task1p = task1/task1.c
task2p = task2/task2.c
task3p = task3/task3.c
task4p = task4/task4.c

task1: task1.out
	./task1.out 5 4

task1.out: $(task1p)
	$(CC) $(CFLAGS) $^ -o task1.out 

task2: task2.out
	./task2.out task2/file1.txt task2/file2.txt

task2.out: $(task2p)
	$(CC) $(CFLAGS) $^ -o task2.out -lm

task3: task3.out
	./task3.out task3/tests.json task3/values.json task3/report.json

task3.out: $(task3p)
	$(CC) $(CFLAGS) $^ -o task3.out

task4: task4.out
	./task4.out task4/file.txt

task4.out: $(task4p)
	$(CC) $(CFLAGS) $^ -o task4.out

clean:
	rm -f *.out
