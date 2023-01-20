#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.14

/*
--If the user enters a letter after the number(like 3b), it processes the number part and does not give an error, 
  if the number value is in the range we want.
  
--In all other undesired cases it gives an error.

--For decimal fractions, I set the precision after the comma to 2 as in the examples(%.2f).

--I couldn't get the fflush(stdin) function to work, I tried another way.
*/

enum shapes{triangle=1,quadrilateral,circle,pyramid,cylinder};
enum calculators{area=1,perimeter,volume};

int select_shape();
int select_calc();
int calculate(int (*select_shape)(),int (*select_calc)());
int calc_triangle(int);
int calc_quadrilateral(int);
int calc_circle(int);
int calc_pyramid(int);
int calc_cylinder(int);
float valid_control();

int main(){

   calculate(select_shape,select_calc);
}


int select_shape(){

      printf("\nSelect a shape to calculate: "
             "\n-----------------------------"
             "\n1. Triangle"
             "\n2. Quadrilateral"
             "\n3. Circle"
             "\n4. Pyramid"
             "\n5. Cylinder"
             "\n0. Exit: ");
   enum shapes e1;     
   int numberread,c=1;
   do{
      numberread= scanf("%u",&e1);   //The scanf function returns 1 if a number is entered, 0 otherwise      
      while(numberread !=1 || !(e1>=0 && e1<=5)){
         printf("\nError!Please enter a valid entry: ");
         scanf("%*[^\n]");   //Reads any character as long as it's not a newline(\n)
         numberread= scanf("%u",&e1);
      }
      do{
       c=getchar();
      }while(c !='\n' && c != EOF); 
       
      break;         
      }while(1);   
   
     
   if(e1 == triangle) return triangle;
   else if(e1 == quadrilateral) return quadrilateral;
   else if(e1 == circle) return circle;
   else if(e1 == pyramid) return pyramid;
   else if(e1 == cylinder) return cylinder;
   else if(e1 == 0) return 0;   
   
}

int select_calc(){

      printf("\nSelect calculator: "
             "\n------------------"
             "\n1. Area"
             "\n2. Perimeter"
             "\n3. Volume"
             "\n0. Exit: ");   
   enum calculators e2;

   char c;
   int numberread;
   do{
      numberread= scanf("%u",&e2);  //The scanf function returns 1 if a number is entered, 0 otherwise
      while(numberread !=1 || !(e2>=0 && e2<=3)){
         printf("\nError!Please enter a valid entry: ");
         scanf("%*[^\n]"); //Reads any character as long as it's not a newline(\n)
         numberread= scanf("%u",&e2);
      }
      do{
      c=getchar();
      }while(c !='\n' && c != EOF);  
      break;   
      
      }while(1);    
    
    
   if(e2 == area) return area;
   else if(e2 == perimeter) return perimeter;
   else if(e2 == volume) return volume;
   else if(e2 == 0) return 0;     

}


int calculate(int (*select_shape)(),int (*select_calc)()){

   float vary;
   do{
      int k1= select_shape();
      if(k1 == 0) break;
      int k2= select_calc();
      if(k2 == 0) break;
      
      switch(k1){
      
         case triangle:
            if(k2 == volume){ printf("\nError! You can't calculate the volume of triangle. Try again"); break; }
            else{
               vary=calc_triangle(k2);          
            break;
            }
         case quadrilateral:
            if(k2 == volume){ printf("\nError! You can't calculate the volume of quadrilateral. Try again"); break; }
            else{            
               vary= calc_quadrilateral(k2);
               break;
            }   
         case circle:
            if(k2 == volume){ printf("\nError! You can't calculate the volume of circle. Try again"); break; }
            else{            
               vary= calc_circle(k2);
               break;
               
         case pyramid:
            calc_pyramid(k2);
            break; 
         
         case cylinder:
            calc_cylinder(k2);
            break;                           
                              
            }         
      }       
   
   }while(1);

}


