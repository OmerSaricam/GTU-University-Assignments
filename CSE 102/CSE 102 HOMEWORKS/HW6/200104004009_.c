/*
 ÖMER SARIÇAM 200104004009
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"


void printMap();
/*
* Function: printMap
*
* Prints the globally defined(It's allowed) map[][] array to the screen.
*
* returns: nothing
*/

int dice();
/*
* Function: dice 
*
* Generates random numbers in the range of 1-6 and assign it to the variable named random
*
* returns: variable named random
*/

int startGame();
/*
* Function: startGame
*
* Call dice function twice. Assign one to variable a and the other one to variable b. Compares to variables.
*
* returns: 1 if a is greater than b, 2 otherwise. If they are equal, the loop continues. 
*/

int map[15][30];

int main(){

   int i,j;
   
   /* 
      In this part, I assigned the ASCII values of the required characters to the array,
      in the required places in the Map.
   */
   
   for(i=0;i<15;i++){
   
      for(j=0;j<30;j++){
      
         if(i==0 || i==14)
            map[i][j]=45;  //45: ASCII Value of '-' 
         else if(j==0 || j==29)
            map[i][j]=124; //124: ASCII Value of '|' 
         else if(i==1 && j==1)
            map[i][j]=49;  //49: ASCII Value of '1'
         else if(i==3 && j==3)
            map[i][j]=50;  //50: ASCII Value of '2'
         else if((i==1 && j==14) || (i==7 && j==28) || (i==13 && j==14) || (i==3 && j==10) || (i==3 && j==18) || (i==5 && j==26) || (i==10 && j==26) || (i==11 && j==10) || (i==11 && j==18 ))
            map[i][j]=88;  //88: ASCII Value of 'X'
         else if((i==2 && j==1) || (i==4 && j==3))
            map[i][j]=95;  //95: ASCII Value of '_'
         else 
            map[i][j]=32;  //32: ASCII Value of space character
                                            
      }   
   }
   
   for(i=2;i<=12;i++){         // I assigned the road lines in the middle of the map to the array.
                               
      for(j=2;j<=27;j++){
         
         if(i==2 || i==12)
            map[i][j]=45;  //45: ASCII Value of '-' 
         else if(j==2 || j==27)
            map[i][j]=124; //124: ASCII Value of '|'   
      }   
   }
   
   for(i=4;i<=10;i++){         // I assign the innermost path lines to the array.
   
      for(j=4;j<=25;j++){
      
         if(i==4 || i==10)
            map[i][j]=45;
         else if(j==4 || j==25)
            map[i][j]=124;   
      }
   }
   
   printMap();
   
   
   int who=startGame(); // Keeps the information of who will start the game.1 for player1, 2 for player2
   printf("\n***Player %d will start the game.***\n\n",who);
   int a1,a2;           // a1 keeps the dice value of player1 and a2 keeps the dice value of player2
   int x1=1,y1=1,x2=3,y2=3;  // x1,y1:Player1's row and column  x2,y2:Player2's row and column
   int temp;
   char ch;
   int flag1=0,flag2=0; // To check if player1 or player2 have reached the finish line
   
   
   do{
   
      printf(ANSI_COLOR_YELLOW "\nPlayer1... press ENTER to dice..." );
      ch=fgetc(stdin);  // Detects if the user pressing Enter
      a1=dice();
      printf("\nDICE: %d",a1);     
      //printf(ANSI_COLOR_RESET);

      printf(ANSI_COLOR_BLUE "\nPlayer2... press ENTER to dice...");
      ch=fgetc(stdin);  // Detects if the user pressing Enter
      a2=dice();
      printf("\nDICE: %d",a2); 
      printf(ANSI_COLOR_RESET);  // Resets the color selection

      // This if structure is for player1
            
      if(x1==1 && y1+a1<=28){
         
         if(map[1][y1+a1]==88){            // If its destination is where X is, it is penalized for taking 2 steps back
            temp=map[1][y1];                
            map[1][y1]=map[1][y1+a1-2];
            map[1][y1+a1-2]=temp;
            y1=y1+a1-2;  
            printf(ANSI_COLOR_RED "\nPenalty for player 1..");  
            printf(ANSI_COLOR_RESET);  // Resets the color selection    
         }
         else{
            temp=map[1][y1];
            map[1][y1]=map[1][y1+a1];
            map[1][y1+a1]=temp;
            y1=y1+a1;                   
         }      
      }
      
      else if(y1+a1>=28 && x1+a1<=13){
         
         
         if(28-y1>0){             // If the column of the destination is more than 28, it will cause it to go out of the limits
            a1=a1-(28-y1);        // So I readjusted the value of a1 and set it to move in the column
            temp=map[x1][y1];
            map[x1][y1]=map[1][28];
            map[1][28]=temp;
            y1=28;                        
         }
         
         if(map[x1+a1][28] == 88){
            temp=map[x1][28];
            map[x1][28]=map[x1+a1-2][28];
            map[x1+a1-2][28]=temp;
            x1=x1+a1-2;
            printf(ANSI_COLOR_RED "\nPenalty for player 1..");  
            printf(ANSI_COLOR_RESET);  // Resets the color selection             
         }
         
         else{
            temp=map[x1][28];
            map[x1][28]=map[x1+a1][28];
            map[x1+a1][28]=temp;
            x1=x1+a1;         
         }
      }
      
      else if(x1+a1>=13 && y1-a1>=1){ 
         
         if(13-x1>0){             // If the row of the destination is more than 13, it will cause it to go out of the limits
            a1=a1-(13-x1);        // So I readjusted the value of a1 and set it to move in the row
            temp=map[x1][y1];
            map[x1][y1]=map[13][28];
            map[13][28]=temp;
            x1=13;
         } 
         
         if(map[13][y1-a1] == 88){
            temp=map[13][y1];
            map[13][y1]=map[13][y1-a1+2];
            map[13][y1-a1+2]=temp;
            y1=y1-a1+2; 
            printf(ANSI_COLOR_RED "\nPenalty for player 1..");  
            printf(ANSI_COLOR_RESET);  // Resets the color selection         
         }
         else{
            temp=map[13][y1];
            map[13][y1]=map[13][y1-a1];
            map[13][y1-a1]=temp;
            y1=y1-a1;            
         }
      }
      
      else if(y1-a1<=1 ){ 

         if(y1-1>0){              // If the column of the destination is less than 1, it will cause it to go out of the limits    
                                  // So I readjusted the value of a1 and set it to move in the column
            a1=a1-(y1-1);
            temp=map[x1][y1];
            map[x1][y1]=map[13][1];
            map[13][1]=temp; 
            y1=1;
         }

         if(x1-a1<=2 ){ 
            flag1=1;
            temp=map[x1][1];
            map[x1][1]=map[3][1];
            map[3][1]=temp;
         
         }
         else{   
            temp=map[x1][1];
            map[x1][1]=map[x1-a1][1];
            map[x1-a1][1]=temp;
            x1=x1-a1; 
        }    
          
      }
      
      // This if structure is for player2
      
      if(x2==3 && y2+a2<=26){
         
         if(map[3][y2+a2]==88){
            temp=map[3][y2];
            map[3][y2]=map[3][y2+a2-2];
            map[3][y2+a2-2]=temp;
            y2=y2+a2-2;  
            printf(ANSI_COLOR_RED "\nPenalty for player 2.."); 
            printf(ANSI_COLOR_RESET);  // Resets the color selection     
         }
         else{
            temp=map[3][y2];
            map[3][y2]=map[3][y2+a2];
            map[3][y2+a2]=temp;
            y2=y2+a2;                   
         }      
      }
      
      else if(y2+a2>=26 && x2+a2<=11){
         
         
         if(26-y2>0){                 // If the column of the destination is more than 26, it will cause it to go out of the limits
            a2=a2-(26-y2);            // So I readjusted the value of a1 and set it to move in the column
            temp=map[x2][y2];
            map[x2][y2]=map[3][26];
            map[3][26]=temp;
            y2=26;                        
         }
         
         if(map[x2+a2][26] == 88){
            temp=map[x2][26];
            map[x2][26]=map[x2+a2-2][26];
            map[x2+a2-2][26]=temp;
            x2=x2+a2-2;
            printf(ANSI_COLOR_RED "\nPenalty for player 2.."); 
            printf(ANSI_COLOR_RESET);                 
         }
         
         else{
            temp=map[x2][26];
            map[x2][26]=map[x2+a2][26];
            map[x2+a2][26]=temp;
            x2=x2+a2;         
         }
      }
      
      else if(x2+a2>=11 && y2-a2>=3){ 
         
         if(11-x2>0){                // If the row of the destination is more than 11, it will cause it to go out of the limits
            a2=a2-(11-x2);           // So I readjusted the value of a1 and set it to move in the row
            temp=map[x2][y2];
            map[x2][y2]=map[11][26];
            map[11][26]=temp;
            x2=11;
         } 
         
         if(map[11][y2-a2] == 88){
            temp=map[11][y2];
            map[11][y2]=map[11][y2-a2+2];
            map[11][y2-a2+2]=temp;
            y2=y2-a2+2; 
            printf(ANSI_COLOR_RED "\nPenalty for player 2.."); 
            printf(ANSI_COLOR_RESET);            
         }
         else{
            temp=map[11][y2];
            map[11][y2]=map[11][y2-a2];
            map[11][y2-a2]=temp;
            y2=y2-a2;            
         }
      }
      
      else if(y2-a2<=3 ){ 

         if(y2-3>0){                // If the column of the destination is less than 3, it will cause it to go out of the limits
                                    // So I readjusted the value of a1 and set it to move in the column
            a2=a2-(y2-3);
            temp=map[x2][y2];
            map[x2][y2]=map[11][3];
            map[11][3]=temp;
            y2=3;
         }

         if(x2-a2<=4 ){ 
            flag2=1;
            temp=map[x2][3];
            map[x2][3]=map[5][3];
            map[5][3]=temp;         
         }
         else{   
            temp=map[x2][3];
            map[x2][3]=map[x2-a2][3];
            map[x2-a2][3]=temp;
            x2=x2-a2; 
         }   
      }      
      
      printf("\n");
      printMap(); 
      printf("\n");
      
      if(who == 1){
         if(flag1 == 1){ printf("\n\n\n\t***PLAYER 1 WON THE GAME!!***"); break;}
         else if(flag2 == 1){ printf("\n\n\n\t***PLAYER 2 WON THE GAME!!***"); break;} 
      }
      else if(who == 2){
         if(flag2 == 1){ printf("\n\n\n\t***PLAYER 2 WON THE GAME!!***"); break;}
         else if(flag1 == 1){ printf("\n\n\n\t***PLAYER 1 WON THE GAME!!***"); break;} 
      }      
              
   }while(1);

   printf("\n\n-----------GAME OVER-----------\n\n");
}


