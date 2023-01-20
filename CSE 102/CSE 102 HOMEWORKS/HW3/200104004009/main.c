#include <stdio.h>
#include <math.h>

void part1();
void part2();
int part3();

int sum(int n1,int n2,int flag);
int multi(int n1,int n2,int flag);
void write_file(int number);
int isprime(int a);
void print_file();
void sort_file();
int control_number(int a); //Checks if the number a is in the temporary file.

int main(){

   int a;
   while(1){
   printf("\nSelect operation"
   "\n1. Calculate sum/multiplication between two numbers"
   "\n2. Calculate prime numbers"
   "\n3. Show number sequence in file"
   "\n4. Sort number sequnce in file: ");
   //int a;
   scanf("%d",&a);
   
   if(a>=1 && a<=4) break;
   else printf("\nOnly numbers in the range 1-4 are acceptable.\n");
   }
   
   switch(a){
      case 1:
         part1();
         break;
      case 2:
         part2();
         int j;
         for(j=1;j<1;j++){
         /*We are told to get the value of N from the user in the part2() function. It was also requested to call the isprime() function there.
         I couldn't understand how the functionless loop that you want to return up to N value will work here
         */
         }         
         break;
      case 3:
         print_file();
         break;
      case 4: 
         sort_file();
         break;     
   
   }
   
}


void part1(){

      int b,n1,n2,flag;
      while(1){ 
         printf("\nPlease enter '0' for sum,'1' for multiplication: ");
         scanf("%d",&b);
         if(b == 0 || b == 1) break;
         else printf("\nError! You should have just entered 0 or 1.");       
      }
      
      switch(b){
         case 0:
            while(1){
               printf("\nPlease enter '0' to work on even numbers,'1' to work on odd numbers: ");
               scanf("%d",&flag);
               if(flag==0 || flag==1) break;
               else printf("\nError! You should have just entered 0 or 1.");           
            }   
            
            while(1){
            printf("\nPlease enter two different number: ");
            printf("\nNumber 1: "); scanf("%d",&n1);
            printf("\nNumber 2: "); scanf("%d",&n2);
            
            if(n1>=0 && n2>=0) break;
            else printf("\nDo not enter negative numbers!(Teacher says so.)");
            }
            if(n1>n2){
               int temp=n1;
               n1=n2;
               n2=temp;
            }
            int value1=sum(n1,n2,flag);
            
            int i;
            if(flag==0){
            for(i=n1+1;i<n2;i++){
               if(i%2 == 0){  
                  if(n2-i<=2) printf("%d ",i);
                  else printf("%d + ",i);             
               }         
            }
            }
            if(flag==1){
            for(i=n1+1;i<n2;i++){
               if(i%2 == 1){  
                  if(n2-i<=2) printf("%d ",i);
                  else printf("%d + ",i);             
               }         
            }
            }            
            printf("= %d",value1);                      
            write_file(value1);          
            printf("\nThe result is written to the result.txt file.");
            break;
         
         case 1: 
            while(1){
               printf("\nPlease enter '0' to work on even numbers,'1' to work on odd numbers: ");
               scanf("%d",&flag);
               if(flag==0 || flag==1) break;
               else printf("\nError! You should have just entered 0 or 1.");           
            }   
            while(1){
            printf("\nPlease enter two different number: ");
            printf("\nNumber 1: "); scanf("%d",&n1);
            printf("\nNumber 2: "); scanf("%d",&n2);
            
            if(n1>=0 && n2>=0) break;
            else printf("\nDo not enter negative numbers!(Teacher says so.)");            
            }
            if(n1>n2){
               int temp=n1;
               n1=n2;
               n2=temp;
               printf("\nValues have been swapped.\n");
            }
            int value2=multi(n1,n2,flag);     

            if(flag==0){   
            for(i=n1+1;i<n2;i++){
               if(i%2 == 0){  
                  if(n2-i<=2) printf("%d ",i);
                  else printf("%d * ",i);             
               }         
            }
            }
            if(flag==1){
            for(i=n1+1;i<n2;i++){
               if(i%2 == 1){  
                  if(n2-i<=2) printf("%d ",i);
                  else printf("%d * ",i);             
               }         
            }
            }            
            printf("= %d",value2);                                   
            write_file(value2);           
            printf("\nThe result is written to the result.txt file.");
            break;       
      }
}




int sum(int n1,int n2,int flag){
   
   int sum=0;
   if(flag == 0){
      int i;
      for(i=n1+1;i<n2;i++){
      
         if(i%2 == 0)
               sum+=i;            
      }
   }
   
   if(flag == 1){
      int i;
      for(i=n1+1;i<n2;i++){
      
         if(i%2 == 1)
               sum+=i;            
      }
   }
   
   return sum;     
}


