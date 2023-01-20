#include <stdio.h>


typedef struct database{
   tables * tList; /* to be implemented as a linked list */
   int n; /* num of entries */
   char * name; /* table name */
}database;

typedef struct tables{
   tables *next;  
   table * t;
}tables;

typedef struct table{
   char **field;
   char **type;
   bool *isNull;
   bool *isKey;
}table;


int main(){

   printf("\nI couldn't spare time for this homework due to final exams.");
}
