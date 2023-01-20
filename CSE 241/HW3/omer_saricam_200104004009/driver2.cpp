#include <iostream>
#include <vector>
#include <limits>
#include "tetromino.h"
#include "tetris.h"


using namespace std;
using namespace tetromino_namespace;
using namespace tetris_namespace;

int main(){
   

   int table_row;  
    do{
       cout<<endl<<"Enter the row number of table(bigger than 6): ";
       while(!(cin >> table_row)){
          cout << "Error, please try again." << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
       }    
    }while(table_row <= 6);


   int table_column;
    do{
       cout<<endl<<"Enter the column number of table(bigger than 2): ";
       while(!(cin >> table_column)){
           cout << "Error, please try again." << endl;
           cin.clear();
           cin.ignore(numeric_limits<streamsize>::max(), '\n');
       } 
    }while(table_column <= 2);       

   
   Tetris tetris_table(table_row,table_column);
   
   
   int tetro_object_size = 1;
   Tetromino* tetro_objects = new Tetromino[tetro_object_size]; 

   tetrominos shape_type;
   
   
   
	   int i;
	   auto tetro_object_num=0; //keeps the number of tetromino objects created
	   char input2;  //The cin command does not work with a variable in enum class. So I get the input as char data type.
	   do{
	      
	      while(1){ //This is how I get the input for error checking
	         cout<<endl<<"What is the tetromino type?: ";
	         cin>>input2;  
	      
	         if(input2 == 'I' ||  input2 == 'O' ||  input2 == 'T' ||  input2 == 'J' ||  input2 == 'L' ||  input2 == 'S' ||  input2 == 'Z' || input2 == 'Q' || input2 == 'R'){
	            
	            
	            if(input2 == 'Q') break;
	            
	            srand(time(0));
	            if(input2 == 'R'){ //random 

	               char array[] = {'I','O','T','J','L','S','Z'};
	               int num=rand()%7;
	               input2=array[num];	               
	            }
	            cout<< "\x1B[2J\x1B[H";

	            shape_type= static_cast<tetrominos>(input2);
	            cin.ignore(2,'\n');

	            if(tetro_object_num == tetro_object_size){ //Setting memory space allocated to dynamic tetro_objects array

	               tetro_object_size++;
	               Tetromino* temp_tetro_objects = new Tetromino[tetro_object_size];

	               for(int i=0; i<tetro_object_size-1; i++){
	                  temp_tetro_objects[i] = tetro_objects[i];
	               }

	               delete[] tetro_objects;
	               tetro_objects = new Tetromino[tetro_object_size];
	               for(int i=0; i<tetro_object_size-1; i++){
	                  tetro_objects[i] = temp_tetro_objects[i];
	               }
	               delete[] temp_tetro_objects;
	            }

	            tetro_objects[tetro_object_num] = Tetromino(shape_type,input2);

	            //cout<< "\x1B[2J\x1B[H";
		    char** temp_table= tetris_table.array_copy(tetris_table.get_table(),tetris_table.get_table_row(),tetris_table.get_table_column());
		    tetris_table += tetro_objects[tetro_object_num];
		    tetris_table.draw();
		    tetris_table.set_table(temp_table);

	            tetris_table.animate(tetro_objects[tetro_object_num]);
	            
	            tetro_object_num++;
	            
	            //The space allocated to the temp_table array is freed by destructors(Tetris destructor)
	            break;

	         }
	      
	         else{
	            cout<<endl<<"Input is not valid. Try again!";
	            cin.ignore(2,'\n');
	         }	      
	      }    	      
	   }while(input2 != 'Q'); 
	   
	   delete[] tetro_objects;         
   
                  
 
}

