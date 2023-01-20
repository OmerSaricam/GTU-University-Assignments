CC = g++

all: driver1 run1 driver2 run2

all2: driver2 run2

all1: driver1 run1

driver2: driver2.cpp tetromino.o tetris.o
	$(CC) -o exe2 driver2.cpp tetromino.o tetris.o

tetromino.o: tetromino.cpp tetromino.h tetris.h
	$(CC) -c tetromino.cpp

tetris.o: tetris.cpp tetromino.h tetris.h
	$(CC) -c tetris.cpp

run2:
	@./exe2
	
driver1: driver1.cpp tetromino.o tetris.o
	$(CC) -o exe1 driver1.cpp tetromino.o tetris.o

run1:
	@./exe1
		
clean:
	rm -f *.o exe1 exe2
