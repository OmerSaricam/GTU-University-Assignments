#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <string>
#include <limits>
#include <unistd.h>
#include "tetromino.h"
#include "tetris.h"

using namespace std;
using namespace tetromino_namespace;
using namespace tetris_namespace;

class Test{


   public:
      
      
      void get_our_tetroTest(){
         
         cout<<endl<<"---The get_our_tetro method is being tested. We will generate S tetrmonino,then we get it by this method."<<endl<<endl;
         
         Tetromino t1(tetrominos::S,'S');
         
         char** copy = new char*[2];
         copy[0] = new char[3];
         copy[1] = new char[3];
         
         copy = t1.get_our_tetro();
         
         for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
               cout<<copy[i][j];
            }
            cout<<endl;
         }
         
         cout<<endl<<"Process is successful";
         //The area allocated to the 2d copy array is deleted in the destructor.         
      }
      
      void get_tetro_rowTest(){
         
         Tetromino t1(tetrominos::L,'L');
         
         cout<<endl<<"---The get_tetro_row method is being tested. For L tetromino: "<<t1.get_tetro_row();
         
         cout<<endl<<"Process is successful";   
         
      }
      
      void get_tetro_columnTest(){
         
         Tetromino t1(tetrominos::L,'L');
         
         cout<<endl<<"---The get_tetro_column method is being tested. For L tetromino: "<<t1.get_tetro_column();
         
         cout<<endl<<"Process is successful";
      }
      
      void get_letterTest(){
      
         Tetromino t1(tetrominos::L,'T');
         
         cout<<endl<<"---The get_letter method is being tested. For T tetromino: "<<t1.get_letter();
         
         cout<<endl<<"Process is successful";
      }
      
      void tetrominoConstructorTest(){
      
         cout<<endl<<"---Tetromino constructor being tested: ";
         
         Tetromino t1(tetrominos::S,'S');
         
         cout<<endl<<"Tetromino has been successfully created.";
      }
      
      void printTest(){
      
         cout<<endl<<"---The print method is being tested. The S tetromino will be printed on the screen: ";
         
         Tetromino t1(tetrominos::S,'S');
         
         t1.print();
         
         cout<<endl<<"Successfully printed to the screen";
      }

      void rotateTest(){
      
         cout<<endl<<"---The rotate method is being tested. The tetromino will be rotated counterclockwise: ";
         
         Tetromino t1(tetrominos::S,'S');
         
         t1.rotate(1);
         
         t1.print();
         
         cout<<endl<<"Successfully rotated";
      }
      
      
      void assignment_operatorTest(){
      
         cout<<endl<<"---The assignment operator overloading (=) is being tested. We will create a T tetromino. Next we will create another object of type Tetromino and assign it T tetromino.";
                  
         Tetromino t1(tetrominos::T,'T');
         
         cout<<endl<<"The Tetromino which was assigned T tetromino to it: ";
         Tetromino t2 ;
         t2 = t1;
         t2.print();
         
         cout<<endl<<"Assignment successful"; 
         
      }
      
      
