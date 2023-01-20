#ifndef _TETROMINO_
#define _TETROMINO_
#include <iostream>
#include <vector>
#include <unistd.h>
#include <array>
#include "tetromino.h"
#include "tetris.h"




using namespace std;

using namespace tetromino_namespace;


       Tetromino::Tetromino(){}
       
       Tetromino::Tetromino(tetrominos shape_type,char input2){

	         letter = input2;   
	         
	         if(shape_type == tetrominos::I){
	            tetro_row=1; tetro_column=4;
	            
	            our_tetro= new char*[tetro_row];
	            
	            for(int i=0;i<tetro_row;i++) our_tetro[i]= new char[tetro_column];
	            
	            our_tetro[0][0] = 'I';  our_tetro[0][1] = 'I';  our_tetro[0][2] = 'I';   our_tetro[0][3] = 'I';
	         }
	         
	         
	         else if(shape_type == tetrominos::O){
	         
	            tetro_row=2;  tetro_column=2;
	            
	            our_tetro= new char*[tetro_row];
	            
	            for(int i=0;i<tetro_row;i++) our_tetro[i]= new char[tetro_column];
	            
	            our_tetro[0][0] = 'O';   our_tetro[0][1] = 'O';
	            our_tetro[1][0] = 'O';   our_tetro[1][1] = 'O';	            
	         }
	         
	         else if(shape_type == tetrominos::T){
	         
	            tetro_row=2;  tetro_column=3;
	            
	            our_tetro= new char*[tetro_row];
	            
	            for(int i=0;i<tetro_row;i++) our_tetro[i]= new char[tetro_column];
	            
	            our_tetro[0][0] = 'T';   our_tetro[0][1] = 'T';   our_tetro[0][2] = 'T';
	            our_tetro[1][0] = ' ';   our_tetro[1][1] = 'T';   our_tetro[1][2] = ' ';          
	         }
	         	         
	         else if(shape_type == tetrominos::J){

	            tetro_row=3;  tetro_column=2;
	            
	            our_tetro= new char*[tetro_row];
	            
	            for(int i=0;i<tetro_row;i++) our_tetro[i]= new char[tetro_column];
	            
	            our_tetro[0][0] = ' ';   our_tetro[0][1] = 'J';
	            our_tetro[1][0] = ' ';   our_tetro[1][1] = 'J';	
	            our_tetro[2][0] = 'J';   our_tetro[2][1] = 'J';            
	         }
	         	         
	         else if(shape_type == tetrominos::L){

	            tetro_row=3;  tetro_column=2;
	            
	            our_tetro= new char*[tetro_row];
	            
	            for(int i=0;i<tetro_row;i++) our_tetro[i]= new char[tetro_column];
	            
	            our_tetro[0][0] = 'L';   our_tetro[0][1] = ' ';
	            our_tetro[1][0] = 'L';   our_tetro[1][1] = ' ';
	            our_tetro[2][0] = 'L';   our_tetro[2][1] = 'L';	            
	         }
	         	         
	         else if(shape_type == tetrominos::S){

	            tetro_row=2;  tetro_column=3;
	            
	            our_tetro= new char*[tetro_row];
	            
	            for(int i=0;i<tetro_row;i++) our_tetro[i]= new char[tetro_column];
	            
	            our_tetro[0][0] = ' ';   our_tetro[0][1] = 'S';   our_tetro[0][2] = 'S';
	            our_tetro[1][0] = 'S';   our_tetro[1][1] = 'S';   our_tetro[1][2] = ' ';
	            	            
	         }
	         	         
	         else if(shape_type == tetrominos::Z){
	         
	            tetro_row=2;  tetro_column=3;
	            
	            our_tetro= new char*[tetro_row];
	            
	            for(int i=0;i<tetro_row;i++) our_tetro[i]= new char[tetro_column];
	            
	            our_tetro[0][0] = 'Z';   our_tetro[0][1] = 'Z';   our_tetro[0][2] = ' ';
	            our_tetro[1][0] = ' ';   our_tetro[1][1] = 'Z';   our_tetro[1][2] = 'Z';         
	         }
	               
  
       }
       
       
       Tetromino::~Tetromino(){

          for(int i=0 ; i<tetro_row ; i++) delete[] our_tetro[i];
          
          delete [] our_tetro;
          
       }
       




       void Tetromino::print(){
       
	   cout<<endl<<endl;
	   
	   for(int i=0; i<tetro_row; i++){
	   
	      for(int j=0; j<tetro_column; j++){
	         cout<<our_tetro[i][j];
	      }
	      cout<<endl;
	   }
          
       }
       
       
       
       
       
       void Tetromino::rotate(const int direction){
       
	   char** rotated= new char*[tetro_column]; 
	   int temp_row, temp_column; 
	   
	   
           if(direction == 1){ //Rotates the tetromino left,that is,counter clockwise. (Makes the last column the first row (from top to bottom)) (Son sütunu ilk satır yapar(Yukarıdan aşağı şekilde))

		   temp_row= 0; 
		   for(int i=tetro_column-1; i>=0;i--){ //column  

		      rotated[(tetro_column-1)-i] = new char[tetro_row];
		      temp_column = 0;

		      for(int j=0 ;j<tetro_row;j++){  //row   
			 rotated[temp_row][temp_column] = our_tetro[j][i];
			 temp_column++;
		      }
		      temp_row++;
		   }	   
	   }
	      

	   
	   if(direction == 2 ){ //Rotates the tetromino right,that is, clockwise. (Makes the first column the first row (from bottom to top)) (İlk sütunu ilk satır yapar(Aşağıdan yukarı şekilde))
	      
	      temp_row = 0;
	      for(int i=0;i<tetro_column;i++){
	         
	         rotated[i] = new char[tetro_row];
	         temp_column=0;
	         for(int j=tetro_row-1;j>=0;j--){

	            rotated[temp_row][temp_column] = our_tetro[j][i];
	            temp_column++;
	         }
	         temp_row++;
	      }
	   }

	   
	   for (int i = 0; i < tetro_row; i++) delete[] our_tetro[i]; // To delete the inner arrays	                        
		
	   delete[] our_tetro; // To delete the outer array	   
	   
	   int temp = tetro_row;
	   tetro_row = tetro_column;  //When the shape is rotated, the new row value is equal to the column value of its previous version.
	   tetro_column = temp;   //When the shape is rotated, the new column value is equal to the row value of its previous version.

	   our_tetro= new char*[tetro_row];
	            
	   for(int i=0;i<tetro_row;i++){
	   
	      our_tetro[i]= new char[tetro_column];	
	      for(int j=0; j<tetro_column; j++){
	         our_tetro[i][j] = rotated[i][j];
	      }  
	   }      
	   
	   //Freeing the memory allocated to the rotated array
	   for (int i = 0; i < tetro_row; i++) delete[] rotated[i]; // To delete the inner arrays	                        
		
	   delete[] rotated; // To delete the outer array	

       }       
       


       char** Tetromino::get_our_tetro() const{
          return our_tetro;
       }
       
       int Tetromino::get_tetro_row() const{
          return tetro_row;
       }
       
       int Tetromino::get_tetro_column() const{
          return tetro_column;
       }              
       
       char Tetromino::get_letter() const{
          return letter;
       }

	void Tetromino::operator=(const Tetromino& t1){ 

	  if( our_tetro != nullptr){
             for(int i=0 ; i<tetro_row ; i++) delete[] our_tetro[i];
             delete [] our_tetro;
          }

          tetro_row= t1.get_tetro_row();
          tetro_column = t1.get_tetro_column();
          letter = t1.get_letter();

          our_tetro = new char*[tetro_row];

          for(int i=0; i<tetro_row; i++){

             our_tetro[i] = new char[tetro_column];
             for(int j=0; j<tetro_column; j++){
                our_tetro[i][j] = t1.get_our_tetro()[i][j];
             }  
          }
          
	}




#endif
