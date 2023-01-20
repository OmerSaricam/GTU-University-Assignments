#include <stdio.h>
#include <stdlib.h>
#include "util.h"


int main(){

   int i;
   int seqlen,xs,currentlen; 
   printf("\nPlease enter the sequence length: ");
   scanf("%d",&seqlen);   //takes the size of the sequence 
   printf("\nPlease enter the first element: ");
   scanf("%d",&xs);  //takes the first element  
   
   //PART 2-3
   int a1;
   int *loop,*looplen=&a1;
   *looplen=seqlen/2+1;
   loop=(int *)calloc(*looplen, sizeof(int));
   check_loop_iterative(generate_sequence,xs,seqlen,loop,looplen);
   
   if(*looplen == 1) printf("\nNo loop found."); //If there is no loop, prints this information. 
   else{                        //prints the loop (if any). 
      printf("\nLoop: {");
      for(i=0;i<*looplen;i++){
         printf("%d ,",loop[i]);
      }
      printf("\b}");
   }
   
   
   //PART 4
   printf("\n");
   int* h;
   h=(int *)calloc(10, sizeof(int));  

   for(i=0;i<9;i++){ //I equate all values of array h to zero(The calloc function also does this, but I wanted to make it sure)
      h[i]=0;
   }

   int digit= seqlen;
   hist_of_firstdigits(generate_sequence,xs,seqlen,h,digit);  //Calls the hist_of_firstdigits function. 
   printf("\nHistogram of sequence: { ");
   for(i=1;i<10;i++) printf("%d ,",*(h+i)); //Prints the histogram array
   printf("\b}");
}



