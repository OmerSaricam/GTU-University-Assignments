#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, int s, int w);

char dt1a(double pl,double pw,double sl,double sw);
char dt1b(double pl,double pw,double sl,double sw);
void bastir(char a); ////The teacher(Cem Ayar) said you can use an extra function.

double dt2a(double x1,double x2,double x3,int x4,int x5);
double dt2b(double x1,double x2,double x3,int x4,int x5);

/* Write the prototype of the functions implementing the decision trees for the third problem */
//In the pdf it says:"The last two are supposed to be designed by you".So I change the functions.
//void dt3a(void);
//void dt3b(void);

char dt3a(double km,double engine,int public,int type,int class);
char dt3b(double km,double engine,int public,int type,int class);

#endif /* _UTIL_H_ */