int calc_triangle(int k2){

   float a,b,c;
   float s;
   do{
      printf("\nPlease enter the three sides of triangle: ");
      a=valid_control();
      b=valid_control();
      c=valid_control(); 
      s=(a+b+c)/2;
      if(!(s>a && s>b && s>c)) printf("\nError! In any triangle,  the  semi  perimeter  can  not  be  less  than  any  side.");
   }while( !(s>a && s>b && s>c));
   switch(k2){
   
      case area: 
         s= (a+b+c)/2;
         printf("\nArea of triangle: %.2f",sqrt(s*(s-a)*(s-b)*(s-c)));       
         break;
      case perimeter: 
         printf("\nPerimeter of triangle: %.2f",a+b+c);  
   }

}


int calc_quadrilateral(int k2){

   float a,b,c,d,s;
   printf("\nPlease enter four sides of quadrilateral: ");
   a=valid_control();
   b=valid_control();
   c=valid_control();
   d=valid_control();
     
   switch(k2){
      
      case area: 
         s= (a+b+c+d)/2;
         printf("\nArea of quadrilateral: %.2f",sqrt(a*b*c*d));
         break;
      case perimeter:
         printf("\nPerimeter of quadrilateral: %.2f",a+b+c+d);              
   }
}


int calc_circle(int k2){
   
   float r;  
   printf("\nPlease enter the radius of circle: ");
   r=valid_control();
   
   switch(k2){
      
      case area:
         printf("\nArea of circle: %.2f",pi*r*r);
         break;
      case perimeter:
         printf("\nPerimeter of circle: %.2f",2*pi*r);
         break;        
   }   
}


int calc_pyramid(int k2){

   float a,h,l;
   switch(k2){
   
      case volume:
         printf("\nPlease enter the base side and height of a pyramid: ");
         a=valid_control();
         h=valid_control();
         printf("\nVolume of the pyramid: %.2f",0.3333333*a*a*h);
         break;
      
      case perimeter:
         printf("\nPlease enter the base side of a pyramid: ");
         a=valid_control();
         printf("\nPerimeter of the base of a pyramid: %.2f",4*a);
         break;
      
      case area:
         printf("\nPlease enter the base side and slant height of a pyramid: ");
         a=valid_control();
         l=valid_control();
         
         printf("\nBase surface area of a pyramid: %.2f",a*a);
         printf("\nLateral surface area of a pyramid: %.2f",2*a*l);
         printf("\nSurface area of a pyramid: %.2f",a*a + 2*a*l);
         break;      
   
   }

}


int calc_cylinder(int k2){

   float r,h; //r means radius, h means height
   printf("\nPlease enter the radius and height of a cylinder: ");
   r=valid_control();
   h=valid_control();
   
   switch(k2){
      
      case volume:
         printf("\nVolume of a cylinder: %.2f",pi*r*r*h);
         break;
      case area:
         printf("\nBase surface area of a cylinder: %.2f",pi*r*r);
         printf("\nLateral surface area of a cylinder: %.2f",2*pi*r*h);
         printf("\nSurface area of a cylinder: %.2f",2*pi*r*(r+h));
         break;
      case perimeter:     
         printf("\nBase surface perimeter of a cylinder: %.2f",2*pi*r);
         break;       
   
   }
}

/*
--This function takes input from the user and checks if the input is a character and if the input is a number;
  it checks if the number is greater than 0. Prints error on screen if needed.
   
--It returns the input if the input is not invalid.
*/
float valid_control(){
   
   float a;
   int numberread,c;
   do{
      numberread= scanf("%f",&a); //The scanf function returns 1 if a number is entered, 0 otherwise
      while(numberread !=1 || a<=0){
         printf("\nError!Please enter a valid entry: ");
         scanf("%*[^\n]");     //Reads any character as long as it's not a newline(\n)
         numberread= scanf("%f",&a);
      }
/*
If an input such as 4ab is entered, the leading number part is taken by the upper scanf. I'm removing ab from the buffer in the following
loop so that the rest ab doesn't break other scanf functions
*/     
      do{
         c=getchar();
      }while(c !='\n' && c != EOF);  
            
      return a;         
      }while(1);      
}
