#ifndef _TETRIS_
#define _TETRIS_
#include <iostream>
#include <vector>
#include <unistd.h>
#include <limits>
#include <array>
#include <deque>
#include "tetromino.h"
#include "tetris.h"
#include <utility>
#include <fstream>

using namespace std;
using namespace tetromino_namespace;
using namespace tetris_namespace;


      int AbstractTetris::number_of_moves = 0;

       TetrisArray1D::TetrisArray1D(const int table_row,const int table_column){
           
           this->table_row= table_row;
           this->table_column = table_column; 

            table = (char*)calloc(table_row* table_column, sizeof(char));

            for(auto i=0; i<table_row * table_column ; i++){
               table[i] = ' ';
            }     
       
       }
       
       
       TetrisArray1D::~TetrisArray1D(){

          free(table);

       }
       



       void TetrisArray1D::add(const Tetromino& t1){

          int tetro_row=0,tetro_column=0;
          for(int i=0;i<t1.get_tetro_row();i++){

             tetro_column=0;
             for(int j=(get_table_column()/2)-1 ; j<t1.get_tetro_column() + (get_table_column()/2)-1 ; j++){

                table[i*table_column + j] = t1.get_our_tetro()[tetro_row][tetro_column];
                tetro_column++;              
             }
             tetro_row++;
          }
           
       } 





       int TetrisArray1D::position_ctrl(Tetromino &t1,int x,int y){ //x:row  y:column

          int cell_num= t1.get_tetro_row() * t1.get_tetro_column(); //cell number in tetromino
          auto count=0; //If the count is equal to the number of cells, the tetromino is suitable for that region.
          int tetro_row= t1.get_tetro_row()-1;  //keeps one less than the number of lines of the given tetromino. Because we start the suitability check from the bottom line.
          int tetro_column= 0;
          
	   //compatibility test for the region


          for(int i=x;i+t1.get_tetro_row()>x;i--){ //It enter the loop as many as the tetromino's row number

             for(int j=y;j<t1.get_tetro_column()+y;j++){ //It enter the loop as many as the tetromino's column number
                
                if(table[i*table_column + j] == ' '){ 
                   count++;
                } //Starting from the last row, we check each column one by one and check for compatibility. If the place to be looked at is empty, we can put the cell we want to put there.
                
                else if(t1.get_our_tetro()[tetro_row][tetro_column] == ' ' ){
                   count++;  //If there is no space in the table, that is, if there is a letter, but if the cell of the tetromino we want to place there is a blank, this tetromino is suitable for that region. So we increase the count again.
                }
                
                else if(!(table[i*table_column + j] == 'I' || table[i*table_column + j] == 'O' || table[i*table_column + j] == 'T' || table[i*table_column + j] == 'J' || table[i*table_column + j] == 'L' || table[i*table_column + j] == 'S' || table[i*table_column + j] == 'Z' )){
                   return 3; 
                }//If a problem occurs because the table is out of bounds,
                
                else return 0; //If both conditions are not met, that area is not suitable for tetromino.
                
                tetro_column++;
             }
             
             tetro_row--; //I do these operations to understand which cell of the tetromino I check suitability with the table
             tetro_column=0;
          }
          
          
	  if( count == cell_num){ 
             return 1; 
           
           }
           
          else return 0;
          
          
       }




       void TetrisArray1D::draw(){
       
         cout<<endl<<endl;

         for(int i=0;i<get_table_column()+2;i++) cout<<'#';
         cout<<endl;
         
         
         for(int i=0 ; i<get_table_row() ; i++){
            cout<<'#';
            for(int j=0 ; j<get_table_column(); j++){
               cout<<table[i*table_column + j];
            }
            cout<<'#';
            cout<<endl;
            
         }        
         for(int i=0;i<get_table_column()+2;i++) cout<<'#';          
                    
       }

        void TetrisArray1D::writeToFile(){
         
         ofstream file;
         file.open("board.txt");
         file<<endl<<endl;

         for(int i=0;i<get_table_column()+2;i++) file<<'#';
         file<<endl;
         
         
         for(int i=0 ; i<get_table_row() ; i++){
            file<<'#';
            for(int j=0 ; j<get_table_column(); j++){
               file<<table[i*table_column+j];
            }
            file<<'#';
            file<<endl;
            
         }        
         for(int i=0;i<get_table_column()+2;i++) file<<'#';           

         file.close();   
       }  
       
       void TetrisArray1D::readFromFile(){

         ifstream file("board.txt");
         if(!file.is_open()){
            cout<<endl<<"Reading from file process is failed.";
            return;
         }
         
         cout<<endl<<"Data read from file: "<<endl<<endl;
         string line;
         while(getline(file,line)){
            cout<<line<<endl;
         }
         file.close();
       }       
       

       void TetrisArray1D::animate(Tetromino &t1){
       
          number_of_moves++;
          char* temp_table= array_copy(table,get_table_row(),get_table_column());
          int row=0;
          int column= get_table_column()/2;
          
          int target_row;
          int target_column;
          
          
          char rotation_direction;
          int repeat1;
          cout<<endl<<"If you want to rotate the tetromino to the left:[L,l] / right:[R,r]: "; 
          while(1){  //Checking if entries are valid
             
             cin>>rotation_direction;
             
             if(rotation_direction == 'L' || rotation_direction == 'l'){
             
                 cout<<endl<<"How many times do you want to rotate?: ";
                  while(!(cin >> repeat1)){
                     cout << "Error, please try again: " << endl;
                     cin.clear();
                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                  }
                  
                  for(int i=0;i<repeat1;i++)  t1.rotate(1);     		 
                  break;           
             }
             
             
             else if(rotation_direction == 'R' || rotation_direction == 'r'){
             
                 cout<<endl<<"How many times do you want to rotate?: ";
                  while(!(cin >> repeat1)){
                     cout << "Error, please try again: " << endl;
                     cin.clear();
                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                  }
                  
                  for(int i=0;i<repeat1;i++)  t1.rotate(2);  
                  break;           
             }
             
             
             else{
               cout<<endl<<"Input is not valid. Try again!: ";
               cin.ignore(numeric_limits<streamsize>::max(),'\n');             
             }          
          }
          cout<< "\x1B[2J\x1B[H";
          add(t1);
          draw();
          table=array_copy(temp_table,get_table_row(),get_table_column());
        
          
          char move_direction;
          int repeat2;


          
          while(1){
             
             cout<<endl<<"If you want to move the tetromino to the left[L,l] / right[R,r]:  ";
             cin>>move_direction;
             
             if(move_direction == 'L' || move_direction == 'l'){
             
                 cout<<endl<<"How many units to the left do you want the Tetromino to move?: ";
                 do{
                     while(!(cin >> repeat2)){
                        cout << "Error, please try again: " << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                     }
                     cout<<endl<<"You must enter a number less than or equal to: "<<(get_table_column()/2)-1<<" : ";
		            }while(! (repeat2<=(get_table_column()/2)-1) ); //For example, if the table consists of 8 columns, tetro is first printed on the screen at the top and in the 4th column. Therefore, the user can take a maximum of 3 steps to the left.
                  target_column = (get_table_column()/2)-1 - repeat2;
                  break;           
             }
             
             
             else if(move_direction == 'R' || move_direction == 'r'){
             
                 cout<<endl<<"How many units to the right do you want the Tetromino to move?: ";
                 do{
                     while(!(cin >> repeat2)){
                        cout << "Error, please try again: " << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                     }
                     cout<<endl<<"You must enter a number less than or equal to: "<<get_table_column() - ((get_table_column()/2)-1) - t1.get_tetro_column()<<" : ";
		            }while(! (repeat2<= get_table_column() - ((get_table_column()/2)-1) - t1.get_tetro_column()) );
		 
                  target_column = (get_table_column()/2)-1 + repeat2; 
                  break;           
             }
             
             
             else{
               cout<<endl<<"Input is not valid. Try again!: ";
               cin.ignore(numeric_limits<streamsize>::max(),'\n');             
             }          
          }          
          cout<< "\x1B[2J\x1B[H";

          int coordinate1= where_to_put(t1,target_column); //I found the target row with this function

          if(coordinate1 == -99){ //If 99 is returned, that means that tetromino cannot be added to the table.
             cout<< "\x1B[2J\x1B[H";
             cout<<endl<<"We cannot add this tetromino to the board. You cannot add new tetromino to the first 3 rows of the board!";
             draw();
             return;
          }


          target_row=coordinate1-t1.get_tetro_row()+1;  //I subtract the row number of the tetromino from the row value returned as the target column and add 1. I do this because of the method I use to add tetrominos to the board. For example, if I have that 2-by-2 tetrominome and the coordinates of 0.0 are returned and I set 0.0 as the target, then half of O will not appear. Because; the 0,0 cell of the tetromino will be put in the 0,0 of the table, cell 0.1 will be put in 0.1 of the table. cell 1.0 of the tetromino is desired to be put into the cell -1.0 of the table, which gives an error. So I ensure the target row is 1 not 0.
          //target_column = coordinates[1];
          
          
          
          
          if(column - target_column > 0){  //If it needs to move to the left
             
             while(!(column == target_column && row == target_row) ){

               if(column != target_column) column--;
                
                if(column == target_column){   //first, moves towards the target column and then moves down.
                   if(row != target_row) row++;
                }
                  
                 //the part where the tetromino is placed on the table
               int tetro_row=0,tetro_column=0;
               for(int i=row;i<t1.get_tetro_row()+row;i++){
                        tetro_column=0;
                  for(int j=column ; j<t1.get_tetro_column() + column ; j++){
                     if(table[i*table_column + j] == ' ') table[i*table_column + j]= t1.get_our_tetro()[tetro_row][tetro_column];
                     tetro_column++;              
                  }
                  tetro_row++;
               }

               cout<< "\x1B[2J\x1B[H"; //clear the screen
               draw();
               usleep(50000); //sleep 20 millisecond
               if(!(column == target_column && row == target_row)) table=array_copy(temp_table,get_table_row(),get_table_column());  //I convert the table to the way it was before the animation, otherwise the trace of the previous tetromino remains in the table. But if the tetromino has reached the target, there's no need to do that. The table can remain as it is.
                                    
             }


          }


          else if(column - target_column <= 0){  //If it needs to move to the right
             
             while(!(column == target_column && row == target_row) ){

               if(column != target_column) column++;
                
                if(column == target_column){   //first, moves towards the target column and then moves down.
                   if(row != target_row) row++;
                }               
                  
                  //the part where the tetromino is placed on the table
               int tetro_row=0,tetro_column=0;
               for(int i=row;i<t1.get_tetro_row()+row;i++){
                        tetro_column=0;
                  for(int j=column ; j<t1.get_tetro_column() + column ; j++){
                     if(table[i*table_column + j] == ' ') table[i*table_column + j] = t1.get_our_tetro()[tetro_row][tetro_column];
                     tetro_column++;              
                  }
                  tetro_row++;
               }	     

               cout<< "\x1B[2J\x1B[H";
               draw();
               usleep(50000);
               if(!(column == target_column && row == target_row)) table=array_copy(temp_table,get_table_row(),get_table_column());  //I convert the table to the way it was before the animation, otherwise the trace of the previous tetromino remains in the table. But if the tetromino has reached the target, there's no need to do that. The table can remain as it is.
                                    
             }    
          }
            
            //When a row is full, this is done to delete it.
            int count = 0;
            for(int i = table_row-1; i>0; i--){

               for(int j = 0; j<table_column; j++){
                  if(table[i*table_column + j] != ' ') count++;
               }

               if(count == table_column){
                  
                  for(int k = i; k>0; k--){
                     for(int j = 0; j<table_column; j++){
                        table[k*table_column + j] = table[(k-1)*table_column + j];
                     }
                  }                  
               }
               count = 0;
            }          
                    
       
       }
       
       int TetrisArray1D::numberOfMoves(){
         return number_of_moves;
       }       
       
       void TetrisArray1D::lastMove(Tetromino &t1,char rotation_direction,int repeat1,char move_direction,int repeat2){
          
          try{

            if( number_of_moves == 0) throw number_of_moves;
          }
          catch(int x){
             cerr<<endl<<"There is no previous move";
             return;
          }



          char* table_here= array_copy(table,get_table_row(),get_table_column());
          char* temp_table= array_copy(table,get_table_row(),get_table_column());
          int row=0;
          int column= get_table_column()/2;
          
          int target_row;
          int target_column;
          

             if(rotation_direction == 'L' || rotation_direction == 'l'){
                  
                  for(int i=0;i<repeat1;i++)  t1.rotate(1);     		 
           
             }
             
             
             else if(rotation_direction == 'R' || rotation_direction == 'r'){
   
                  for(int i=0;i<repeat1;i++)  t1.rotate(2);           
             }
        
          
          cout<< "\x1B[2J\x1B[H";
          add(t1);
          draw();
          table_here=array_copy(temp_table,get_table_row(),get_table_column());
        
    
             if(move_direction == 'L' || move_direction == 'l'){
                             
                  target_column = (get_table_column()/2)-1 - repeat2;
             }
             
             
             else if(move_direction == 'R' || move_direction == 'r'){
  	 
                  target_column = (get_table_column()/2)-1 + repeat2;            
             }
         
          cout<< "\x1B[2J\x1B[H";

          int coordinate1= where_to_put(t1,target_column); //I found the target row with this function

          if(coordinate1 == -99){ //If 99 is returned, that means that tetromino cannot be added to the table.
             cout<< "\x1B[2J\x1B[H";
             cout<<endl<<"We cannot add this tetromino to the board. You cannot add new tetromino to the first 3 rows of the board!";
             draw();
             return;
          }


          target_row=coordinate1-t1.get_tetro_row()+1;  //I subtract the row number of the tetromino from the row value returned as the target column and add 1. I do this because of the method I use to add tetrominos to the board. For example, if I have that 2-by-2 tetrominome and the coordinates of 0.0 are returned and I set 0.0 as the target, then half of O will not appear. Because; the 0,0 cell of the tetromino will be put in the 0,0 of the table, cell 0.1 will be put in 0.1 of the table. cell 1.0 of the tetromino is desired to be put into the cell -1.0 of the table, which gives an error. So I ensure the target row is 1 not 0.
          //target_column = coordinates[1];
          
          //First of all, we need to remove the last tetromino from where it was placed.
               int tetro_row=0,tetro_column=0;
               for(int i=target_row;i<t1.get_tetro_row()+target_row;i++){
                        tetro_column=0;
                  for(int j=target_column ; j<t1.get_tetro_column() + target_column ; j++){
                     if(table_here[i*table_column+j] != ' ') table_here[i*table_column+j]= ' ';
                     tetro_column++;              
                  }
                  tetro_row++;
               }          
          
          
          if(column - target_column > 0){  //If it needs to move to the left
             
             while(!(column == target_column && row == target_row) ){

               if(column != target_column) column--;
                
                if(column == target_column){   //first, moves towards the target column and then moves down.
                   if(row != target_row) row++;
                }
                  
                 //the part where the tetromino is placed on the table
               tetro_row=0; tetro_column=0;
               for(int i=row;i<t1.get_tetro_row()+row;i++){
                        tetro_column=0;
                  for(int j=column ; j<t1.get_tetro_column() + column ; j++){
                     if(table_here[i*table_column + j] == ' ') table_here[i*table_column + j]= t1.get_our_tetro()[tetro_row][tetro_column];
                     tetro_column++;              
                  }
                  tetro_row++;
               }

               cout<< "\x1B[2J\x1B[H"; //clear the screen


         //for drawing: 
         cout<<endl<<endl;
         for(int i=0;i<get_table_column()+2;i++) cout<<'#';
         cout<<endl; 
         for(int i=0 ; i<get_table_row() ; i++){
            cout<<'#';
            for(int j=0 ; j<get_table_column(); j++){
               cout<<table_here[i*table_column+j];
            }
            cout<<'#';
            cout<<endl;     
         }        
         for(int i=0;i<get_table_column()+2;i++) cout<<'#'; 
         
               usleep(50000); //sleep 20 millisecond
               if(!(column == target_column && row == target_row)) table_here=array_copy(temp_table,get_table_row(),get_table_column());  //I convert the table to the way it was before the animation, otherwise the trace of the previous tetromino remains in the table. But if the tetromino has reached the target, there's no need to do that. The table can remain as it is.
                                    
             }    
          }


          else if(column - target_column <= 0){  //If it needs to move to the right
             
             while(!(column == target_column && row == target_row) ){

               if(column != target_column) column++;
                
                if(column == target_column){   //first, moves towards the target column and then moves down.
                   if(row != target_row) row++;
                }               
                  
                  //the part where the tetromino is placed on the table
               tetro_row=0; tetro_column=0;
               for(int i=row;i<t1.get_tetro_row()+row;i++){
                        tetro_column=0;
                  for(int j=column ; j<t1.get_tetro_column() + column ; j++){
                     if(table_here[i*table_column + j] == ' ') table_here[i*table_column + j] = t1.get_our_tetro()[tetro_row][tetro_column];
                     tetro_column++;              
                  }
                  tetro_row++;
               }	     

               cout<< "\x1B[2J\x1B[H";

         //for drawing: 
         cout<<endl<<endl;
         for(int i=0;i<get_table_column()+2;i++) cout<<'#';
         cout<<endl; 
         for(int i=0 ; i<get_table_row() ; i++){
            cout<<'#';
            for(int j=0 ; j<get_table_column(); j++){
               cout<<table_here[i*table_column+j];
            }
            cout<<'#';
            cout<<endl;     
         }        
         for(int i=0;i<get_table_column()+2;i++) cout<<'#'; 

               usleep(50000);
               if(!(column == target_column && row == target_row)) table_here=array_copy(temp_table,get_table_row(),get_table_column());  //I convert the table to the way it was before the animation, otherwise the trace of the previous tetromino remains in the table. But if the tetromino has reached the target, there's no need to do that. The table can remain as it is.
                                    
             }    
          }

       }
       

       int TetrisArray1D::where_to_put(Tetromino &t1, const int target_column){ 
          
          //The appropriate row and column coordinates are kept in this variable.         
          int x=get_table_row()-1,y;  

             y=target_column;
             while(1){
                if(position_ctrl(t1,x,y) == 1){            
		    return x;              
                }
                
                if(x == 3){  //If it have been reached the 3rd line and still no suitable location is found, -99 is returned. That means the tetromino can't fit to the board
                   return -99;
                }
                x--;                                  
             }
             

      }   
      
          

      char* TetrisArray1D::array_copy(const char* array, const int row, const int column) {
      
          char* temp_table = (char*)calloc(row*column,sizeof(char));          
          
          for (auto i = 0; i < row*column; i++){
             
            temp_table[i] =  array[i];
          }
          
          
          return temp_table;
      }
      
      
      
      char* TetrisArray1D::get_table() const{
         return table;
      }
      
      
      
      void TetrisArray1D::set_table(const char* array){
            
          for(int i=0; i<table_row*table_column; i++){
             table[i] = array[i];
          }    
      }
      
      
      
      int TetrisArray1D::get_table_row() const{
         return table_row;
      }
      
      

      int TetrisArray1D::get_table_column() const{
         return table_column;
      }
      
      
      void TetrisArray1D::operator+=(Tetromino& t1){

         add(t1);
      }

      vector<vector<char>> TetrisArray1D::getTable() const{
          exit(-1); 
      }
      
      void TetrisArray1D::setTable(vector<vector<char>>  vect){
         return;
      }       

      void TetrisArray1D::increment_number_of_moves(){
         number_of_moves++;
      } 



















   /////////// TetrisVector PART ///////////






       TetrisVector::TetrisVector(const int table_row,const int table_column){
           
           this->table_row= table_row;
           this->table_column = table_column;

          for(auto i = 0; i<table_row; i++){
             
             vector<char> temp;
             for(auto j = 0; j<table_column; j++){
                temp.push_back(' ');
             }
             table.push_back(temp);
          }       
       
       }
       
       
       TetrisVector::~TetrisVector(){

       }
       



       void TetrisVector::add(const Tetromino& t1){

          int tetro_row=0,tetro_column=0;
          for(int i=0;i<t1.get_tetro_row();i++){

             tetro_column=0;
             for(int j=(get_table_column()/2)-1 ; j<t1.get_tetro_column() + (get_table_column()/2)-1 ; j++){

                table[i][j]= t1.get_our_tetro()[tetro_row][tetro_column];
                tetro_column++;              
             }
             tetro_row++;
          }
           
       } 





       int TetrisVector::position_ctrl(Tetromino &t1,int x,int y){ //x:row  y:column

          int cell_num= t1.get_tetro_row() * t1.get_tetro_column(); //cell number in tetromino
          auto count=0; //If the count is equal to the number of cells, the tetromino is suitable for that region.
          int tetro_row= t1.get_tetro_row()-1;  //keeps one less than the number of lines of the given tetromino. Because we start the suitability check from the bottom line.
          int tetro_column= 0;
          
	   //compatibility test for the region


          for(int i=x;i+t1.get_tetro_row()>x;i--){ //It enter the loop as many as the tetromino's row number

             for(int j=y;j<t1.get_tetro_column()+y;j++){ //It enter the loop as many as the tetromino's column number
                
                if(table[i][j] == ' '){ 
                   count++;
                } //Starting from the last row, we check each column one by one and check for compatibility. If the place to be looked at is empty, we can put the cell we want to put there.
                
                else if(t1.get_our_tetro()[tetro_row][tetro_column] == ' ' ){
                   count++;  //If there is no space in the table, that is, if there is a letter, but if the cell of the tetromino we want to place there is a blank, this tetromino is suitable for that region. So we increase the count again.
                }
                
                else if(!(table[i][j] == 'I' || table[i][j] == 'O' || table[i][j] == 'T' || table[i][j] == 'J' || table[i][j] == 'L' || table[i][j] == 'S' || table[i][j] == 'Z' )){
                   return 3; 
                }//If a problem occurs because the table is out of bounds,
                
                else return 0; //If both conditions are not met, that area is not suitable for tetromino.
                
                tetro_column++;
             }
             
             tetro_row--; //I do these operations to understand which cell of the tetromino I check suitability with the table
             tetro_column=0;
          }
          
          
	  if( count == cell_num){ 
             return 1; 
           
           }
           
          else return 0;
          
          
       }




       void TetrisVector::draw(){
       
         cout<<endl<<endl;

         for(int i=0;i<get_table_column()+2;i++) cout<<'#';
         cout<<endl;
         
         
         for(int i=0 ; i<get_table_row() ; i++){
            cout<<'#';
            for(int j=0 ; j<get_table_column(); j++){
               cout<<table[i][j];
            }
            cout<<'#';
            cout<<endl;
            
         }        
         for(int i=0;i<get_table_column()+2;i++) cout<<'#';          
                    
       }


       void TetrisVector::writeToFile(){
         
         ofstream file;
         file.open("board.txt");
         file<<endl<<endl;

         for(int i=0;i<get_table_column()+2;i++) file<<'#';
         file<<endl;         
         
         for(int i=0 ; i<get_table_row() ; i++){
            file<<'#';
            for(int j=0 ; j<get_table_column(); j++){
               file<<table[i][j];
            }
            file<<'#';
            file<<endl;
            
         } 
         for(int i=0;i<get_table_column()+2;i++) file<<'#';     

         file.close();            
       }   

       void TetrisVector::readFromFile(){

         ifstream file("board.txt");
         if(!file.is_open()){
            cout<<endl<<"Reading from file process is failed.";
            return;
         }
         
         cout<<endl<<"Data read from file: "<<endl<<endl;
         string line;
         while(getline(file,line)){
            cout<<line<<endl;
         }
         file.close();
       }


       void TetrisVector::animate(Tetromino &t1){
       
          number_of_moves++;
          vector<vector<char>> temp_table = table;
          int row=0;
          int column= get_table_column()/2;
          
          int target_row;
          int target_column;
          
          
          char rotation_direction;
          int repeat1;
          cout<<endl<<"If you want to rotate the tetromino to the left:[L,l] / right:[R,r]: "; 
          while(1){  //Checking if entries are valid
             
             cin>>rotation_direction;
             
             if(rotation_direction == 'L' || rotation_direction == 'l'){
             
                 cout<<endl<<"How many times do you want to rotate?: ";
                  while(!(cin >> repeat1)){
                     cout << "Error, please try again: " << endl;
                     cin.clear();
                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                  }
                  
                  for(int i=0;i<repeat1;i++)  t1.rotate(1);     		 
                  break;           
             }
             
             
             else if(rotation_direction == 'R' || rotation_direction == 'r'){
             
                 cout<<endl<<"How many times do you want to rotate?: ";
                  while(!(cin >> repeat1)){
                     cout << "Error, please try again: " << endl;
                     cin.clear();
                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                  }
                  
                  for(int i=0;i<repeat1;i++)  t1.rotate(2);  
                  break;           
             }
             
             
             else{
               cout<<endl<<"Input is not valid. Try again!: ";
               cin.ignore(numeric_limits<streamsize>::max(),'\n');             
             }          
          }
          cout<< "\x1B[2J\x1B[H";
          add(t1);
          draw();
          table = temp_table;
          
          char move_direction;
          int repeat2;


          
          while(1){
             
             cout<<endl<<"If you want to move the tetromino to the left[L,l] / right[R,r]:  ";
             cin>>move_direction;
             
             if(move_direction == 'L' || move_direction == 'l'){
             
                 cout<<endl<<"How many units to the left do you want the Tetromino to move?: ";
                 do{
                     while(!(cin >> repeat2)){
                        cout << "Error, please try again: " << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                     }
                  cout<<endl<<"You must enter a number less than or equal to: "<<(get_table_column()/2)-1<<" : ";
		            }while(! (repeat2<=(get_table_column()/2)-1) ); //For example, if the table consists of 8 columns, tetro is first printed on the screen at the top and in the 4th column. Therefore, the user can take a maximum of 3 steps to the left.
                  target_column = (get_table_column()/2)-1 - repeat2;
                  break;           
             }
             
             
             else if(move_direction == 'R' || move_direction == 'r'){
             
                 cout<<endl<<"How many units to the right do you want the Tetromino to move?: ";
                 do{
                     while(!(cin >> repeat2)){
                        cout << "Error, please try again: " << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                     }
                     cout<<endl<<"You must enter a number less than or equal to: "<<get_table_column() - ((get_table_column()/2)-1) - t1.get_tetro_column()<<" : ";
		            }while(! (repeat2<= get_table_column() - ((get_table_column()/2)-1) - t1.get_tetro_column()) );
		 
                  target_column = (get_table_column()/2)-1 + repeat2; 
                  break;           
             }
             
             
             else{
               cout<<endl<<"Input is not valid. Try again!: ";
               cin.ignore(numeric_limits<streamsize>::max(),'\n');             
             }          
          }          
          cout<< "\x1B[2J\x1B[H";

          int coordinate1= where_to_put(t1,target_column); //I found the target row with this function

          if(coordinate1 == -99){ //If 99 is returned, that means that tetromino cannot be added to the table.
             cout<< "\x1B[2J\x1B[H";
             cout<<endl<<"We cannot add this tetromino to the board. You cannot add new tetromino to the first 3 rows of the board!";
             draw();
             return;
          }


          target_row=coordinate1-t1.get_tetro_row()+1;  //I subtract the row number of the tetromino from the row value returned as the target column and add 1. I do this because of the method I use to add tetrominos to the board. For example, if I have that 2-by-2 tetrominome and the coordinates of 0.0 are returned and I set 0.0 as the target, then half of O will not appear. Because; the 0,0 cell of the tetromino will be put in the 0,0 of the table, cell 0.1 will be put in 0.1 of the table. cell 1.0 of the tetromino is desired to be put into the cell -1.0 of the table, which gives an error. So I ensure the target row is 1 not 0.
          //target_column = coordinates[1];
          
          
          
          
          if(column - target_column > 0){  //If it needs to move to the left
             
             while(!(column == target_column && row == target_row) ){

               if(column != target_column) column--;
                
                if(column == target_column){   //first, moves towards the target column and then moves down.
                   if(row != target_row) row++;
                }
                  
                 //the part where the tetromino is placed on the table
               int tetro_row=0,tetro_column=0;
               for(int i=row;i<t1.get_tetro_row()+row;i++){
                        tetro_column=0;
                  for(int j=column ; j<t1.get_tetro_column() + column ; j++){
                     if(table[i][j] == ' ') table[i][j]= t1.get_our_tetro()[tetro_row][tetro_column];
                     tetro_column++;              
                  }
                  tetro_row++;
               }

               cout<< "\x1B[2J\x1B[H"; //clear the screen
               draw();
               usleep(50000); //sleep 20 millisecond
               if(!(column == target_column && row == target_row)) table = temp_table; //table=array_copy(temp_table,get_table_row(),get_table_column());  //I convert the table to the way it was before the animation, otherwise the trace of the previous tetromino remains in the table. But if the tetromino has reached the target, there's no need to do that. The table can remain as it is.
                                    
             }    
          }


          else if(column - target_column <= 0){  //If it needs to move to the right
             
             while(!(column == target_column && row == target_row) ){

               if(column != target_column) column++;
                
                if(column == target_column){   //first, moves towards the target column and then moves down.
                   if(row != target_row) row++;
                }               
                  
                  //the part where the tetromino is placed on the table
               int tetro_row=0,tetro_column=0;
               for(int i=row;i<t1.get_tetro_row()+row;i++){
                        tetro_column=0;
                  for(int j=column ; j<t1.get_tetro_column() + column ; j++){
                     if(table[i][j] == ' ') table[i][j] = t1.get_our_tetro()[tetro_row][tetro_column];
                     tetro_column++;              
                  }
                  tetro_row++;
               }	     

               cout<< "\x1B[2J\x1B[H";
               draw();
               usleep(50000);
               if(!(column == target_column && row == target_row)) table = temp_table; //table=array_copy(temp_table,get_table_row(),get_table_column());  //I convert the table to the way it was before the animation, otherwise the trace of the previous tetromino remains in the table. But if the tetromino has reached the target, there's no need to do that. The table can remain as it is.
                                    
             }    
          }
            
            //When a row is full, this is done to delete it.
            int count = 0;
            for(int i = table_row-1; i>0; i--){

               for(int j = 0; j<table_column; j++){
                  if(table[i][j] != ' ') count++;
               }

               if(count == table_column){
                  
                  for(int k = i; k>0; k--){
                     for(int j = 0; j<table_column; j++){
                        //if(table[i*table_column + j] != ' ') count++;
                        table[k][j] = table[k-1][j];
                     }
                  }                  
               }
               count = 0;
            }                    
       
       }
       
       int TetrisVector::numberOfMoves(){
         return number_of_moves;
       }       
       
       void TetrisVector::lastMove(Tetromino &t1,char rotation_direction,int repeat1,char move_direction,int repeat2){

          
          try{

            if( number_of_moves == 0) throw number_of_moves;
          }
          catch(int x){
             cerr<<endl<<"There is no previous move";
             return;
          }
          
          
          vector<vector<char>> table_here = table;
          vector<vector<char>> temp_table = table;
          int row=0;
          int column= get_table_column()/2;
          
          int target_row;
          int target_column;
             
             if(rotation_direction == 'L' || rotation_direction == 'l'){
                  
                  for(int i=0;i<repeat1;i++)  t1.rotate(1);     		         
             }
             
             
             else if(rotation_direction == 'R' || rotation_direction == 'r'){
                  
                  for(int i=0;i<repeat1;i++)  t1.rotate(2);          
             }

          cout<< "\x1B[2J\x1B[H";
          add(t1);
          draw();
          table_here = temp_table;

          


             if(move_direction == 'L' || move_direction == 'l'){
             
                  target_column = (get_table_column()/2)-1 - repeat2;         
             }
             
             
             else if(move_direction == 'R' || move_direction == 'r'){

                  target_column = (get_table_column()/2)-1 + repeat2; 
             }
        
          cout<< "\x1B[2J\x1B[H";

          int coordinate1= where_to_put(t1,target_column); //I found the target row with this function

          if(coordinate1 == -99){ //If 99 is returned, that means that tetromino cannot be added to the table.
             cout<< "\x1B[2J\x1B[H";
             cout<<endl<<"We cannot add this tetromino to the board. You cannot add new tetromino to the first 3 rows of the board!";
             draw();
             return;
          }


          target_row=coordinate1-t1.get_tetro_row()+1;  //I subtract the row number of the tetromino from the row value returned as the target column and add 1. I do this because of the method I use to add tetrominos to the board. For example, if I have that 2-by-2 tetrominome and the coordinates of 0.0 are returned and I set 0.0 as the target, then half of O will not appear. Because; the 0,0 cell of the tetromino will be put in the 0,0 of the table, cell 0.1 will be put in 0.1 of the table. cell 1.0 of the tetromino is desired to be put into the cell -1.0 of the table, which gives an error. So I ensure the target row is 1 not 0.
          
          
          //First of all, we need to remove the last tetromino from where it was placed.
          
               int tetro_row=0,tetro_column=0;
               
               for(int i=target_row;i<t1.get_tetro_row()+target_row;i++){
                        tetro_column=0;
                  for(int j=target_column ; j<t1.get_tetro_column() + target_column ; j++){
                     if(table_here[i][j] == ' ') table_here[i][j]= t1.get_our_tetro()[tetro_row][tetro_column];
                     tetro_column++;              
                  }
                  tetro_row++;
               } 
               
               

          
          if(column - target_column > 0){  //If it needs to move to the left
              
             while(!(column == target_column && row == target_row) ){
               if(column != target_column) column--;
                
                if(column == target_column){   //first, moves towards the target column and then moves down.
                   if(row != target_row) row++;
                }
                  
                 //the part where the tetromino is placed on the table
               tetro_row=0; tetro_column=0;
               for(int i=row;i<t1.get_tetro_row()+row;i++){
                        tetro_column=0;
                  for(int j=column ; j<t1.get_tetro_column() + column ; j++){
                     if(table_here[i][j] == ' ') table_here[i][j]= t1.get_our_tetro()[tetro_row][tetro_column];
                     tetro_column++;              
                  }
                  tetro_row++;
               }

               cout<< "\x1B[2J\x1B[H"; //clear the screen
            
         //for drawing:
         cout<<endl<<endl;
         for(int i=0;i<get_table_column()+2;i++) cout<<'#';
         cout<<endl;
         for(int i=0 ; i<get_table_row() ; i++){
            cout<<'#';
            for(int j=0 ; j<get_table_column(); j++){
               cout<<table_here[i][j];
            }
            cout<<'#';
            cout<<endl;           
         }        
         for(int i=0;i<get_table_column()+2;i++) cout<<'#'; 


               usleep(50000); //sleep 20 millisecond
               if(!(column == target_column && row == target_row)) table_here = temp_table; //table=array_copy(temp_table,get_table_row(),get_table_column());  //I convert the table to the way it was before the animation, otherwise the trace of the previous tetromino remains in the table. But if the tetromino has reached the target, there's no need to do that. The table can remain as it is.
                                    
             }    
          }


          else if(column - target_column <= 0){  //If it needs to move to the right
             while(!(column == target_column && row == target_row) ){
               if(column != target_column) column++;
                
                if(column == target_column){   //first, moves towards the target column and then moves down.
                   if(row != target_row) row++;
                }               
                  
                  //the part where the tetromino is placed on the table
               tetro_row=0; tetro_column=0;
               for(int i=row;i<t1.get_tetro_row()+row;i++){
                        tetro_column=0;
                  for(int j=column ; j<t1.get_tetro_column() + column ; j++){
                     if(table_here[i][j] == ' ') table_here[i][j] = t1.get_our_tetro()[tetro_row][tetro_column];
                     tetro_column++;              
                  }
                  tetro_row++;
               }	     

               cout<< "\x1B[2J\x1B[H";

         //for drawing:
         cout<<endl<<endl;
         for(int i=0;i<get_table_column()+2;i++) cout<<'#';
         cout<<endl;
         for(int i=0 ; i<get_table_row() ; i++){
            cout<<'#';
            for(int j=0 ; j<get_table_column(); j++){
               cout<<table_here[i][j];
            }
            cout<<'#';
            cout<<endl;           
         }        
         for(int i=0;i<get_table_column()+2;i++) cout<<'#'; 

               usleep(50000);
               if(!(column == target_column && row == target_row)) table_here = temp_table; //table=array_copy(temp_table,get_table_row(),get_table_column());  //I convert the table to the way it was before the animation, otherwise the trace of the previous tetromino remains in the table. But if the tetromino has reached the target, there's no need to do that. The table can remain as it is.
                                    
             }    
          }
       }       
       

       int TetrisVector::where_to_put(Tetromino &t1, const int target_column){ 
          
          //The appropriate row and column coordinates are kept in this variable.         
          int x=get_table_row()-1,y;  

             y=target_column;
             while(1){
                if(position_ctrl(t1,x,y) == 1){            
		             return x;              
                }
                
                if(x == 3){  //If it have been reached the 3rd line and still no suitable location is found, -99 is returned. That means the tetromino can't fit to the board
                   return -99;
                }
                x--;                                  
             }
             

      }   
      
          
      /*
      char** TetrisVector::array_copy(char const* const* array, const int row, const int column){
      
          char** temp_table= new char*[row];
          
          for(int i=0;i<row;i++){
             temp_table[i]= new char[column];
             for(int j=0;j<column;j++){
                temp_table[i][j] = array[i][j];
             }
          }
          
          return temp_table;
      }
      */
      
      
      vector<vector<char>> TetrisVector::getTable() const{
         return table;
      }
      
      
      
      void TetrisVector::setTable(vector<vector<char>>  vect){
          
          for(int i=0;i<table_row;i++){
             
             for(int j=0;j<table_column;j++){
                table[i][j] = vect[i][j];
             }
          }      
      }
      
      
      
      
      int TetrisVector::get_table_row() const{
         return table_row;
      }
      
      

      int TetrisVector::get_table_column() const{
         return table_column;
      }
      
      
      void TetrisVector::operator+=(Tetromino& t1){

         add(t1);
      }    


      char* TetrisVector::array_copy(const char* array, const int row, const int column){
           
           exit(-1);
      }
            
      char* TetrisVector::get_table() const{
           exit(-1);      
      }
      
      void TetrisVector::set_table(const char* array){
         return;
      }                      

      void TetrisVector::increment_number_of_moves(){
         number_of_moves++;
      }       













            

#endif
