#Sorting Makefile
CC = gcc
CFLAGS = -g 

objects = sorting.o
sorting : $(objects)
	$(CC) $(CFLAGS) -o sorting $(objects)
$(objects) : sorting.c

mergesort : mergesort.o
	$(CC) $(CFLAGS) -o mergesort mergesort.o
mergesort.o : mergesort.c

quicksort : quicksort.o
	$(CC) $(CFLAGS) -o quicksort quicksort.o
quicksort.o : quicksort.c

.PHONY:clean
clean:
	rm *.o
