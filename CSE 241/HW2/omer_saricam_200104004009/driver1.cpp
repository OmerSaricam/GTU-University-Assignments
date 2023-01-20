#include <iostream>
#include <vector>
#include <limits>
#include <unistd.h>
#include "tetromino.h"
#include "tetris.h"



class Test{


   public:
      
      void tetrominoConstructorTest(){
      
         cout<<endl<<"Tetromino constructor being tested: ";
         
         Tetromino t1(tetrominos::S,'S');
         
         cout<<endl<<"Tetromino has been successfully created.";
      }
      
      void printTest(){
      
         cout<<endl<<"The print method is being tested. The S tetromino will be printed on the screen: ";
         
         Tetromino t1(tetrominos::S,'S');
         
         t1.print(t1.our_tetro);
         
         cout<<endl<<"Successfully printed to the screen";
      }

      void rotateTest(){
      
         cout<<endl<<"The rotate function is being tested. The tetromino will be rotated counterclockwise: ";
         
         Tetromino t1(tetrominos::S,'S');
         
         t1.our_tetro= t1.rotate(t1.our_tetro,1);
         
         t1.print(t1.our_tetro);
         
         cout<<endl<<"Successfully rotated";
      }
      
      void canFitTest(){
      
         cout<<endl<<"canFit is being tested. A table with 4 rows and 10 columns will be created and it will be checked whether the S tetromino is suitable for the table: ";
         
         Tetromino t1(tetrominos::S,'S');
         
         vector<vector<char>> table = table_maker(10);
         
         if(t1.canFit(t1.our_tetro,table,3,0) == 1){
            cout<<endl<<"canFit correctly returned 1";
         }
	  
	 else cout<<endl<<"canFit returned incorrect results."; 
      }
      
      void putShapeTest(){
      
         cout<<endl<<"putShape is being tested. It will create a 4x15 table and the S, J, Z, T tetrominos will be put on the table.";
         
         vector<Tetromino> tetro_objects;
         
         Tetromino t1(tetrominos::S,'S');
         Tetromino t2(tetrominos::J,'J');
         Tetromino t3(tetrominos::Z,'Z');
         Tetromino t4(tetrominos::T,'T');
         
         tetro_objects.push_back(t1);
         tetro_objects.push_back(t2);
         tetro_objects.push_back(t3);
         tetro_objects.push_back(t4);
         
         vector<vector<char>> table = table_maker(15);
         
         t1.putShape(table,tetro_objects);
         
         cout<<endl<<"Process is successful";
      }
      
      void tetrisConstructorTest(){
         
         cout<<endl<<"tetris Constructor is being tested. A table with 10 rows and 20 columns will be created: ";
         
         Tetris tetris(10,20);
         
         tetris.draw();
         
         cout<<endl<<"Process is successful";
      }
      
      void addTest(){
      
         cout<<endl<<"The add function is being tested. T tetromino will be put in the 10x10 table: ";
         
         Tetris tetris(10,10);
         
         Tetromino t1(tetrominos::T,'T');
         
         tetris.add(t1);  
         
         tetris.draw();
      }
      
      void canfitTest(){
      
         cout<<endl<<"Checking canfit in Tetris: A table of 10 rows and 10 columns will be created and it will be checked whether the L tetromino matches the table: ";
         
         Tetromino t1(tetrominos::L,'L');
         
         Tetris tetris(10,10);
        
         
         if(tetris.canfit(t1.our_tetro,3,0,'L') == 1){
            cout<<endl<<"canfit correctly returned 1";
         }
	  
	 else cout<<endl<<"canfit returned incorrect results.";          
      }
      
      void FitTest(){
         
         
         //Fit fonksiyonu tek başına bir işlem yapmıyor
         cout<<endl<<"The fit function is being tested. T tetromino will be put in row 5 column 4 of the table";
         
         Tetris tetris(10,10);
         
         Tetromino t1(tetrominos::T,'T');
         
         //void Fit(int &row,int &column,int target_row,int target_column,vector<vector<char>> &table,Tetromino &t1,const int direction);
         auto row=5;
         auto column=4;
         tetris.Fit(row,column,9,0,t1,1);
         tetris.draw();
         
         cout<<endl<<"Process is successful";
      }
      
      void drawTest(){
         cout<<endl<<"The draw method is being tested. We will print the 10x10 blank table to the screen";
         Tetris tetris(10,10);
         tetris.draw();
         cout<<endl<<"Process is successful";
      }
      
      void animateTest(){
         cout<<endl<<"In the Animate function, the terminal screen is cleared. Check out the output so far. Do you want to continue the test?Yes[Y,y] ";
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
      
         cout<<endl<<"The where_to_put function finds where the tetromino should be placed in the table and returns its coordinates. We will create a 10x10 Empty table and insert the L tetromino into it. We expect the method to return 9.0.";

         Tetromino t1(tetrominos::L,'L');
         
         Tetris tetris(10,10);         
         
         vector<int> return_value = tetris.where_to_put(t1);         
         
         cout<<endl<<"row coordinate: "<<return_value[0]<<endl<<"column coordinate: "<<return_value[1];
         cout<<endl<<"Process is successful";
      }

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

   test.canFitTest();
   cout<<endl<<endl;

   test.putShapeTest();
   cout<<endl<<endl<<endl;
   
   
   cout<<endl<<"---------------Checking Tetris class methods--------------------";
   
   test.tetrisConstructorTest();
   cout<<endl<<endl;
   
   test.addTest();
   cout<<endl<<endl;   
   
   test.canfitTest();
   cout<<endl<<endl; 
   
   test.FitTest();
   cout<<endl<<endl;  
   
   test.drawTest();
   cout<<endl<<endl; 
   
   test.animateTest();
   cout<<endl<<endl;          
   
   test.where_to_putTest();
   cout<<endl<<endl;
   
   
}
