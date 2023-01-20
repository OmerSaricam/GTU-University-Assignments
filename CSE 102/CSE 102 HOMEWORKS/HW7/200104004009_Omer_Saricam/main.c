#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//You can activate the comment line on line 192 to find out where the words are.

int coordinatefinder(int);
/*
* Function: coordinatefinder
*
* Its purpose is to arrange the row and column coordinates of the first letter of the word in the board array.
*
* returns: an integer between 0 and 14
*/

int control1(int row,int column,int length,int style);
/*
* Function: control1
*
* It checks if there are any other letters in the region where the word will be placed. 
*
* returns: 1 if a letter is found, 0 otherwise.
*/

int control2(int row,int column, char word2[],int length);
/*
* Function: control2
*
* It is checked whether word2 string is in the specified (row, column) coordinate. All directions are checked.
* If the specified string is found, the letters in the string are replaced with the character X.
*
* returns: 1 if true 0 otherwise
*/

void printboard();
/*
* Function: printboard
*
* Prints the board array as a 2D table
*
* returns: nothing
*/

char board[15][15];


int main(){

   //Assigning the words in the file to the string array named words[][]
   char words[50][10];
   int i=0;
   char word[10];
   FILE *fp=fopen("wordlist.txt","r"); 
   while(!feof(fp)){
      
      fscanf(fp,"%s",word);
      
      strcpy(words[i],word);
      i++;   
   }
   

  //Choosing 7 random numbers between 0 and 50
  srand(time(NULL));
  int a1[7];
  int j;
  for(i=0;i<7;i++){
     a1[i]=rand()%50;
     
     if(i != 0){
        for(j=0;j<i;j++){
           if(a1[i] == a1[j]){
              a1[i]=rand()%50;
           }                  
        }
     }        
  }

  //Assigning 7 different words obtained by 7 random numbers to sevenwords[][] array   
  char sevenwords[7][10];
  for(i=0;i<7;i++){
     strcpy(sevenwords[i],words[a1[i]]);
  } 

   //Making every element of the board array 0
   for(i=0;i<15;i++){
      
      for(j=0;j<15;j++){
         board[i][j]='0';
      }
   }  

  //Randomly placing the words in the sevenwords array into the table(board array)
  
  int row,column,length,style,controll1;
  
  /*
  The style variable takes random values from 1 to 8 and these values mean:
  1: left to right
  2: right to left
  3: from top to bottom
  4: from bottom to up
  5: from the upper left corner to the lower right corner
  6: from the lower right corner to the upper left corner
  7: from the upper right corner to the lower left corner
  8: from the lower left corner to the upper right corner  
  
  It determines how the word will be placed.
  */

  for(i=0;i<7;i++){
     
     row=rand()%15; column=rand()%15;
     style=rand()%8+1;
     length=strlen(sevenwords[i]);

     
     if(style == 1){ //left to right
        while(column+length >14 || control1(row,column,length,style) == 1){
           column=coordinatefinder(column); row=coordinatefinder(row);
        }
        for(j=0;j<length;j++){
           board[row][column+j]=sevenwords[i][j];
        }
     }
     
     else if(style == 2){ //right to left
        while(column-length <0 || control1(row,column,length,style) == 1){
           column=coordinatefinder(column); row=coordinatefinder(row);
        }
        for(j=0;j<length;j++){
           board[row][column-j]=sevenwords[i][j];
        }
     }
     
     else if(style == 3){ //from top to bottom
        while(row+length >14 || control1(row,column,length,style) == 1){
           column=coordinatefinder(column); row=coordinatefinder(row);
        }
        
        for(j=0;j<length;j++){
           board[row+j][column]=sevenwords[i][j];
        }
     }     

     else if(style == 4){ //from bottom to up
        while(row-length < 0 || control1(row,column,length,style) == 1){
           column=coordinatefinder(column); row=coordinatefinder(row);
        }
        for(j=0;j<length;j++){
           board[row-j][column]=sevenwords[i][j];
        }
     }
     
     else if(style == 5){ //from the upper left corner to the lower right corner
        while(row+length >14 || column+length >14 || control1(row,column,length,style) == 1){
           column=coordinatefinder(column); row=coordinatefinder(row);
        }
        for(j=0;j<length;j++){
           board[row+j][column+j]=sevenwords[i][j];
        }
     }          
     
     else if(style == 6){ //from the lower right corner to the upper left corner
        while(row-length <0 || column-length <0 || control1(row,column,length,style) == 1){
           column=coordinatefinder(column); row=coordinatefinder(row); 
        }
        for(j=0;j<length;j++){
           board[row-j][column-j]=sevenwords[i][j];
        }
     }         
     
     else if(style == 7){ //from the upper right corner to the lower left corner
        while(row+length >14 || column-length <0 || control1(row,column,length,style) == 1){ 
           column=coordinatefinder(column); row=coordinatefinder(row);
        }
        for(j=0;j<length;j++){
           board[row+j][column-j]=sevenwords[i][j];
        }
     }    

     else if(style == 8){ //from the lower left corner to the upper right corne
        while(row-length <0 || column+length >14 || control1(row,column,length,style) == 1){
           column=coordinatefinder(column); row=coordinatefinder(row);
        }
        for(j=0;j<length;j++){
           board[row-j][column+j]=sevenwords[i][j];
        }
     }
     
     //You can activate the comment line below to learn where the words are.
     printf("\n%d. kelime: %s / rc:%d,%d style: %d\n",i,words[a1[i]],row,column,style); 
                   
  }
  
  //Assigning random numbers to the remainders
  for(i=0;i<15;i++){
  
     for(j=0;j<15;j++){
        if(board[i][j] == '0')
           board[i][j] = rand()%26+97; //BASED ON ASCII VALUE(97-122)
     }
  }

   
   //PART 2
   char word2[10];
   char rowc[5],columnc[5]; 
   int flag2,counter=0,mistakecounter=0;
   int flag3; //It checks whether the string that word 2 is holding is one of the seven words array elements.

   while(mistakecounter != 3 && counter != 3){
      
      
      printf("\n");
      printboard();
      printf("\nEnter coordinates and words: ");

      scanf(" %s",rowc);
      if(strcmp(rowc,":q") == 0){ printf("\nYou have chosen to exit."); break; } //If :q input is received from the user, the program terminates
      else sscanf(rowc,"%d",&row); //What is entered in the rows string is converted to an integer value
      
      scanf(" %s",columnc);
      if(strcmp(columnc,":q") == 0){ printf("\nYou have chosen to exit."); break; }
      else sscanf(columnc,"%d",&column);

      scanf(" %s",word2);
      if(strcmp(word2,":q") == 0){ printf("\nYou have chosen to exit."); break; }
      
      flag3=0;
      for(i=0;i<7;i++){
            if(strcmp(word2,sevenwords[i]) == 0) flag3=1;
      }
      
      if(flag3 == 0){
         mistakecounter++;
         printf("\nWrong choice! You have only %d lefts",3-mistakecounter);      
      }
      
      else if(flag3 == 1){
           
      length=strlen(word2);
      flag2= control2(row,column,word2,length);
      
      if(flag2 == 1){
         counter++;
         printf("\nFounded!You got 2 points. Your total points: %d",counter*2);
      }
      else{
         mistakecounter++;
         printf("\nWrong choice! You have only %d lefts",3-mistakecounter);
      } 
      
      }
            
   }
   if(counter == 3) printf("\nYou win the game");
   if(mistakecounter == 3) printf("\nYou lose the game");
    
            
}