int multi(int n1,int n2,int flag){

   int multi=1;
   if(flag == 0){
      int i;
      for(i=n1+1;i<n2;i++){
      
         if(i%2 == 0)
               multi*=i;            
      }
   }
   
   if(flag == 1){
      int i;
      for(i=n1+1;i<n2;i++){
      
         if(i%2 == 1)
               multi*=i;            
      }
   }
   
   return multi;  

}


void write_file(int number){

    FILE *fp;
    fp = fopen("results.txt", "a+");
    fprintf(fp, "%d ", number);
    fclose(fp);
}



void part2(){  

   int n,control; 
   printf("\nPlease enter an integer: ");
   scanf("%d",&n);
   int i;
   for(i=2;i<n;i++){
      control= isprime(i);
      if(control == 1)
         printf("\n%d is a prime number.",i);
      else
         printf("\n%d is not a prime number,it is dividible by %d",i,control);   
   }
}


int isprime(int a){

   int x;
   for(x=2;x<=sqrt(a);x++){
   
      if(a%x == 0)
         return x;        
   }
   return 1;
}

void print_file(){

    FILE *fp;
    fp = fopen("results.txt", "r");
    int temp;
    printf("\nResult: ");
    while (fscanf(fp, "%d", &temp) == 1)
    {
        //total += temp;
        //counter++;
        //fscanf(fp,"%d",&temp);
        printf("%d ",temp);
    }
    fclose(fp);
}


void sort_file(){

    FILE *fp;
    fp = fopen("results.txt", "r");
    int sayi1,counter=0;
    int min1=2147483647,min2=2147483647,min3=2147483647; 
    FILE *tempo;
    tempo = fopen("temporary.txt","w");
    
    while(!feof(fp)){
    
       fscanf(fp,"%d",&sayi1);
       counter++;
    }
    counter=counter-1; //For a reason I don't understand, the counter value is one more than the value it should be.

    fclose(fp);
    fp = fopen("results.txt", "r"); //This time, I open the results file in read mode for the processes below.
    
    while (!feof(fp)){  //Finds the smallest three numbers
    
       fscanf(fp, "%d", &sayi1);

        if(sayi1<min1){
           min3=min2;
           min2=min1;
           min1=sayi1;
        }   
        else if(sayi1>min1 && sayi1<min2){
           
           min3=min2;
           min2=sayi1;
        }   
        else if(sayi1>min2 && sayi1<min3){
           
           min3=sayi1;  
        }  
    }
    fprintf(tempo,"%d %d %d ",min1,min2,min3);
    
    fclose(tempo); 
    fclose(fp);
   
    int i;
    for(i=1;i<counter/3;i++){ //Finds the smallest three numbers for the remainders
    
    min1=min2=min3=2147483647;
    fp = fopen("results.txt", "r");

    while (!feof(fp)){  
    
       fscanf(fp, "%d", &sayi1);
       if(control_number(sayi1) == 0)
          continue;
       else{   

        if(sayi1<min1){
           min3=min2;
           min2=min1;
           min1=sayi1;
        }   
        else if(sayi1>min1 && sayi1<min2){
           
           min3=min2;
           min2=sayi1;
        }   
        else if(sayi1>min2 && sayi1<min3){
           
           min3=sayi1;  
        }  
     }
    }

    tempo = fopen("temporary.txt","a");
    fprintf(tempo,"%d %d %d ",min1,min2,min3);
    fclose(tempo);
    fclose(fp);
    
    } 
    
    if(counter%3 == 1){
       fp = fopen("results.txt", "r");
       while (!feof(fp)){
       
          fscanf(fp, "%d", &sayi1);
          if(control_number(sayi1) == 1){ //The number that is in the results file but not in the temporary file,
             tempo = fopen("temporary.txt","a"); // is added to the end of the temporary file
             fprintf(tempo,"%d",sayi1);
             fclose(tempo);
             break;
          }          
       }
       fclose(fp);
    }
    
    else if(counter%3 == 2){
       int num1=0;
       int num2=0;
       fp = fopen("results.txt", "r");
       while (!feof(fp)){
          fscanf(fp, "%d", &sayi1);
          if(control_number(sayi1) == 1){
             num2=num1;
             num1=sayi1;
           }         
       }
       tempo = fopen("temporary.txt","a");
       if(num1<num2)
          fprintf(tempo,"%d %d",num1,num2);
       else
          fprintf(tempo,"%d %d",num2,num1);
                     
      fclose(fp);
      fclose(tempo);    
    }
    
    remove("results.txt");
    rename("temporary.txt","results.txt");       
    printf("\nSorting is complete.");
    print_file();       
}

int control_number(int a){  //Checks if the number a is in the temporary file.

   int sayi;
   FILE *tempo;
   tempo = fopen("temporary.txt","r");
   while(!feof(tempo)){
      fscanf(tempo, "%d", &sayi);
      if(a == sayi){
         fclose(tempo);
         return 0;
      }   
   }
   fclose(tempo);
   return 1;
}