void printMap(){

   int i,j;
   
   for(i=0;i<15;i++){
      
      for(j=0;j<30;j++){
         
         if(map[i][j] == 88){ printf(ANSI_COLOR_RED" %c",map[i][j]); printf(ANSI_COLOR_RESET); }
         else if(map[i][j] == 49){ printf(ANSI_COLOR_YELLOW" %c",map[i][j]); printf(ANSI_COLOR_RESET); }
         else if(map[i][j] == 50){ printf(ANSI_COLOR_BLUE" %c",map[i][j]); printf(ANSI_COLOR_RESET); }
         else printf(" %c",map[i][j]);      
      }
      printf("\n");
   
   }
}


int dice(){

   srand(time(NULL));
   int random=rand()%6+1;
   return random;
}



int startGame(){

   int a,b;
   char ch;
   printf("\n\nTo start the game,players should dice and decide who is going to start  first according to it...");
   do{
      printf(ANSI_COLOR_YELLOW "\nPlayer1... press ENTER to dice...");
      //scanf(" %c",&ch);
      ch=fgetc(stdin);  // Detects if the user pressing Enter
      a=dice();
      printf("\nDICE: %d",a);

      printf(ANSI_COLOR_BLUE "\nPlayer2... press ENTER to dice...");
      //scanf(" %c",&ch);
      ch=fgetc(stdin);
      b=dice();
      printf("\nDICE: %d",b);
      printf(ANSI_COLOR_RESET);  // Resets the color selection     
      
      if(a==b) printf("\nSame dice value, please try again.");
      else if(a>b) return 1;
      else return 2;  
   
   }while(a == b);
   
}