/*
      
      void tetrisConstructorTest(){
         
         cout<<endl<<"---tetris Constructor is being tested. A table with 10 rows and 20 columns will be created: ";
         
         Tetris tetris(10,20);
         
         tetris.draw();
         
         cout<<endl<<"Process is successful";
      }
      
      void addTest(){
      
         cout<<endl<<"---The add function is being tested. T tetromino will be put in the 10x10 table: ";
         
         Tetris tetris(10,10);
         
         Tetromino t1(tetrominos::T,'T');
         
         tetris.add(t1);  
         
         tetris.draw();
      }
      
      void position_ctrlTest(){
      
         cout<<endl<<"---Checking position_ctrl in Tetris: A table of 10 rows and 10 columns will be created and it will be checked whether the L tetromino matches the table: ";
         
         Tetromino t1(tetrominos::L,'L');
         
         Tetris tetris(10,10);
        
         
         if(tetris.position_ctrl(t1,3,0) == 1){
            cout<<endl<<"position_ctrlTest correctly returned 1";
         }
	  
	 else cout<<endl<<"position_ctrlTest returned incorrect results.";          
      }
      
      
      void drawTest(){
         cout<<endl<<"---The draw method is being tested. We will print the 10x10 blank table to the screen";
         Tetris tetris(10,10);
         tetris.draw();
         cout<<endl<<"Process is successful";
      }
      
      void animateTest(){
         cout<<endl<<"---In the Animate function, the terminal screen is cleared. Check out the output so far. Do you want to continue the test?Yes[Y,y] ";
         char input;
         cin>>input;
         
         if(input == 'Y' || input == 'y'){         
         
         cout<<endl<<"Testing the Animate function. The tetromino L will be animated";
         
         Tetromino t1(tetrominos::L,'L');
         
         Tetris tetris(10,10);         
         
         tetris.animate(t1);
         
         cout<<endl<<"Process is successful";
         }
         
         else cout<<endl<<"Animate method will not be tested";
      }
      
      void where_to_putTest(){
      
         cout<<endl<<"---The user determines how far to the right or left the tetromino will be shifted. This method calculates where the tetromino will land on the chart and returns the row number of the spot where it will land. We will create a 10x10 Empty table and insert the L tetromino into it. Suppose the target column is 2. We expect the method to return 9 ";

         Tetromino t1(tetrominos::L,'L');
         
         Tetris tetris(10,10);         
         
         int target_column = 2;
         
         int return_value = tetris.where_to_put(t1,target_column);         
         
         cout<<endl<<"return value(row coordinate): "<<return_value;
         cout<<endl<<"Process is successful";
      }
      
      void array_copyTest(){
         
         cout<<endl<<"---The array_copy() method is being tested. ";
         
         cout<<endl<<"array to copy: "<<endl;
         
         Tetris tetris_table(10,10);
         Tetromino t1(tetrominos::Z,'Z');
         
         t1.print();
         
         cout<<endl<<"copied array: "<<endl;

         char** copy = new char*[2];
         for(int i=0; i<2; i++) copy[i] = new char[3];
         
         copy = tetris_table.array_copy(t1.get_our_tetro(),2,3);
         
         for(int i = 0 ; i<2; i++){
            for(int j=0 ; j<3; j++){
               cout<<copy[i][j];
            }
            cout<<endl;
         }
         
         cout<<endl<<"Process is successful";

         for(int i=0; i<2 ;i++) delete[] copy[i];  
         delete[] copy;            
                
      }
      
      void getAndset_tableTest(){
         
         cout<<endl<<"---The get_table() method is being tested. We create a 10x10 table ";
         
         cout<<endl<<"get_table() returned: "<<endl;
         
         Tetris tetris_table(10,10);

         char** copy = new char*[10];
         for(int i=0; i<10; i++) copy[i] = new char[10];
         
         copy = tetris_table.get_table();
         
         for(int i = 0 ; i<10; i++){
            for(int j=0 ; j<10; j++){
               cout<<copy[i][j];
            }
            cout<<endl;
         }
         
         cout<<endl<<"Process is successful";
         
         
         
         cout<<endl<<"---The set_table() method is being tested. We create a 10x10 table: "<<endl;
         
         tetris_table.set_table(copy);
         tetris_table.draw();
         
         cout<<endl<<"Process is successful";

         //The area allocated to the 2d copy array is deleted in the destructor. 
                
      }
      
      
      void get_table_rowTest(){
         
         cout<<endl<<"---The get_table_row() method is being tested. We created a 10x12 table. The method returned: "; 
         
         Tetris tetris_table(10,10);
         
         cout<<tetris_table.get_table_row();
         
         cout<<endl<<"Process is successful";
      }

      
      void get_table_columnTest(){
         
         cout<<endl<<"---The get_table_column() method is being tested. We created a 10x12 table. The method returned: "; 
         
         Tetris tetris_table(10,10);
         
         cout<<tetris_table.get_table_column();
         
         cout<<endl<<"Process is successful";
      }     
      
      void addition_assignment_operatorTest(){
      
         cout<<endl<<"---The addition assignment operator overloading(+=) method is being tested. We will add the T tetromino(tetromino class) to the 10x12 table(tetris class).";
         
         Tetris tetris_table(10,12);
         
         Tetromino t1(tetrominos::T,'T');
         
         tetris_table += t1;
         
         tetris_table.draw();
         
         cout<<endl<<"Process is successful";
      } 
      */

};

