#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void listCustomers(int num);
/*
* Function: listCustomer
*
* To Do: It takes the num variable, the number of customers, as a parameter. 
*        Prints customers' ID numbers, names and credit information on the screen.
*
* Returns: Nothing
*/

void addCustomer(int i);
/*
* Function: addCustomer
*
* To Do: Gets the address, phone and name information from the user and writes them to the customers.txt file.
*        So it creates a new user.
*
* Returns: nothing
*/

void newLoan(int num);
/*
* Function: newLoan
*
* To Do: It creates a new loan record by taking the amount, interestRate and period values from the user.
*        Calculates the loan value by calling the calculateLoan function.
*
* Returns: Nothing
*/

float calculateLoan(float amount, int period, float interestRate);
/*
* Function: calculateLoan
*
* To Do: It takes the variables Amount, period, interestRate as parameters. 
*
* Returns: amount
*/

void getReport();
/*
* Function: getReport
*
* To Do: It takes num, the number of customers, as a parameter.
*        According to options, prints customer.txt  or creates and edits loan.txt file and prints it.
*
* Returns: nothing
*/


union Person{
   char name[50];
   char address[50];
   long int phone; //I defined it as "long" so that it can work with 11 digit numbers.
};

union Loan{
   float amount;
   float interestRate;
   int period; 
};

struct BankAccount{
   union Person Customer; 
   union Loan Loans[3];
};

struct OtherThings{
   int period[3]; //Since union can store a single variable I defined this struct to hold the period variable
};
struct OtherThings b[50];

struct BankAccount a[50];

int main(){

   char c;
   int i,j,num=0;

   for(i=0;i<50;i++){  //I set the amount and period to zero for all conditions. Because in the future I'll check it out.
      for(j=0;j<3;j++){
         a[i].Loans[j].amount=0;
         b[i].period[j]=0;
      }
   }
   
   FILE *fp=fopen("customers.txt","w");
   fclose(fp);
   
   while(1){
      
      int choice1,choice2,flag1;
      
      printf("\n======================================"
             "\nWelcome to the Bank Management System"
             "\n======================================"
             "\n\t1. List All Customers"
             "\n\t2. Add New Customer"
             "\n\t3. New Loan Application"
             "\n\t4. Report Menu"
             "\n\t5. Exit System: ");
      
   //Checking that a correct value has been entered for the variable choice1
   //I use this system to prevent error and unwanted entries. 
   do{
      flag1= scanf("%u",&choice1);  //The scanf function returns 1 if a number is entered, 0 otherwise
      while(flag1 !=1 || !(choice1>=1 && choice1<=5)){
         printf("\nError!Please enter a valid entry: ");
         scanf("%*[^\n]"); //Reads any character as long as it's not a newline(\n)
         flag1= scanf("%u",&choice1);
      }
      do{
      c=getchar();
      }while(c !='\n' && c != EOF);  
      break;         
   }while(1);     
   
      if(choice1 == 5){ 
         //remove("customers.txt");
         break;
      }
   
      else if(choice1 == 1){
         listCustomers(num);
      }
   
      else if(choice1 == 2){
         if(num>=50) printf("\nOur service is full. We are currently unable to add customers.");
         else{
            addCustomer(num);
            num++; //The number of users is increased by 1 when a new user is added.
         }
      }
      
      else if(choice1 == 3){
      
         //If a number not between 0 and 50 and greater than num variable is entered, the loop continues.
         //If anything other than a number is entered, the loop continues.
         do{
            printf("\nEnter the ID number to give credit[0-49]: ");
            flag1= scanf("%u",&choice2);  //The scanf function returns 1 if a number is entered, 0 otherwise
            while(flag1 !=1 || !(choice2>=0 && choice2<50 && choice2<num)){
               printf("\nError!Please enter a valid entry: ");
               scanf("%*[^\n]"); //Reads any character as long as it's not a newline(\n)
               flag1= scanf("%u",&choice2);
            }
            do{
               c=getchar();
            }while(c !='\n' && c != EOF);  
            break;   
      
         }while(1);       
         newLoan(choice2);
      }
      
      else if(choice1 == 4){
         
         getReport(num);
         remove("loans.txt");	
      }                          
   }
}