int coordinatefinder(int coordinate){ 

   coordinate=rand()%15;
   return coordinate;   
}


int control1(int row,int column,int length,int style){ 

   int i;
   switch(style){
   
      case 1:
         for(i=0;i<length;i++){
            if(board[row][column+i] != '0') return 1; 
         }
         break;
      
      case 2:
         for(i=0;i<length;i++){
            if(board[row][column-i] != '0') return 1;
         }
         break;
         
      case 3:      
         for(i=0;i<length;i++){
            if(board[row+i][column] != '0') return 1;
         }  
         break;
      
      case 4:
         for(i=0;i<length;i++){
            if(board[row-i][column] != '0') return 1;
         }
         break;
      
      case 5: 
         for(i=0;i<length;i++){
            if(board[row+i][column+i] != '0') return 1;
         }
         break;
      
      case 6: 
         for(i=0;i<length;i++){
            if(board[row-i][column-i] != '0') return 1;
         }
         break;
      case 7:
         for(i=0;i<length;i++){
            if(board[row+i][column-i] != '0') return 1;
         }
         break;
         
      case 8:
         for(i=0;i<length;i++){
            if(board[row-i][column+i] != '0') return 1;
         } 
         break;           
   }
   
   return 0;
}


int control2(int row,int column, char word2[],int length){ 

   int i;
   char comp[10];
   for(i=0;i<length;i++) comp[i]= board[row][column+i];  //style 1    
   comp[length]='\0';
   if(strcmp(comp,word2) == 0){  
   //If the specified string is found at the specified coordinate, the letters of that string are replaced with the character X 
      for(i=0;i<length;i++) board[row][column+i]='X';     
      return 1;     
   }

   for(i=0;i<length;i++) comp[i]= board[row][column-i];  //style 2   
   comp[length]='\0';
   if(strcmp(comp,word2) == 0){
      for(i=0;i<length;i++) board[row][column-i]='X';  
      return 1;  
   }

   for(i=0;i<length;i++) comp[i]= board[row+i][column];  //style 3
   comp[length]='\0';
   if(strcmp(comp,word2) == 0){
      for(i=0;i<length;i++) board[row+i][column]='X';    
      return 1;  
   }

   for(i=0;i<length;i++) comp[i]= board[row-i][column];  //style 4
   comp[length]='\0';
   if(strcmp(comp,word2) == 0){
      for(i=0;i<length;i++) board[row-i][column]='X'; 
      return 1;  
   }

   for(i=0;i<length;i++) comp[i]= board[row+i][column+i]; //style 5
   comp[length]='\0';
   if(strcmp(comp,word2) == 0){
      for(i=0;i<length;i++) board[row+i][column+i]='X';     
      return 1;  
   }

   for(i=0;i<length;i++) comp[i]= board[row-i][column-i];  //style 6
   comp[length]='\0';
   if(strcmp(comp,word2) == 0){
      for(i=0;i<length;i++) board[row-i][column-i]='X';   
      return 1;  
   }

   for(i=0;i<length;i++) comp[i]= board[row+i][column-i]; //style 7
   comp[length]='\0';
   if(strcmp(comp,word2) == 0){
      for(i=0;i<length;i++) board[row+i][column-i]='X';   
      return 1;  
   }

   for(i=0;i<length;i++) comp[i]= board[row-i][column+i];  //style 8
   comp[length]='\0';
   if(strcmp(comp,word2) == 0){
      for(i=0;i<length;i++) board[row-i][column+i]='X';    
      return 1;  
   }

   return 0;

}


void printboard(){

   int i,j;
   for(i=0;i<15;i++){
      
      for(j=0;j<15;j++){
         printf(" %c",board[i][j]);
         
      }
      printf("\n");
   } 

}
