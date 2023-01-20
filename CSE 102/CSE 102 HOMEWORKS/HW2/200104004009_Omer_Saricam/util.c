#include <stdio.h>
#include "util.h"
#include <math.h>

/* Example decision tree - see the HW2 description */

int dt0(int t, double p, double h, int s, int w) {
    int r = 0;
    if (t>35 && w!=3) r = 1;
    else if (t<=35 && s==0) r = 1;
    return r;
}



/* Provide your implementations for all the requested functions here */

char dt1a(double pl,double pw,double sl,double sw){

//Returns s for Setosa, v for virginica, r for versicolor
   if(pl<2.45)
      return 's';
   else if(pl>=2.45 && pw>=1.75)
      return 'v';
   else if(pl>=2.45 && pw<1.75 && pl>=4.95)
      return 'v';
   else if(pl>=2.45 && pw<1.75 && pl<4.95 && pw>=1.65)
      return 'v';
   else if(pl>=2.45 && pw<1.75 && pl<4.95 && pw<1.65)
      return 'r';            

}



char dt1b(double pl,double pw,double sl,double sw){

//Returns s for Setosa, v for virginica, r for versicolor
   if(pl<2.55)
      return 's';
   else if(pl>=2.55 && pw>=1.69)
      return 'v';
   else if(pl>=2.55 && pw<1.69 && pl>=4.85)
      return 'v';
   else if(pl>=2.55 && pw<1.69 && pl<4.85)
      return 'r';   

}



void bastir(char a){ //The teacher(Cem Ayar) said you can use an extra function.
//Since we cannot use the char* type, this is how I print it
   if(a == 's')
      printf(" Setosa");
   else if(a == 'v')
      printf(" Virginica");
   else if(a == 'r')
      printf(" Versicolor");      

}



double dt2a(double x1,double x2,double x3,int x4,int x5){

   if(x1<31.5 && x2>-2.5)
      return 5.0;
   else if(x1<31.5 && x2<=-2.5 && x1>=x2-0.1 && x1<=x2+0.1)
      return 2.1;
   else if(x1<31.5 && x2<=-2.5 && !(x1>=x2-0.1 && x1<=x2+0.1))
      return -1.1;
   else if(x1>=31.5 && x3>=-1 && x3<=2)
      return 1.4;
   else if(x1>=31.5 && !(x3>=-1 && x3<=2) && (x4 & x5)==1)
      return -2.23;
   else if(x1>=31.5 && x3<-1 && x3>2 && (x4 & x5)==0);
      return 11.0;

}



double dt2b(double x1,double x2,double x3,int x4,int x5){

   if(x1>12 && x1<22 && x3>5/3)
      return -2.0;
   else if(x1>12 && x1<22 && x3<=5/3 && x3>=x1-0.1 && x3<=x1+0.1 )
      return 1.01;
   else if(x1>12 && x1<22 && x3<=5/3 && !(x3>=x1-0.1 && x3<=x1+0.1))
      return -8;   
   else if(!(x1>12 && x1<22) && (x4 & x5)==1)
      return -1;
   else if(!(x1>12 && x1<22) && (x4 & x5)==0 && x2>=-1 && x2<=2)
      return -1.0/7.0; 
   else if(!(x1>12 && x1<22) && (x4 & x5)==0 && !(x2>=-1 && x2<=2))
      return sqrt(2)/3.0;
}



char dt3a(double km,double engine,int public,int type,int class){

//The function returns y(yes) if environmental tax is to be applied, n(no) if not.

   if(public==1)
      return 'n';
   else if(public==0 && type<2)
      return 'n';
   else if(public==0 && type>=2 && class<=2 && engine<1.8 && km<50000)
      return 'n';    
   else if(public==0 && type>=2 && class<=2 && engine<1.8 && km>=50000)
      return 'y';
   else if(public==0 && type>=2 && class<=2 && engine>=1.8 && km<40000) 
      return 'n';
   else if(public==0 && type>=2 && class<=2 && engine>=1.8 && km>=40000) 
      return 'y';
   else if(public==0 && type>=2 && class>2 && engine<7 && class==6)    //Sınıf 6 tuhaf oldu.
      return 'n';
   else if(public==0 && type>=2 && class>2 && engine<7 && class!=6 && km<30000)
      return 'n';
   else if(public==0 && type>=2 && class>2 && engine<7 && class!=6 && km>=30000)
      return 'y';
   else if(public==0 && type>=2 && class>2 && engine>=7 && km<10000)
      return 'n';
   else if(public==0 && type>=2 && class>2 && engine>=7 && km>=10000)
      return 'y';                  
           
}



char dt3b(double km,double engine,int public,int type,int class){

//The function returns y(yes) if environmental tax is to be applied, n(no) if not.

   if(type<2)
      return 'n';
   else if(type>=2 && public == 1)
      return 'n';
   else if(type>=2 && public == 0 && class>2 && class<6 && engine<6 && km<55000)
      return 'n';      
   else if(type>=2 && public == 0 && class>2 && class<6 && engine<6 && km>=55000)
      return 'y';
   else if(type>=2 && public == 0 && class>2 && class<6 && engine>=6 && km<40000)
      return 'n';
   else if(type>=2 && public == 0 && class>2 && class<6 && engine>=6 && km>=40000)
      return 'y';
   else if(type>=2 && public == 0 && !(class>2 && class<6) && engine<1.6 && km<100000)
      return 'n';
   else if(type>=2 && public == 0 && !(class>2 && class<6) && engine<1.6 && km>=100000 && class==6 && km<150000)
      return 'n';
   else if(type>=2 && public == 0 && !(class>2 && class<6) && engine<1.6 && km>=100000 && class==6 && km>=150000)
      return 'y';
   else if(type>=2 && public == 0 && !(class>2 && class<6) && engine<1.6 && km>=100000 && class!=6)
      return 'y';
   else if(type>=2 && public == 0 && !(class>2 && class<6) && engine>=1.6 && km<80000)
      return 'n';                     
   else if(type>=2 && public == 0 && !(class>2 && class<6) && engine>=1.6 && km>=80000 && class==6 && km<130000)
      return 'n';
   else if(type>=2 && public == 0 && !(class>2 && class<6) && engine>=1.6 && km>=80000 && class==6 && km>=130000)
      return 'y';
   else if(type>=2 && public == 0 && !(class>2 && class<6) && engine>=1.6 && km>=80000 && class!=6)
      return 'y';      

}
