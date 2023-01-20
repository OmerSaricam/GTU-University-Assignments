#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void generate_sequence(int xs, int currentlen, int seqlen, int *seq){
   
   if(currentlen == seqlen) return; //The function is terminated when there are as many array elements in the seq array as the seqlen value

   if(xs % 2 == 0){
      *(seq+currentlen) = xs/2;
      generate_sequence(xs/2,currentlen+1,seqlen,seq);
      return;
   }
   
   else if(xs %2 == 1){
      *(seq+currentlen) = (3*xs)+1;
      generate_sequence((3*xs)+1,currentlen+1,seqlen,seq);
      return;
   }

}



void check_loop_iterative(void (*f)(int,int,int,int*), int xs, int seqlen, int *loop,int *looplen){

   int i;
   (*looplen)--;
   if(*looplen == 1) return;
   
   int currentlen=1;
   int* seq;
   seq=(int *)calloc(seqlen, sizeof(int));  
   seq[0]=xs; 
   f(xs,currentlen,seqlen,seq); //generates the sequence     

   if(*looplen == seqlen/2){  //prints the sequence (prints it only once)
      printf("\n\n");
      printf("\nSequence: { ");
      for(i=0;i<seqlen;i++){
         //printf("%d ,",seq[i]);
         printf("%d ,",*(seq+i));
      } 
      printf("\b}");  
      printf("\n");
   }
   
   int n=seqlen;
   int ls1,le1;
   int *ls=&ls1,*le=&le1;
   
   printf("\nChecking if there is a loop of length %d...",*looplen);
   
   if(has_loop(seq,n,*looplen,ls,le) == 1){ //Checks if the sequence has a loop
      printf("\n");
      printf("\nLoop detected with a length of %d",*looplen);
      printf("\nThe indexes of the loop's first occurrence: %d (first digit), %d (last digit)",*ls,*le);
 
      for(i=0;i<*looplen;i++){
         loop[i]=seq[(*ls)+i]; //This assignment was made because the loop was requested to be printed in main.
      }
      return;
   }
   
   else check_loop_iterative(generate_sequence,xs,seqlen,loop,looplen);    
   return;
}

int has_loop(int *arr, int n, int looplen, int *ls, int *le){

   *ls=0; *le=looplen;
   int i,counter2;

   while(*le != n){ //When the value of le reaches the length of the sequence,that is,one more than the end-of-array index,the program terminates
      counter2=0;
      for(i=*ls;i<*le;i++){
         if(arr[i] == arr[i+looplen]) counter2++; 
      }
      if(counter2 == looplen) return 1;
      (*ls)++; (*le)++;
          
   }   
   return 0; 
}


void hist_of_firstdigits(void (*f)(int,int,int,int*), int xs, int seqlen, int *h, int digit){ 

   if(digit == 0) return;
   
   int currentlen=1;
   int* seq;
   seq=(int *)calloc(seqlen, sizeof(int));  
   seq[0]=xs; 
   f(xs,currentlen,seqlen,seq);  //generates the sequence

   
   int basamaksayisi=digitfinder(seq[digit-1]);
   int i,firstdigit;
   firstdigit=seq[digit-1];
   for(i=1;i<basamaksayisi;i++){ //Finds the first digit
      firstdigit=firstdigit/10;
   }
   h[firstdigit]++; 
   
   hist_of_firstdigits(generate_sequence,xs,seqlen,h,digit-1);
   return;   
}


int digitfinder(int a){ // It calculates the number of digits of the integer a which it takes as a parameter

   int counter1=1;
   while(a/10 != 0){
      counter1++; 
      a=a/10;  
   }
   
   return counter1;
}
