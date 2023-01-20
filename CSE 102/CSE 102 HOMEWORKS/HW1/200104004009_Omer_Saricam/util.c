#include <stdio.h>
#include "util.h"

int find_divisible(int x, int y, int z){

   int i,output=0;
   
   for(i=x+1;i<y;i++){  //I DO NOT INCLUDE LIMITS BECAUSE THE VALUES IN BETWEEN ARE REQUESTED
      if(i%z==0){
         output=1;
         return i;
      }   
   }
   if(output==0)
      return -1;   
}

int find_nth_divisible(int n, int f_I, int z){
    
      int i=0;     
      int j;      
      for(j=f_I+1;j!=-1;j++){

         if(j%z == 0)
            i++;
        
         if(i==n+1)
            return j;     
      }
}


int validate_identity_number(char identity_number [ ]){

   //THE PART THAT CHECKS IF THE ID NUMBER IS 11 DIGIT
   int bigcounter=0; //The variable I defined to control that the id number passed all tests successfully
   int i,counter=0;
   for(i=0;i<100;i++){
      if(identity_number[i]=='\0')
         break;
      counter++;   
           
   }

   if(counter != 11)
      return 0;
   else
      bigcounter++;


    
   //THE PART THAT CHECKS THAT EVERY DIGIT IS A NUMBER
   for(i=0;i<11;i++){
      if(!(identity_number[i]>=48 && identity_number[i]<=57))
         return 0;
      
   
   }
   bigcounter++;
   
   
   //THE PART THAT CHECKS IF THE FIRST DIGIT IS 0
   if(identity_number[0]-48 == 0)
      return 0;
   bigcounter++;
   
   //4. CONTROL PART
   int variable4=7*((identity_number[0]-48)+(identity_number[2]-48)+(identity_number[4]-48)+(identity_number[6]-48)+(identity_number[8]-48))-((identity_number[1]-48)+(identity_number[3]-48)+(identity_number[5]-48)+(identity_number[7]-48));

   
   
   if(variable4 %10 !=(identity_number[9]-48))
      return 0;
   bigcounter++;   
   
         
   //5. CONTROL PART
   int variable5=0;
   for(i=0;i<=9;i++){
   
      variable5 += identity_number[i]-48;
   }
   
   if(variable5 %10 != identity_number[10]-48)
      return 0;
   bigcounter++;   
   
      
   if(bigcounter==5)  
      return 1;
      
}


int create_customer(char identity_number [ ], int password){

   FILE *file;
   
   file=fopen("customeraccount.txt","w");
   fprintf(file,"%s,%d",identity_number,password);
   fclose(file);

}


int check_login(char identity_number [ ], int password){

   FILE *dosya;
   dosya=fopen("customeraccount.txt","r");
   
   int i=0;
   char karakter;
   
   while(karakter != ','){
      karakter=fgetc(dosya);
      if(karakter==',')
         break;
      
      if(karakter!=identity_number[i])
         return 0;
      i++; 
           
   }
   
   int j=1,k;
   int karakter2;
   int sum=0;
   while(karakter != EOF){
      karakter=fgetc(dosya); //FILE READING CONTINUES FROM WHERE IT LEFT.
      if(karakter==EOF)
         break;

      karakter2=karakter-48; //I FIND REEL NUMBER VALUE OF THE KARAKTER VARIABLE

      if(j<4){
         //karakter2*=10;
         for(k=4;k>j;k--){
            karakter2*=10;
         }     
      }
      j++;
      
      sum+=karakter2;

              
         
   }
   
   if(sum != password)
         return 0;
         
   fclose(dosya);      
   return 1;

}


int withdrawable_amount(float cash_amount){

   int cash=cash_amount;                 /*SINCE THER IS NO REQUIREMENT THAT THE FUNCTION SHOULD RETURN A NUMBER IN THIS PART
                                           I ALSO DID THE PRINTF OPERATION HERE.   */
   int withdrawable;                     
 
   if(cash<10)
      printf("\nThis value cannot be withdraw.Minimum withdrawable amount is 10!");   
      
   else if(cash_amount-cash>0){
      
         withdrawable=cash-(cash%10);
         printf("\nWithdrawable amount is: %d",withdrawable);
   }
   
   else{
      if(cash%10 == 0)
         printf("\nThis value can be withdraw.");
      else{
         withdrawable=cash-(cash%10);
         printf("\nWithdrawable amount is: %d",withdrawable);  
      }   
   }   
}


