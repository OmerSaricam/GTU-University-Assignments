#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define STACK_BLOCK_SIZE 10

typedef struct{
   int *array;
   int currentsize; 
   int maxsize; 
}stack;

int size;

int push(stack * s, int d); /* the stack array will grow STACK_BLOCK_SIZE entries at a time */
/*
* Function: push
*
* To Do: inserts an element at the top of the stack.
*
* returns: -999 if the stack is full,1 otherwise 
*/

int pop(stack * s); /* the stack array will shrink STACK_BLOCK_SIZE entries at a time */
/*
* Function: pop
*
* To Do: removes an element from the top of the stack
*
* returns: -998 if the stack is empty
*/

stack * init_return();
/*
* Function: init_return
*
* To Do: initializes an empty stack
*
* Returns: the stack it created
*/

int init(stack * s); /* returns 1 if initialization is successful*/

void print_op(int a1,int a2,stack *left,stack *mid,stack *right);
/*
* Function: print_op
*
* To Do: It takes the necessary parameters and prints the wanted things to the screen
*
* Returns: 1 if initialization is successful
*/


int main(){

   printf("\nEnter tower size: ");
   scanf("%d",&size);
   
   stack *left,*mid,*right;
   
   //Stack initializing for bars
   left= init_return();  
   mid= init_return(); 
   right= init_return();
         
   int i;
   for(i=size;i>=1;i--){    
      push(left,i);
   } 
   
   int k;
   int a1,a2;
    
   if(size%2 == 1){
      for(k=1;k < pow(2,size) ;k++){
         a1=(k&k-1)%3;     //Determining which stack to get disk from 
         a2=((k|k-1)+1)%3; //Determining on which stack the received disk will be placed 
         
      print_op(a1,a2,left,mid,right); 
      }
   
   } 
   
   //Size, that is, if the number of disks is even, the process is modified.
   else if(size%2 == 0){

      for(k=1;k < pow(2,size) ;k++){
         a1=(k&k-1)%3;     //Determining which stack to get disk from 
         a2=((k|k-1)+1)%3; //Determining on which stack the received disk will be placed 

         if(a1 == 1) a1=2;
         else if(a1==2) a1=1;
         if(a2 == 1) a2=2;
         else if(a2 == 2) a2=1;
         
         print_op(a1,a2,left,mid,right);
    
      }
   
   }    
   
}


int push(stack *s, int d){ 
 
   if ((s->currentsize == s->maxsize  )) return -999; //Checking if stack is full or not 	
   if(size>=STACK_BLOCK_SIZE)    s->array = realloc(s->array,sizeof(int)*size*2);
       	 
   s -> array[++(s -> currentsize)] = d; //d value is added to the stack
   return 1;
} 


int pop(stack* s){

   if ((s->currentsize == 0)) return -998; // If currentsize is -1, it means the stack is empty. 		 
   return s -> array[(s -> currentsize)--]; //Returns the value at the top of the stack
} 


stack * init_return(){
   
   stack *s= (stack*)malloc(sizeof(stack));
   init(s); //Checking if the stack is initialized correctly
   s->currentsize=0;
   s->maxsize=STACK_BLOCK_SIZE;
   s->maxsize=size;
   s->array=(int*)malloc(sizeof(int)*s->maxsize);
   return s;
}


void print_op(int a1,int a2,stack *left,stack *mid,stack *right){

         
   int value;
   switch(a1){
    
      case 0: //The disc is taken from the left bar(stack)
         value=pop(left);
         printf("\nMove the disk %d from '%d' to '%d' ",value,a1+1,a2+1);
         break;
      case 1: //The disc is taken from the mid bar(stack) 
         value=pop(mid);
         printf("\nMove the disk %d from '%d' to '%d' ",value,a1+1,a2+1);
         break;
      case 2: //The disc is taken from the right bar(stack) 
         value=pop(right);
         printf("\nMove the disk %d from '%d' to '%d' ",value,a1+1,a2+1);
         break;
   }

   switch(a2){
    
      case 0: //The disc is put on the left bar(stack) 
         push(left,value);
         break;
      case 1: //The disc is put on the mid bar(stack) 
         push(mid,value);
         break;
      case 2: //The disc is put on the right bar(stack) 
         push(right,value);
         break;
   }   

}


int init(stack *s){
   
   if(s == NULL){
      printf("\ninitialization is not successful");
      return -997;
   }   
   else return 1;
}
