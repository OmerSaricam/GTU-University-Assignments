#ifndef _TETRIS_
#define _TETRIS_
#include <iostream>
#include <vector>
#include <unistd.h>
#include "tetromino.h"
#include "tetris.h"

using namespace std;



       Tetris::Tetris(const int table_row,const int table_column){
       
	   for(auto i=0;i<table_row;i++){  
	      
              vector<char> temp_vect;
	      for(auto j=0;j<table_column;j++){
		 temp_vect.push_back(' ');
	      }
	      table.push_back(temp_vect);
	   }       
       
       }



       void Tetris::add(const Tetromino t1){
          
          int tetro_row=0,tetro_column=0;
          for(int i=0;i<t1.our_tetro.size();i++){
             tetro_column=0;
             for(int j=(table[0].size()/2)-1 ; j<t1.our_tetro[0].size() + (table[0].size()/2)-1 ; j++){
                table[i][j]= t1.our_tetro[tetro_row][tetro_column];
                tetro_column++;              
             }
             tetro_row++;
          }
           
       } 





       template<typename T>
       int Tetris::canfit(vector<vector<char>> tetro,T x,T y,const char letter){ //x:row  y:column

          int cell_num= tetro.size() * tetro[0].size(); //cell number in tetromino
          auto count=0; //If the count is equal to the number of cells, the tetromino is suitable for that region.
          int tetro_row= tetro.size()-1;  //keeps one less than the number of lines of the given tetromino. Because we start the suitability check from the bottom line.
          int tetro_column= 0;
          
	   //compatibility test for the region


          for(int i=x;i+tetro.size()>x;i--){ //It enter the loop as many as the tetromino's row number

             for(int j=y;j<tetro[0].size()+y;j++){ //It enter the loop as many as the tetromino's column number
                
                if(table[i][j] == ' '){ 
                   count++;
                } //Starting from the last row, we check each column one by one and check for compatibility. If the place to be looked at is empty, we can put the cell we want to put there.
                
                else if(tetro[tetro_row][tetro_column] == ' ' ){
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
          
          
     
          
          //A tetromino can fit exactly in that area, but if there is a space in the bottom line, the bestfit condition cannot be achieved.
          //So we also check to see if there will be a gap where the tetromino will be placed, disrupting the bestfit status.
          
          //I create a temporary table and sync that temp_table to the table, then add the tetromino that passed the region compatibility test we did above to the temp_table.          
          vector<vector<char>> temp_table= table;         

          tetro_row= tetro.size()-1;
          tetro_column= 0;
                          
          for(int i=x;i+tetro.size()>x;i--){ 

             for(int j=y;j<tetro[0].size()+y;j++){ 
 
                if(temp_table[i][j] == ' ') temp_table[i][j]=tetro[tetro_row][tetro_column];
                
                tetro_column++;
             }             
             tetro_row--; 
             tetro_column=0;
          }

          
          //We check if there is a space where the tetromino will be placed, disrupting the bestfit status.     
          int is_there_a_space=0;  

          if((temp_table[x][y-1] == ' ' && temp_table[x][y] == letter) || (temp_table[x][y] == ' ' && temp_table[x][y+1] == letter) || (temp_table[x][y+1] == ' ' && temp_table[x][y+2] == letter)){
             is_there_a_space=1;
             return 2; //2 is returned if the bestfit condition is broken because there is a space.
          }
          
          
          //If the compatibility test for the region is passed and space test is passed, then the bestfit status is achieved.
          if( count == cell_num && is_there_a_space == 0){  

             return 1; 
           
           }
           
          else return 0;
          
          
       }




       void Tetris::draw(){
       
	   cout<<endl<<endl;
	   int j;
	   for(int i=0;i<table[0].size()+2;i++) cout<<'#';
	   cout<<endl;
	   for(std::vector<char> i : table){  //range based loop 
	      cout<<'#';
	      for(j=0 ; j<i.size();j++){
		 cout<<i[j];
	      }
	      cout<<'#';
	      cout<<endl;  
          }
	  for(int i=0;i<table[0].size()+2;i++) cout<<'#';          
                    
       }


       void Tetris::Fit(int &row,int &column,const int target_row,const int target_column,Tetromino &t1,const int direction){ //direction 1 ise sol 0ise sağ.
       
       
          if(direction == 1){  //tetromino will move to the left
          
                
                if(column != target_column) column--;
                
                if(column == target_column){   //first, moves towards the target column and then moves down.
                   if(row != target_row) row++;
                }
                  
                  //the part where the tetromino is placed on the table
		 int tetro_row=0,tetro_column=0;
		 for(int i=row;i<t1.our_tetro.size()+row;i++){
	            tetro_column=0;
		     for(int j=column ; j<t1.our_tetro[0].size() + column ; j++){
		        if(table[i][j] == ' ') table[i][j]= t1.our_tetro[tetro_row][tetro_column];
		        tetro_column++;              
		     }
		     tetro_row++;
		 }
	  }
	  
	  else if(direction == 0){  //tetromino will move to the right
                
                if(column != target_column) column++;
                
                if(column == target_column){   //first, moves towards the target column and then moves down.
                   if(row != target_row) row++;
                }               
                  
                  //the part where the tetromino is placed on the table
		 int tetro_row=0,tetro_column=0;
		 for(int i=row;i<t1.our_tetro.size()+row;i++){
	            tetro_column=0;
		     for(int j=column ; j<t1.our_tetro[0].size() + column ; j++){
		        if(table[i][j] == ' ') table[i][j] = t1.our_tetro[tetro_row][tetro_column];
		        tetro_column++;              
		     }
		     tetro_row++;
		 }	     
	  
	  }	 
		       
       }
       
       
       void Tetris::animate(Tetromino &t1){
       
          
          vector<vector<char>> temp_table = table;
          int row=0;
          int column= table[0].size()/2;
          
          add(t1);
          draw();
          table=temp_table;

          vector<int> coordinates= where_to_put(t1); //I found the target row and column with this function

          if(coordinates[0] == -99){ //If 99 is returned, that means that tetromino cannot be added to the table.
             cout<< "\x1B[2J\x1B[H";
             cout<<endl<<"We cannot add this tetromino to the board. You cannot add new tetromino to the first 3 rows of the board!";
             draw();
             return;
          }

          //t1.print(t1.our_tetro);  
          int target_row=coordinates[0]-t1.our_tetro.size()+1;  //I subtract the row number of the tetromino from the row value returned as the target column and add 1. I do this because of the method I use to add tetrominos to the board. For example, if I have that 2-by-2 tetrominome and the coordinates of 0.0 are returned and I set 0.0 as the target, then half of O will not appear. Because; the 0,0 cell of the tetromino will be put in the 0,0 of the table, cell 0.1 will be put in 0.1 of the table. cell 1.0 of the tetromino is desired to be put into the cell -1.0 of the table, which gives an error. So I ensure the target row is 1 not 0.
          int target_column= coordinates[1];
          
          
          
          
          if(column - target_column > 0){  //If it needs to move to the left
             
             while(!(column == target_column && row == target_row) ){

                Fit(row,column,target_row,target_column,t1,1);

		 cout<< "\x1B[2J\x1B[H"; //clear the screen
		 draw();
		 usleep(50000); //sleep 20 millisecond
		 if(!(column == target_column && row == target_row)) table=temp_table;  //I convert the table to the way it was before the animation, otherwise the trace of the previous tetromino remains in the table. But if the tetromino has reached the target, there's no need to do that. The table can remain as it is.
		                      
             }    
          }


          else if(column - target_column <= 0){  //If it needs to move to the right
             
             while(!(column == target_column && row == target_row) ){

                Fit(row,column,target_row,target_column,t1,0);

		 cout<< "\x1B[2J\x1B[H";
		 draw();
		 usleep(50000);
		 if(!(column == target_column && row == target_row)) table=temp_table;  //I convert the table to the way it was before the animation, otherwise the trace of the previous tetromino remains in the table. But if the tetromino has reached the target, there's no need to do that. The table can remain as it is.
		                      
             }    
          }
                    
       
       }
       
       
       
       
       

       vector<int> Tetris::where_to_put(Tetromino &t1){ 
          vector<int> x_and_y; //The appropriate row and column coordinates are kept in this variable.
          
          int x=table.size()-1,y;  
          int flag1=0; //When the appropriate region is found in the table and the tetromino is placed there, we change this to 1 and break the while loop.
          int count2=0; //I change the order of the tetrominos if the tetrominos can never be sorted in the entered order without a space on the bottom line. But this cannot be done in any way in entries such as z o z. I'll keep track of how many sorting changes have been made with this variable to prevent the code from crashing. If the maximum number of changes has been reached, I will output that these tetrominos cannot be lined up in the best way.

             y=0; flag1=0;
             while(1){
		  for(int turn=0;turn<=3;turn++){  //Tetromino will rotate 4 times. If it cannot be placed to the table in all four move, the column i.e. y value will be incremented by 1

                    if(turn == 3  && canfit(t1.our_tetro,x,y,t1.letter) == 2){  //Although it passes the region compatibility test and is rotated in all directions, still if it does not pass the gap test, it is added to the table as it is. 'Cause there's no other choice.
                       
                       
                      while(canfit(t1.our_tetro,x,y,t1.letter) == 3){ //if it is not a best fit because it is outside the table, shape is rotated. I'm doing this due to an error when putting tetromino in the last columns of the row
                          t1.our_tetro=t1.rotate(t1.our_tetro,1);
                       }
                                              
                       x_and_y.push_back(x); //row value
                       x_and_y.push_back(y); //column value
                       return x_and_y;
                       
                    }

		     if(canfit(t1.our_tetro,x,y,t1.letter) == 1){ //Since the conditions are met, I place the parts of the tetromino in the table where the conditions are met.
		          x_and_y.push_back(x); //row value
		          x_and_y.push_back(y); //column value
		          return x_and_y;	  			    
		     }
			  

	             else{ 
	               if(t1.our_tetro[0][1] != 'T') t1.our_tetro=t1.rotate(t1.our_tetro,1);  
	               else{ t1.our_tetro=t1.rotate(t1.our_tetro,1); t1.our_tetro=t1.rotate(t1.our_tetro,1);} 
	               
	               //t1.print(t1.our_tetro);
	             }
			  
		  }     
                
                 if(flag1 == 1) break; 
                                  

                 if(y +1 < table[0].size()) y++;    //If we couldn't place the tetromino in that area of the table by rotating it in that column, I'll try my luck in the next column.
                 

                 else{  
                 
                    if(x == 3){  //If it have been reached the 3rd line and still no suitable location is found, -99 is returned. That means the tetromino can't fit to the board
                    
                       x_and_y.push_back(-99); 
                       x_and_y.push_back(-99);
                       return x_and_y;
                    }                  
                    y=0;
                    x--;
                    

                    
                    
               } 
             }

      }       

  


                   

#endif
