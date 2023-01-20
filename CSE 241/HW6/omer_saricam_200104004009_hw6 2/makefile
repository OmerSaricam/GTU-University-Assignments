CC = g++

all: driver run

driver: driver.cpp pfarray.cpp pfarray.h
	$(CC) -o exe driver.cpp pfarray.cpp 

run:
	@./exe
		
clean:
	rm -f *.o exe
