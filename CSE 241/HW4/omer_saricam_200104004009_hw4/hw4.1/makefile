CC = g++

all: driver run

driver: driver.cpp dayofyearset.cpp dayofyearset.h
	$(CC) -o exe driver.cpp dayofyearset.cpp 

run:
	@./exe
		
clean:
	rm -f *.o exe
