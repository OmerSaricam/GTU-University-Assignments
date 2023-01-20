#include <stdio.h>
#include "util.h"


int main() {

   //PART 1
   
   int x,y,z,n; 

   printf("\nEnter the first integer: ");
   scanf("%d",&x);
   printf("\nEnter the second integer: ");
   scanf("%d",&y);
   printf("\nEnter the divisor: ");
   scanf("%d",&z);
   
   if(find_divisible(x,y,z)==-1)
      printf("\nThere is not any integer between %d and %d can be divided by %d\n",x,y,z);
   else{
      printf("\nThe first integer between %d and %d divided by %d is %d\n",x,y,z,find_divisible(x,y,z));   
      int f_I=x;   
      printf("\nEnter the number how many next: ");
      scanf("%d",&n);
      if(find_nth_divisible(n, f_I, z)<y)
         printf("The %d. integer between %d and %d divided by %d is %d\n",n+1,x,y,z,find_nth_divisible(n, f_I, z));      
      else if(find_nth_divisible(n, f_I, z)>y)
         printf("No possible to find %d. divisible between %d and %d divided by %d\n",n+1,x,y,z);
   }   
   

   //PART 2 
   
   int control,password;
   char id[100];
   printf("\nEnter your identity number to create an account: ");
   scanf("%s",id);
   
   if(validate_identity_number(id)==0)
      printf("\nThis identity number is not valid!");
   else if(validate_identity_number(id)==1){
      printf("\nThe identity number is valid.");
      printf("\nPlease enter a 4-digit password to create an account: ");
      scanf("%d",&password);

      if(password<1000 || password>=10000)
         printf("\nInvalid password. You should have entered a 4 digit password!"); //BAŞINDA 0 OLAN ŞİFRELERİ ALMIYOR
        
      else{
         create_customer(id,password); 
         
         //PART 3.I REQUIRED THAT THE REGISTRATION SECTION MADE CORRECTLY TO ENTER THE ENTRY SECTION.
         
         char id2[100];  //Giriş için girilen kimliği tutan çar
   	 int password2;  // giriş için girilen şifreyi tutan çar
   	 printf("\n\nEnter your identity number to login: "); //Buraya ilk 11 hanesi doğru sayıları içeren daha uzun sayı yazsak da çalışıyor
   	 scanf("%s",id2);
   	 printf("\nEnter your password to login: ");  //Şifre ise nasılsa 4 haneden büyük girince 0 döndürüyor.
   	 scanf("%d",&password2);  
   	 
   	 if(check_login(id2,password2) == 0)
   	    printf("\nInvalid identity number or password!\n");
   	 else if(check_login(id2,password2) == 1){
   	    printf("\nLogin Successful\n");
   	    float cash_amount;
   	    printf("\nEnter your withdraw amount: ");
   	    scanf("%f",&cash_amount);
   	    withdrawable_amount(cash_amount);  	       	 
   	 }      	    	               
      } 
   }
 
   return(0);
}
