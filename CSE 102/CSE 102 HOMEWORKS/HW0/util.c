#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
	*n3= n1*d2 - n2*d1;
	*d3= d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
	*n3= n1*n2;
	*d3= d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
	*n3= n1*d2;
	*d3= d1*n2;
    fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) {
	int gcd;
	
	if(*n>=0 && *d>=0){
	if(*n<=*d){
		int i=1;
		while(i<=*n){
			if(*n%i==0 && *d%i==0){
				gcd=i;
			}
			i++;	
		}
	}
	
	else if(*d<*n){
		int j=1;
		while(j<=*d){
			if(*n%j==0 && *d%j==0){
				gcd=j;
			}
			j++;	
		}
	}
	
	}
	
	
	if(*n>0 && *d <0){
	if(*n<=*d){
		int i=1;
		while(i<=*d){
			if(*n%i==0 && *d%i==0){
				gcd=i;
			}
			i++;	
		}
	}
	
	else if(*d<*n){
		int j=1;
		while(j<=*n){
			if(*n%j==0 && *d%j==0){
				gcd=j;
			}
			j++;	
		}
	}
	}
	
	if(*n<0 && *d >0){
	if(*n<=*d){
		int i=1;
		while(i<=*d){
			if(*n%i==0 && *d%i==0){
				gcd=i;
			}
			i++;	
		}
	}
	
	else if(*d<*n){
		int j=1;
		while(j<=*n){
			if(*n%j==0 && *d%j==0){
				gcd=j;
			}
			j++;	
		}
	}
	}		
		
	if(*n<0 && *d <0){
	*n=*n*-1;
	*d=*d*-1;
	if(*n<=*d){
		int i=1;
		while(i<=*d){
			if(*n%i==0 && *d%i==0){
				gcd=i;
			}
			i++;	
		}
	}
	
	else if(*d<*n){
		int j=1;
		while(j<=*n){
			if(*n%j==0 && *d%j==0){
				gcd=j;
			}
			j++;	
		}
	}
	}
			
	*n=*n/gcd;
	*d=*d/gcd;
	

} /* end fraction_div */