void addCustomer(int i){
   
   FILE* fp;
   fp=fopen("customers.txt","a");
   
   fprintf(fp,"Customer ID: %d\n",i);
   
   printf("\nEnter the adress: ");
   fflush(stdin);
   scanf(" %[^\n]%*c",a[i].Customer.address);   
   fprintf(fp,"Customer Adress: %s\n",a[i].Customer.address); 
   
   printf("\nEnter the phone number: "); 
   int flag1;
   char c;
   do{
      flag1= scanf("%ld",&a[i].Customer.phone);   //The scanf function returns 1 if a number is entered, 0 otherwise
      while(flag1 !=1){
         printf("\nError!Please enter a valid entry: ");
         scanf("%*[^\n]"); //Reads any character as long as it's not a newline(\n)
         flag1= scanf("%ld",&a[i].Customer.phone); 
      }
      do{
      c=getchar();
      }while(c !='\n' && c != EOF);  
      break;   
      
   }while(1);      
   fprintf(fp,"Customer phone: %ld\n",a[i].Customer.phone);
   
   printf("\nEnter the name: ");
   fflush(stdin);
   scanf(" %[^\n]%*c",a[i].Customer.name);
   fprintf(fp,"Customer Name: %s\n",a[i].Customer.name);   
   
   fprintf(fp,"\n");
   fclose(fp);   
}

void listCustomers(int num){

   int i;
   for(i=0;i<num;i++){
   
      printf("\nCustomer ID: %d",i);
      printf("\nCustomer Name: %s",a[i].Customer.name);
      if(a[i].Loans[0].amount == 0) printf("\nThere is no loan");
      else if(a[i].Loans[1].amount == 0) printf("\nLoans: [ %.2f ]",a[i].Loans[0].amount);
      else if(a[i].Loans[2].amount == 0) printf("\nLoans: [ %.2f + %.2f ] => %.2f",a[i].Loans[0].amount,a[i].Loans[1].amount,a[i].Loans[0].amount+a[i].Loans[1].amount);
      else printf("\nLoans: [ %.2f + %.2f + %.2f ] => %.2f",a[i].Loans[0].amount,a[i].Loans[1].amount,a[i].Loans[2].amount,a[i].Loans[0].amount+a[i].Loans[1].amount+a[i].Loans[2].amount);
      
      printf("\n");
   }

}

void newLoan(int i){
   
   
   int j,flag1;
   char c;
   if(a[i].Loans[0].amount == 0) j=0;
   else if(a[i].Loans[1].amount == 0) j=1;
   else if(a[i].Loans[2].amount == 0) j=2;
   else{ printf("\nWe can't give any more loan!"); return; }
   

   printf("\nEnter the amount: ");
   do{

      flag1= scanf("%f",&a[i].Loans[j].amount);   //The scanf function returns 1 if a number is entered, 0 otherwise
      while(flag1 !=1){
         printf("\nError!Please enter a valid entry: ");
         scanf("%*[^\n]"); //Reads any character as long as it's not a newline(\n)
         flag1= scanf("%f",&a[i].Loans[j].amount); 
      }
      do{
      c=getchar();
      }while(c !='\n' && c != EOF);  
      break;   
      
   }while(1);      
   float amount1=a[i].Loans[j].amount;
   
   
   printf("\nEnter the interest rate: ");
   do{

      flag1= scanf("%f",&a[i].Loans[j].interestRate);   //The scanf function returns 1 if a number is entered, 0 otherwise
      while(flag1 !=1){
         printf("\nError!Please enter a valid entry: ");
         scanf("%*[^\n]"); //Reads any character as long as it's not a newline(\n)
         flag1= scanf("%f",&a[i].Loans[j].interestRate);
      }
      do{
      c=getchar();
      }while(c !='\n' && c != EOF);  
      break;        
   }while(1);      
   float interestRate1=a[i].Loans[j].interestRate;
   
   printf("\nEnter the period: ");
   do{

      flag1= scanf("%d",&a[i].Loans[j].period);  //The scanf function returns 1 if a number is entered, 0 otherwise
      while(flag1 !=1){
         printf("\nError!Please enter a valid entry: ");
         scanf("%*[^\n]"); //Reads any character as long as it's not a newline(\n)
         flag1= scanf("%d",&a[i].Loans[j].period);
      }
      do{
      c=getchar();
      }while(c !='\n' && c != EOF);  
      break;   
      
   }while(1);    
   int period1=a[i].Loans[j].period; 
   b[i].period[j]=a[i].Loans[j].period; 
   
   float loan=calculateLoan(amount1,period1,interestRate1);
   printf("\nLoan: %.2f",loan);
   a[i].Loans[j].amount=calculateLoan(amount1,period1,interestRate1);

}


float calculateLoan(float amount, int period, float interestRate){
    
   amount=amount*(1+interestRate);  
   if(period == 1)  return amount; 
   else amount=calculateLoan(amount,period-1,interestRate);
   return amount;  
   
}


