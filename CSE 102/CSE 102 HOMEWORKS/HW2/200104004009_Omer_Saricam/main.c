#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include <math.h>


int main() {

    /* Ask for the problem selection (1,2,3) .....  */

    /* Get the input from the user for the first problem, i.e., to test dt1a and dt1b */
    /* Compare performances and print results */

    /* Get the input from the user for the second problem, i.e., to test dt2a and dt2b */
    /* Compare performances and print results */

    /* Get the input from the user for the third problem, i.e., to test dt3a and dt3b */
    /* Compare performances and print results */
    
    int rank;
    printf("Which problem do you want solved?[0][1][2][3]: ");
    scanf("%d",&rank);
    
    if(rank == 0){
       int t,s,w;
       double p,h;
       printf("\nTemperature(t): ");
       scanf("%d",&t);
       printf("\nPressure(p): ");
       scanf("%lf",&p);
       printf("\nHumidity(h): ");
       scanf("%lf",&h);
       printf("\nSunny or not?(s): ");
       scanf("%d",&s);
       printf("\nDay of the week(w): ");
       scanf("%d",&w);
      
       int dt00=dt0(t,p,h,s,w);
       if(dt00 == 1)
          printf("\nTurn on the AC");
       else if(dt00 == 0)
          printf("\nTurn off the AC");   
    
    }
    
    if(rank == 1){
    
       double pl,pw,sl,sw; //I added the sl and sw variables although they are not used.
       printf("\nWrite the PL,PW,SL and SW values in order: ");
       scanf("%lf %lf %lf %lf",&pl,&pw,&sl,&sw);
       char dt1aa=dt1a(pl,pw,sl,sw);
       char dt1bb=dt1b(pl,pw,sl,sw);
       
       if(dt1aa == dt1bb){
          
          printf("\nBoth answers are the same. The result: ");
          bastir(dt1aa);
       }
       else{
          printf("\nThe answers are different. The results: ");
          bastir(dt1aa);
          bastir(dt1bb);
       }                
 
    }
    
    
    if(rank == 2){
    
       double x1,x2,x3;
       int x4,x5;
       printf("\nEnter the x1,x2,x3,x4,x5 values in order: ");
       scanf("%lf %lf %lf %d %d",&x1,&x2,&x3,&x4,&x5);
       //printf("\nThe result: %.2lf",dt2b(x1,x2,x3,x4,x5));
       
       double dt2aa=dt2a(x1,x2,x3,x4,x5);
       double dt2bb=dt2b(x1,x2,x3,x4,x5);
       if(fabs(dt2aa-dt2bb) <= CLOSE_ENOUGH)
          printf("\nThe answers are similar.The avarage: %.2lf",(dt2aa+dt2bb)/2);
       
       else  
          printf("\nThe answers are different.The results: %.2lf %.2lf",dt2aa,dt2bb); 
    
    }
    
    if(rank == 3){
    
       double km,engine_capacity;
       int public,type,class;
       printf("\nEnter the mileage(km) of the vehicle: ");
       scanf("%lf",&km);

       printf("\nEnter the engine volume of the vehicle (in liters): ");
       scanf("%lf",&engine_capacity);

       printf("\nDoes the vehicle belong to a public institution?Yes:[1] No:[0]: ");
       scanf("%d",&public);
    
       printf("\nEnter the fuel type of the vehicle.\nElectric:[1]\nGasoline[2]\nDiesel[3]\nLPG[4]: ");
       scanf("%d",&type);


       printf("\nEnter the class of the vehicle.\n"
       "Vehicles with 2 axles and the wheelbase of less than 3.2 m:[1]\n"
       "Vehicles with 2 axles and the wheelbase longer than 3.2 m:[2]\n"
       "3 axle vehicles:[3]\n"
       "4 and 5 axle vehicles:[4]\n"
       "Vehicles with 6 or more axles:[5]\n"
       "Motorcycles:[6]");
       scanf("%d",&class);
       
       char dt3aa=dt3a(km,engine_capacity,public,type,class);
       char dt3bb=dt3b(km,engine_capacity,public,type,class);
       
       if(dt3aa == dt3bb){
          printf("\nBoth answers are the same.");
          if(dt3aa == 'y')
             printf("\nThe result: Ecotax.");
          else if(dt3aa == 'n')
             printf("\nThe result: No tax");          
       }

       if(dt3aa != dt3bb){
          printf("\nThe answers are different.");
          if(dt3aa == 'y')
             printf("\nThe result of function dt3a: Ecotax.");
          else if(dt3aa == 'n')
             printf("\nThe result of function dt3a: No tax");
          if(dt3bb == 'y')
             printf("\nThe result of function dt3b: Ecotax."); 
          else if(dt3bb == 'n')     
             printf("\nThe result of function dt3b: No tax");          
       }       
       
    }
    
    return 0;
}