int main(){


   cout<<endl<<"----------------Checking Tetromino class methods---------------";
   
   
   Test test;
   
   test.tetrominoConstructorTest();
   cout<<endl<<endl;
   
   test.printTest();
   cout<<endl<<endl;

   test.rotateTest();
   cout<<endl<<endl;
   
   test.get_our_tetroTest();
   cout<<endl<<endl;

   test.get_tetro_rowTest();
   cout<<endl<<endl;
   
   test.get_tetro_columnTest();
   cout<<endl<<endl;
   
   test.get_letterTest();
   cout<<endl<<endl;      

   test.assignment_operatorTest();
   cout<<endl<<endl;   

   cout<<endl<<endl<<endl;
   
   

{
   cout<<endl<<"---------------Checking TetrisVector class methods--------------------";

   cout<<endl<<endl<<"----TetrisVector constructor is being tested----";
   TetrisVector vect_object1(10,10);
   vect_object1.draw();
   cout<<endl<<"The process is successful.";

   cout<<endl<<endl<<"----getTable() and setTable are being tested----";
   vector<vector<char>> board = vect_object1.getTable();
   vect_object1.setTable(board);
   vect_object1.draw();
   cout<<endl<<"The process is successful.";  

   cout<<endl<<endl<<"----get_table_row(): "<<vect_object1.get_table_row();
   cout<<endl<<endl<<"----get_table_column(): "<<vect_object1.get_table_column();

   
   cout<<endl<<endl<<"----add() method is being tested---";
   Tetromino t1(tetrominos::L,'L');
   vect_object1.add(t1);
   vect_object1.draw();
   cout<<endl<<"The process is successful."; 

  
   cout<<endl<<endl<<"----position_cntrl() method is being tested---";
   cout<<endl<<"---Checking position_ctrl in Tetris: A table of 10 rows and 10 columns will be created and it will be checked whether the L tetromino matches the table: ";  
   if(vect_object1.position_ctrl(t1,3,0) == 1){
      cout<<endl<<"position_ctrlTest correctly returned 1";
   }

   
   cout<<endl<<endl<<"----draw() method is being tested---";
   vect_object1.draw();
   cout<<endl<<"The process is successful.";   

  
   cout<<endl<<endl<<"----writeToFile() and readFromFile() method is being tested---";
   vect_object1.writeToFile();
   vect_object1.readFromFile();
   cout<<endl<<"The process is successful."; 

   
   cout<<endl<<endl<<"----animate() method is being tested---";
   cout<<endl<<"---In the Animate function, the terminal screen is cleared. Check out the output so far. Do you want to continue the test?Yes[Y,y] ";
   char input;
   cin>>input;  
   if(input == 'Y' || input == 'y'){         
   
      cout<<endl<<"Testing the Animate function. The tetromino L will be animated";
      
      //Tetromino t1(tetrominos::L,'L');
      
      TetrisVector tetris(10,10);         
      
      tetris.animate(t1);
      
      cout<<endl<<"Process is successful";
   }  
   else cout<<endl<<"Animate method will not be tested";
   cout<<endl<<"The process is successful."; 
   


   cout<<endl<<endl<<"----numberOfMoves(): "<<vect_object1.numberOfMoves();

   
   cout<<endl<<endl<<"----lastMove() method is being tested---";   
   cout<<endl<<"---In the lastMove function, the terminal screen is cleared. Check out the output so far. Do you want to continue the test?Yes[Y,y] ";
   cin>>input;  
   if(input == 'Y' || input == 'y'){         
   
      cout<<endl<<"Testing the lastMove function. Suppose the user turns the tetromino 3 steps to the right and shifts it 3 steps to the left in the last move. The lastMove will be animated";
      cout<<endl<<"Press a letter and then press enter to continue: ";
      cin>>input;      
      TetrisVector tetris(10,10);   
      tetris.increment_number_of_moves();      
      
      tetris.lastMove(t1,'R',3,'L',3);
      
      cout<<endl<<"Process is successful";
   }  
   else cout<<endl<<"lastMove() method will not be tested";


   cout<<endl<<endl<<"----where_to_put() method is being tested---";
   cout<<endl<<"---The user determines how far to the right or left the tetromino will be shifted. This method calculates where the tetromino will land on the chart and returns the row number of the spot where it will land. We will create a 10x10 Empty table and insert the L tetromino into it. Suppose the target column is 2. We expect the method to return 9 ";
   {
      Tetromino t1(tetrominos::L,'L');
      
      TetrisVector tetris(10,10);         
      
      int target_column = 2;
      
      int return_value = tetris.where_to_put(t1,target_column);         
      
      cout<<endl<<"return value(row coordinate): "<<return_value;
      cout<<endl<<"Process is successful";
   }


   cout<<endl<<endl<<"---The addition assignment operator overloading(+=) method is being tested. We will add the T tetromino(tetromino class) to the 10x12 table(tetris class).";
   {  
      TetrisVector tetris_table(10,12);
      
      Tetromino t1(tetrominos::T,'T');
      
      tetris_table += t1;
      
      tetris_table.draw();
      
      cout<<endl<<"Process is successful";
   }

}










{
   cout<<endl<<endl<<endl<<"---------------Checking TetrisArray1D class methods--------------------";

   cout<<endl<<endl<<"----TetrisArray1D constructor is being tested----";
   TetrisArray1D object1(10,10);
   object1.draw();
   cout<<endl<<"The process is successful.";

   cout<<endl<<endl<<"----get_table() and set_table are being tested----";
   char* board = object1.get_table();
   object1.set_table(board);
   object1.draw();
   cout<<endl<<"The process is successful.";  

   cout<<endl<<endl<<"----get_table_row(): "<<object1.get_table_row();
   cout<<endl<<endl<<"----get_table_column(): "<<object1.get_table_column();

   
   cout<<endl<<endl<<"----add() method is being tested---";
   Tetromino t1(tetrominos::L,'L');
   object1.add(t1);
   object1.draw();
   cout<<endl<<"The process is successful."; 

  
   cout<<endl<<endl<<"----position_cntrl() method is being tested---";
   cout<<endl<<"---Checking position_ctrl in Tetris: A table of 10 rows and 10 columns will be created and it will be checked whether the L tetromino matches the table: ";  
   if(object1.position_ctrl(t1,3,0) == 1){
      cout<<endl<<"position_ctrlTest correctly returned 1";
   }

   
   cout<<endl<<endl<<"----draw() method is being tested---";
   object1.draw();
   cout<<endl<<"The process is successful.";   

  
   cout<<endl<<endl<<"----writeToFile() and readFromFile() method is being tested---";
   object1.writeToFile();
   object1.readFromFile();
   cout<<endl<<"The process is successful."; 

   
   cout<<endl<<endl<<"----animate() method is being tested---";
   cout<<endl<<"---In the Animate function, the terminal screen is cleared. Check out the output so far. Do you want to continue the test?Yes[Y,y] ";
   char input;
   cin>>input;  
   if(input == 'Y' || input == 'y'){         
   
      cout<<endl<<"Testing the Animate function. The tetromino L will be animated";
      
      //Tetromino t1(tetrominos::L,'L');
      
      TetrisArray1D tetris(10,10);         
      
      tetris.animate(t1);
      
      cout<<endl<<"Process is successful";
   }  
   else cout<<endl<<"Animate method will not be tested";
   cout<<endl<<"The process is successful."; 
   


   cout<<endl<<endl<<"----numberOfMoves(): "<<object1.numberOfMoves();

   
   cout<<endl<<endl<<"----lastMove() method is being tested---";   
   cout<<endl<<"---In the lastMove function, the terminal screen is cleared. Check out the output so far. Do you want to continue the test?Yes[Y,y] ";
   cin>>input;  
   if(input == 'Y' || input == 'y'){         
   
      cout<<endl<<"Testing the lastMove function. Suppose the user turns the tetromino 3 steps to the right and shifts it 3 steps to the left in the last move. The lastMove will be animated";
      cout<<endl<<"Press a letter and then press enter to continue: ";
      cin>>input;      
      TetrisArray1D tetris(10,10);  

      tetris.increment_number_of_moves();      
       
      
      tetris.lastMove(t1,'R',3,'L',3);
      
      cout<<endl<<"Process is successful";
   }  
   else cout<<endl<<"lastMove() method will not be tested";


   cout<<endl<<endl<<"----where_to_put() method is being tested---";
   cout<<endl<<"---The user determines how far to the right or left the tetromino will be shifted. This method calculates where the tetromino will land on the chart and returns the row number of the spot where it will land. We will create a 10x10 Empty table and insert the L tetromino into it. Suppose the target column is 2. We expect the method to return 9 ";
   {
      Tetromino t1(tetrominos::L,'L');
      
      TetrisArray1D tetris(10,10);         
      
      int target_column = 2;
      
      int return_value = tetris.where_to_put(t1,target_column);         
      
      cout<<endl<<"return value(row coordinate): "<<return_value;
      cout<<endl<<"Process is successful";
   }


   cout<<endl<<endl<<"---The addition assignment operator overloading(+=) method is being tested. We will add the T tetromino(tetromino class) to the 10x12 table(tetris class).";
   {  
      TetrisArray1D tetris_table(10,12);
      
      Tetromino t1(tetrominos::T,'T');
      
      tetris_table += t1;
      
      tetris_table.draw();
      
      cout<<endl<<"Process is successful";
   }



   cout<<endl<<"---The array_copy() method is being tested. ";
   
   cout<<endl<<"array to copy: "<<endl;
   
   //TetrisArray1D tetris_table(10,10);
   //Tetromino t1(tetrominos::Z,'Z');
   
   //t1.print();
   object1.draw();
   
   cout<<endl<<"copied array: "<<endl;

   char* copy = new char[100];
   
   copy = object1.array_copy(object1.get_table(),10,10);
   
   for(int i = 0 ; i<10; i++){
      for(int j=0 ; j<10; j++){
         cout<<copy[i*10+j];
      }
      cout<<endl;
   }
   
   cout<<endl<<"Process is successful";
   delete[] copy; 

}










{
   cout<<endl<<"---------------Checking TetrisAdapter class methods--------------------";

   cout<<endl<<endl<<"----TetrisAdapter constructor is being tested----";
   TetrisAdapter<string> object1(10,10);
   object1.draw();
   cout<<endl<<"The process is successful.";

   cout<<endl<<endl<<"----gettable() and settable are being tested----";
   string board = object1.gettable();
   object1.settable(board);
   object1.draw();
   cout<<endl<<"The process is successful.";  

   cout<<endl<<endl<<"----get_table_row(): "<<object1.get_table_row();
   cout<<endl<<endl<<"----get_table_column(): "<<object1.get_table_column();

   
   cout<<endl<<endl<<"----add() method is being tested---";
   Tetromino t1(tetrominos::L,'L');
   object1.add(t1);
   object1.draw();
   cout<<endl<<"The process is successful."; 

  
   cout<<endl<<endl<<"----position_cntrl() method is being tested---";
   cout<<endl<<"---Checking position_ctrl in Tetris: A table of 10 rows and 10 columns will be created and it will be checked whether the L tetromino matches the table: ";  
   if(object1.position_ctrl(t1,3,0) == 1){
      cout<<endl<<"position_ctrlTest correctly returned 1";
   }

   
   cout<<endl<<endl<<"----draw() method is being tested---";
   object1.draw();
   cout<<endl<<"The process is successful.";   

  
   cout<<endl<<endl<<"----writeToFile() and readFromFile() method is being tested---";
   object1.writeToFile();
   object1.readFromFile();
   cout<<endl<<"The process is successful."; 

   
   cout<<endl<<endl<<"----animate() method is being tested---";
   cout<<endl<<"---In the Animate function, the terminal screen is cleared. Check out the output so far. Do you want to continue the test?Yes[Y,y] ";
   char input;
   cin>>input;  
   if(input == 'Y' || input == 'y'){         
   
      cout<<endl<<"Testing the Animate function. The tetromino L will be animated";
            
      TetrisAdapter<string> tetris(10,10);         
      
      tetris.animate(t1);
      
      cout<<endl<<"Process is successful";
   }  
   else cout<<endl<<"Animate method will not be tested";
   cout<<endl<<"The process is successful."; 
   


   cout<<endl<<endl<<"----numberOfMoves(): "<<object1.numberOfMoves();

   
   cout<<endl<<endl<<"----lastMove() method is being tested---";   
   cout<<endl<<"---In the lastMove function, the terminal screen is cleared. Check out the output so far. Do you want to continue the test?Yes[Y,y] ";
   cin>>input;  
   if(input == 'Y' || input == 'y'){         
   
      cout<<endl<<"Testing the lastMove function. Suppose the user turns the tetromino 3 steps to the right and shifts it 3 steps to the left in the last move. The lastMove will be animated";
      cout<<endl<<"Press a letter and then press enter to continue: ";
      cin>>input;      
      TetrisAdapter<string> tetris(10,10); 

      tetris.increment_number_of_moves();      
        
      
      tetris.lastMove(t1,'R',3,'L',3);
      
      cout<<endl<<"Process is successful";
   }  
   else cout<<endl<<"lastMove() method will not be tested";


   cout<<endl<<endl<<"----where_to_put() method is being tested---";
   cout<<endl<<"---The user determines how far to the right or left the tetromino will be shifted. This method calculates where the tetromino will land on the chart and returns the row number of the spot where it will land. We will create a 10x10 Empty table and insert the L tetromino into it. Suppose the target column is 2. We expect the method to return 9 ";
   {
      Tetromino t1(tetrominos::L,'L');
      
      TetrisAdapter<string> tetris(10,10);         
      
      int target_column = 2;
      
      int return_value = tetris.where_to_put(t1,target_column);         
      
      cout<<endl<<"return value(row coordinate): "<<return_value;
      cout<<endl<<"Process is successful";
   }


   cout<<endl<<endl<<"---The addition assignment operator overloading(+=) method is being tested. We will add the T tetromino(tetromino class) to the 10x12 table(tetris class).";
   {  
      TetrisAdapter<string> tetris_table(10,12);
      
      Tetromino t1(tetrominos::T,'T');
      
      tetris_table += t1;
      
      tetris_table.draw();
      
      cout<<endl<<"Process is successful";
   }

}







   cout<<endl<<"---------------Test driver completed its task--------------------"<<endl<<endl<<endl<<endl<<endl;
}
