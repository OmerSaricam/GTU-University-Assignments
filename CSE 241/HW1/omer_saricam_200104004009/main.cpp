#include <iostream>
#include <vector>
#include "tetris.h"


using namespace std;


int main(){
 
   int number1;
   while(1){   //This is how I get the input for error checking
      cout<<endl<<"How many tetrominos?";
      char input1;
      cin>>input1;
      if(int(input1) >=48 && int(input1) <= 57){
         number1= int(input1) - 48;
         cin.ignore(2,'\n');
         break;
      }
      
      else cout<<endl<<"Input is not valid. Try again!";
      cin.ignore(2,'\n');

   }
   


   tetrominos types2[number1]; //I will store the char inputs entered by the user in this enum class array.
   
   
   Tetromino t1(types2,number1);
   
   int i; 
   cout<<endl<<"Your tetrominos: ";
   for(i=0; i<t1.types1.size();i++){ //printing the entered tetrominos one by one
      
      t1.print(t1.types1[i]);  
   }
   
   

   vector<vector<char>> table= table_maker(number1); 
   
   cout<<endl<<"Horizontally best-fit tetrominos: "<<endl;
   t1.putShape(table);
   
                                  
 
}

