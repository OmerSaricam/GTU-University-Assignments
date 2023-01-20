all: clear clean compile run

compile: main.c
	@echo "Compiling..."
	@gcc main.c -o main -lm
	
run:    
	@echo "Running the tests...."
	./main
	@echo
	@echo "Completed test..."
        
clean:  
	@echo "Removing compiled files...."
	@rm -f *.o
	@rm -f main
        
clear:
	@clear        
                  

        	
	
