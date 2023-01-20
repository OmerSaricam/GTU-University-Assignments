#ifndef _TETROMINO_
#define _TETROMINO_
#include <iostream>
#include <vector>
#include <unistd.h>
#include "tetromino.h"
#include "tetris.h"




using namespace std;



vector<vector<char>> table_maker(int number1){ //Creates the table where the game will be played, that is, the tetrominos will be lined up.

   vector<vector<char>> table( 4 ,vector<char> (number1*4));   
   
   for(auto i=0;i<table.size();i++){  

      for(auto j=0;j<table[i].size();j++){
         table[i][j]=' ';
      }
   }
   
   return table;
}


       Tetromino::Tetromino(){}
       
       Tetromino::Tetromino(tetrominos shape_type,char input2){

	      
	         if(shape_type == tetrominos::I) our_tetro= I1;
	            else if(shape_type == tetrominos::O) our_tetro= O1;
	            else if(shape_type == tetrominos::T) our_tetro= T1;
	            else if(shape_type == tetrominos::J) our_tetro= J1;
	            else if(shape_type == tetrominos::L) our_tetro= L1;
	            else if(shape_type == tetrominos::S) our_tetro= S1;
	            else if(shape_type == tetrominos::Z) our_tetro= Z1;
	         
	         letter = input2;   
	      
  
       }




       void Tetromino::print(vector<vector<char>> vect){
       
	   cout<<endl<<endl;
	   int j;
	   for(std::vector<char> i : vect){  //range based loop 
	      
	      for(j=0 ; j<i.size();j++){
		 cout<<i[j];
	      }
	      cout<<endl;  
          }          
       }
       
       
       
       
       
       vector<vector<char>> Tetromino::rotate(vector<vector<char>> vect,int direction){
       
	   vector<vector<char>> rotated;

           if(direction == 1){ //Rotates the tetromino left,that is,counter clockwise. (Son sütunu ilk satır yapar(Yukarıdan aşağı şekilde))
		   for(int i=vect[0].size()-1; i>=0;i--){ //column

		      vector<char> tempvect1;

		      for(int j=0 ;j<vect.size();j++){  //row

			 tempvect1.push_back(vect[j][i]);

		      }
		      rotated.push_back(tempvect1);
		   }	   
	   }
	   
	   if(direction == 2){ //Rotates the tetromino right,that is, clockwise. ( İlk sütunu ilk satır yapar(Aşağıdan yukarı şekilde))
	      for(int i=0;i<vect[0].size();i++){
	         vector<char> tempvect1;
	         for(int j=vect.size()-1;j>=0;j--){
	            tempvect1.push_back(vect[j][i]);
	         }
	         rotated.push_back(tempvect1);
	      }
	   }
       
           return rotated;
       }       
       







       bool Tetromino::canFit(vector<vector<char>> tetro,vector<vector<char>> table,int x,int y){ //x ve y koordinat

          int cell_num= tetro.size() * tetro[0].size(); //cell number in tetromino
          auto count=0; //If the count is equal to the number of cells, the tetromino is suitable for that region.
          int tetro_row= tetro.size()-1;  //keeps one less than the number of lines of the given tetromino. Because we start the suitability check from the bottom line.
          int tetro_column= 0;
          
          
	   //compatibility test for the region
          for(int i=x;i>x-tetro.size();i--){ //It enter the loop as many as the tetromino's row number

             for(int j=y;j<tetro[0].size()+y;j++){ //It enter the loop as many as the tetromino's column number

                if(table[i][j] == ' ') count++; //Starting from the last row, we check each column one by one and check for compatibility. If the place to be looked at is empty, we can put the cell we want to put there.
                
                else if(tetro[tetro_row][tetro_column] == ' ') count++;  //If there is no space in the table, that is, if there is a letter, but if the cell of the tetromino we want to place there is a blank, this tetromino is suitable for that region. So we increase the count again.
                else return false; //If both conditions are not met, that area is not suitable for tetromino.
                tetro_column++;
             }
             
             tetro_row--; //I do these operations to understand which cell of the tetromino I check suitability with the table
             tetro_column=0;
          }
          
          
     
          
          //A tetromino can fit exactly in that area, but if there is a space in the bottom line, the bestfit condition cannot be achieved.
          //So I also need to check if there is a space in the bottom line.
          
          //I create a temporary table and sync that temp_table to the table, then add the tetromino that passed the region compatibility test we did above to the temp_table.          
          vector<vector<char>> temp_table= table; //!!böyle bir şey yapabiliyot muyuz emin  değilim.         

          tetro_row= tetro.size()-1;
          tetro_column= 0;
                          
          for(int i=x;i>x-tetro.size();i--){ 

             for(int j=y;j<tetro[0].size()+y;j++){ 
 
                if(temp_table[i][j] == ' ') temp_table[i][j]=tetro[tetro_row][tetro_column];
                
                tetro_column++;
             }             
             tetro_row--; 
             tetro_column=0;
          }

          
          //We check if there is a space in the bottom line in temp_table        
          int is_there_a_space=0;  
          for(int i=0;i<temp_table[0].size()-1;i++){
           
             if(temp_table[x][i] == ' ' && temp_table[x][i+1] != ' '){
                is_there_a_space=1; // If it catches a place with a space and then a letter, it means there is a space left on the bottom line. Then the bestfit status cannot be achieved.
                return false;
             }   
          }
          
          
          
          
          //If the compatibility test for the region is passed and there is no space in the bottom line, then the bestfit status is achieved.
          if( count == cell_num && is_there_a_space == 0){  
             
             table= temp_table;
             return true; 
           
           }
          else return false;
          
       }
       
       
       
       
       


       void Tetromino::putShape(vector<vector<char>> table,vector<Tetromino> tetro_objects){
          
          
          int x=3,y;
          int flag1=0; //When the appropriate region is found in the table and the tetromino is placed there, we change this to 1 and break the while loop.
          int count2=0; //I change the order of the tetrominos if the tetrominos can never be sorted in the entered order without a space on the bottom line. But this cannot be done in any way in entries such as z o z. I'll keep track of how many sorting changes have been made with this variable to prevent the code from crashing. If the maximum number of changes has been reached, I will output that these tetrominos cannot be lined up in the best way.
          
          for(int i1=0;i1<tetro_objects.size();i1++){
             y=0; flag1=0;
             while(1){
		  for(int turn=0;turn<=3;turn++){  //Tetromino will rotate 4 times. If it cannot be placed to the table in all four move, the column i.e. y value will be incremented by 1

		     if(canFit(tetro_objects[i1].our_tetro,table,x,y) == 1){ //Since the conditions are met, I place the parts of the tetromino in the table where the conditions are met.
		        
			  int tetro_row= tetro_objects[i1].our_tetro.size()-1;  
			  int tetro_column= 0;
			  
			  for(int i=x;i>x-tetro_objects[i1].our_tetro.size();i--){ 
			  
			     for(int j=y;j<tetro_objects[i1].our_tetro[0].size()+y;j++){ 
			     
				if(table[i][j] == ' '){ table[i][j]=tetro_objects[i1].our_tetro[tetro_row][tetro_column];

				} 
				tetro_column++;
				
			     }			     
			     tetro_row--; 
			     tetro_column=0;
			     
			  }
			     flag1=1;
			     break; 		  			    
		     }
			  

	             else{ 
	               if(tetro_objects[i1].our_tetro[0][1] != 'T') tetro_objects[i1].our_tetro=rotate(tetro_objects[i1].our_tetro,1);  
	               else{ tetro_objects[i1].our_tetro=rotate(tetro_objects[i1].our_tetro,1); tetro_objects[i1].our_tetro=rotate(tetro_objects[i1].our_tetro,1);} 
	             }
			  
		  }     
                
                 if(flag1 == 1) break; 
                                  

                 if(y < table[0].size()-1) y++;   //If we couldn't place the tetromino in that area of the table by rotating it in that column, I'll try my luck in the next column.
                 
                 //If the y value is greater than one less than the number of columns in the table, all regions in the table have been checked. 
                 //This means that the bestFit status cannot be created with the tetromino sequence entered by the user. 
                 //Then we need to change the order. I move the tetrominos one step to the right. vector[2] equals vector[1], vector[2] replaces vector[3] for example
                 else{   
                                        
                    if(count2 == tetro_objects.size()){ //For example, if there are 4 tetrominos and they are swiped 4 times, all the swipe possibilities are checked. So, if there is no best fit so far, then there is no best fit for this tetromino family.
                       cout<<endl<<"A bestfit condition cannot occur for this tetromino sequence. In any case, there will be a space in the bottom line!!";
                       exit(0);
                    }
                    count2++;
                    
                    vector<vector<char>> temp_vect=tetro_objects[tetro_objects.size()-1].our_tetro;
                    for(int shape_num=tetro_objects.size()-1;shape_num>=0;shape_num--){                     

                       if(shape_num == 0) continue;
                       else tetro_objects[shape_num].our_tetro = tetro_objects[shape_num - 1].our_tetro;                                                                     
                    }                                                          
                   tetro_objects[0].our_tetro=temp_vect;
                   i1=-1; //I change i1 because I want the control to start from the first element of the vector again
       
                   table=table_maker(table[0].size()/4); //reset the table
                   break;
                    
               } 
             }
          }
      
         print(table);
      }       







#endif
