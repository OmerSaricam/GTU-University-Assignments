#include <stdio.h>

void graph_plotter();
void text_graph();

int main(){

   int cho;
   do{
   int a,b,c;
   printf("\nSelect an operation..."
          "\n1. Enter the coefficients"
          "\n2. Draw the graph"
          "\n3. Print the graph into a .txt file"
          "\n4. Exit");
   printf("\nChoice: ");
   scanf("%d",&cho);
   
   switch(cho){
   
      case 1:
         printf("\nPlease enter the coefficients for the following equation: x= a*(y*y)+ b*y +c ");
         printf("\na: ");  scanf("%d",&a);
         printf("\nb: ");  scanf("%d",&b);
         printf("\nc: ");  scanf("%d",&c);
         
         FILE *fp;
         fp= fopen("coefficients.txt","w");
         fprintf(fp,"%d\n%d\n%d",a,b,c);
         fclose(fp);
         printf("\nCoefficients.txt file has been created.\n");
         break;
         
      case 2:
         
         graph_plotter();
         break;
      
      case 3:
         text_graph();
         break; 
      case 4: 
         break;
      default:
         printf("\nIncorrect input\n");                              
   }        
   
   }while(cho!=4);

}


void graph_plotter(){ //Prints the graph to terminal

   int a,b,c,x,y,xd;
   FILE *fp;
   fp=fopen("coefficients.txt","r");
   if(fp == NULL) printf("\nFile could not be found"); //checks if the file exists or not
   else{
   fscanf(fp,"%d %d %d",&a,&b,&c);
   printf("\nCoefficients has been read from the coefficients.txt file.");
   printf("\nPrinting the graph of x = %d*(y*y) + %d*y + %d\n\n",a,b,c);
   for(y=15;y>=-15;y--){
   
      xd= a*(y*y) + b*y + c;
      for(x=-50;x<=50;x++){
      
         if( x == -56 && y == 0) printf("<"); 
         else if( x == 56 && y == 0) printf(">");
         else if( x == 0 && y == 16) printf("^");
         else if(y==0 && x!=xd) printf("-");
         else if(y==0 && x==xd){ printf("\033[0;34m"); printf("#"); printf("\033[0m");}    
         
         /*
         else if(y==-1){
            //for(x=-50;x<=50;x++){
               //if(x==0) continue;
            if(x<0 && x%10 == 0 ) printf("\b\b%d",x);
            else if(x>0 && x%10 == 0) printf("\b%d",x);
            else if(x!=0){
              if(x==xd) printf("#");
              else printf(" ");
              //printf("#"); 
            }  
            else if(x==0) printf("|");
         }
         */
         /*
         else if(y==-1){
            
            if(x >= -50 && x <= -10 && x%10==0) printf("\b\b%d",x);
            else if(x >= 10 && x <= 50 && x%10==0) printf("\b%d",x);
            else if( x == -1 ) printf("%d",x+1);
            else if(x == 0) printf("|\b\b");
            if(x==xd) printf("#");
            
            else printf(" ");
                
         }
         */
         
         else if(y == -1){         
                                  
            if(x<0 && x%10==0){
               printf("\033[0;33m");
               printf("%d       ",x);
               printf("\033[0m");
            }
            else if(x>0 && x%10==0){
               printf("\033[0;33m");
               printf("        %d",x);
               printf("\033[0m");
            }
            else if(x==0 && x!=xd) printf("|");
            else if(x==0 && x==xd){ printf("\033[0;34m"); printf("#"); printf("\033[0m");  }
         }
  
         
         else{
            if(x==0 && y!=0 && x!=xd) printf("|");
            else if(x==0 && y!=0 && x==xd){ printf("\033[0;34m"); printf("#"); printf("\033[0m"); }              
            else{
              if(x==xd && xd>=-50 && xd<=50){ printf("\033[0;34m"); printf("#"); printf("\033[0m"); }
              else printf(" ");
           }              
         }
      }

      printf("\n");
   }
   
   }
   
   fclose(fp);
}


void text_graph(){ //Prints the graph to the graph.txt file.

   int a,b,c,x,y,xd;
   FILE *fp;
   fp=fopen("coefficients.txt","r");
   if(fp == NULL) printf("\nFile could not be found"); //checks if the file exists or not
   else{
      fscanf(fp,"%d %d %d",&a,&b,&c);
      FILE *dosya;
      dosya=fopen("graph.txt","w");
      
      for(y=16;y>=-16;y--){
      
         xd= a*(y*y) + b*y + c;   
         for(x=-56;x<=56;x++){
            if( x == -56 && y == 0) fprintf(dosya,"<");
            else if( x == 56 && y == 0) fprintf(dosya,">");
            else if( x == 0 && y == 16) fprintf(dosya,"^");
            else if(y==0 && x!=xd) fprintf(dosya,"-");
            else if(y==0 && x == xd) fprintf(dosya,"#");
            
            else{
               if(x==0 && y!=0 && x!=xd) fprintf(dosya,"|");
               else if(x==0 && y!=0 && x==xd) fprintf(dosya,"#");
               else{
                 if(x==xd) fprintf(dosya,"#");
                 else fprintf(dosya," ");
               }  
            }
         
         }
         fprintf(dosya,"\n");
      }
      
   fclose(dosya);
   }

   fclose(fp);
   printf("The graph of x = %d*(y*y) + %d*y + %d has been written to graph.txt file.\n",a,b,c);
}