void getReport(int num){

   int i,choose3;
   int flag1;
   char c;
   printf("\nSelect 1 for customer list, 2 for loan detail: ");
   do{

      flag1= scanf("%d",&choose3);  //The scanf function returns 1 if a number is entered, 0 otherwise
      while(flag1 !=1 || !(choose3 == 1 || choose3 == 2)){
         printf("\nError!Please enter a valid entry: ");
         scanf("%*[^\n]"); //Reads any character as long as it's not a newline(\n)
         flag1= scanf("%d",&choose3);
      }
      do{
      c=getchar();
      }while(c !='\n' && c != EOF);  
      break;         
   }while(1);       
   
   
   if(choose3 == 1){
      FILE* fp;
      fp=fopen("customers.txt","r");
      
      if(fp != NULL){ //Checking if the customers.txt file exists
         char ch;
         while(!feof(fp)){ //Printing the customers.txt file to the screen
            ch=fgetc(fp);
            printf("%c",ch);   
         }
         fclose(fp);
      }
      else{ printf("\nCustomer list not created yet"); return;}
   }
   
   else if(choose3 == 2){
   FILE*fp;
   fp=fopen("loans.txt","a");
   
   printf("\nEnter the id number of the user whose credit information you want to learn: ");
         do{
            flag1= scanf("%u",&i);  //The scanf function returns 1 if a number is entered, 0 otherwise
            while(flag1 !=1 || !(i>=0 && i<50 && i<num)){
               printf("\nError!Please enter a valid entry. We do not have such a user: ");
               scanf("%*[^\n]"); //Reads any character as long as it's not a newline(\n)
               flag1= scanf("%u",&i);
            }
            do{
               c=getchar();
            }while(c !='\n' && c != EOF);  
            break;   
      
         }while(1);    
   //for(i=0;i<num;i++){
   
      fprintf(fp,"\nCustomer ID: %d",i);
      fprintf(fp,"\nCustomer Name: %s",a[i].Customer.name);
      fprintf(fp,"\nTotal credit value: %.2f",a[i].Loans[0].amount+a[i].Loans[1].amount+a[i].Loans[2].amount);
      int j,k,max=0;
      for(j=0;j<3;j++){ //find the largest period value
         for(k=0;k<=2;k++){
            if(b[i].period[k]>max) max=b[i].period[k];
         }
      }
      int period1=b[i].period[0];
      int period2=b[i].period[1]; //I will use these variables to reduce
      int period3=b[i].period[2];
      
      //For example, if period3 is zero, it doesn't make sense to add it to the total anymore. 
      
      for(j=1;j<=max;j++){
         
         fprintf(fp,"\n%d. Month Installment = ",j);
         if(period1!=0 && period2!=0 && period3!=0){
            fprintf(fp,"%.2f",a[i].Loans[0].amount/b[i].period[0]+a[i].Loans[1].amount/b[i].period[1]+a[i].Loans[2].amount/b[i].period[2]);
            period1--; period2--; period3--;
         }  
          
         else if(period1!=0 && period2!=0 && period3 ==0){           
            fprintf(fp,"%.2f",a[i].Loans[0].amount/b[i].period[0]+a[i].Loans[1].amount/b[i].period[1]);
            period1--; period2--; 
         }
         
         else if(period1!=0 && period2==0 && period3 !=0){
            fprintf(fp,"%.2f",a[i].Loans[0].amount/b[i].period[0]+a[i].Loans[2].amount/b[i].period[2]);
            period1--; period3--;
         }
         
         else if(period1==0 && period2!=0 && period3 !=0){
            fprintf(fp,"%.2f",a[i].Loans[1].amount/b[i].period[1]+a[i].Loans[2].amount/b[i].period[2]);
            period2--; period3--;
         }
         
         else if(period1!=0 && period2==0 && period3 ==0){
            fprintf(fp,"%.2f",a[i].Loans[0].amount/b[i].period[0]);
            period1--;
         }
         
         else if(period1==0 && period2!=0 && period3 ==0){
            fprintf(fp,"%.2f",a[i].Loans[1].amount/b[i].period[1]);
            period2--;
         }
         
         else if(period1==0 && period2==0 && period3 !=0){
            fprintf(fp,"%.2f",a[i].Loans[2].amount/b[i].period[2]);
            period3--;
         }
         
         //else if(period1==0 && period2==0 && period3 ==0)                       
      }     
      fprintf(fp,"\n");
        
   //}
   fclose(fp); //I closed the loans.txt file because I needed to open it in read mode.
   
   fp=fopen("loans.txt","r");
   char ch;
   while(!feof(fp)){
      ch=fgetc(fp);
      printf("%c",ch);
   }
   fclose(fp);
   
   }
   
}


