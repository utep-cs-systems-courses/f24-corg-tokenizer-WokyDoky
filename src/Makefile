# Do not use make file. Idk how to make makefiles. 


# compiler flags.  -g for debug, -O3 for optimization
CFLAGS=-g -O3

# default target
tokenizer: main.c tokenizer.c history.c
	gcc $(CFLAGS) main.c tokenizer.c history.c -o tokenizer

# object file target
tokenizer.o: main.c tokenizer.c history.c
	gcc -c $(CFLAGS) main.c tokenizer.c history.c

# clean target
clean:
	rm -f *.o tokenizer

