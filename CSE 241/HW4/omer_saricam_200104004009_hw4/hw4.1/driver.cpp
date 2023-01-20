#include <iostream>
#include <list>
#include "dayofyearset.h"


using namespace std;
using namespace doys;


int main(){

   cout<<endl<<"------DayofYearSet and DayOfYear constructors is being tested------";
   DayofYearSet::DayOfYear day1{10,24};
   DayofYearSet::DayOfYear day2(5,10);
   DayofYearSet::DayOfYear day3(5,12);	
   DayofYearSet::DayOfYear day4(4,23);	

   DayofYearSet d1 = {day1,day2,day3,day4};

   DayofYearSet::DayOfYear day5{1,14};
   DayofYearSet::DayOfYear day6(8,30);
   DayofYearSet::DayOfYear day7(10,24);	
   DayofYearSet::DayOfYear day8(5,12);
   DayofYearSet::DayOfYear day9(11,11);

   DayofYearSet d2 = {day5,day6,day7,day8,day9}; 

   cout<<endl<<"The objects generated successfully.";

   /////

   cout<<endl<<endl<<"------Size() method is being tested------";
   cout<<endl<<"Size of d1: "<<d1.Size();
   cout<<endl<<"Size of d2: "<<d2.Size();
   cout<<endl<<"The process is successful";

   /////

   cout<<endl<<endl<<"------iterator_() method is being tested------";
   cout<<endl<<"This method returns what value is in the index entered as a parameter in a set.";
   cout<<endl<<"A set was created with the values 1,2,3,4,5,6,7 in it.";
   set<int>set1 = {1,2,3,4,5,6,7};
   cout<<endl<<"If we want to know the value in the second index: ";
   cout<<endl<<"Returned value: "<<d1.iterator_(set1,2);
   cout<<endl<<endl<<"If we want to know the value in the fourth index: ";
   cout<<endl<<"Returned value: "<<d1.iterator_(set1,4);   
   cout<<endl<<"The process is successful";

   /////

   cout<<endl<<endl<<"------getMonth() method is being tested------";
   cout<<endl<<"returned value for day4(4,23): "<<day4.getMonth();
   cout<<endl<<"returned value for day6(8,30): "<<day6.getMonth();
   cout<<endl<<"The process is successful";

   /////

   cout<<endl<<endl<<"------getDay() method is being tested------";
   cout<<endl<<"returned value for day4(4,23): "<<day4.getDay();
   cout<<endl<<"returned value for day6(8,30): "<<day6.getDay();
   cout<<endl<<"The process is successful";

   /////
   
   cout<<endl<<endl<<"------setMonth() method is being tested------";
   DayofYearSet::DayOfYear day_(9,11);
   cout<<endl<<"Old month value of day_ object: "<<day_.getMonth();
   day_.setMonth(12);
   cout<<endl<<"After we set the month value 12: "<<day_.getMonth();
   day_.setMonth(2);
   cout<<endl<<"After we set the month value 2: "<<day_.getMonth();
   cout<<endl<<"The process is successful";

   /////

   cout<<endl<<endl<<"------setDay() method is being tested------";
   cout<<endl<<"Old day value of day_ object: "<<day_.getDay();
   day_.setDay(12);
   cout<<endl<<"After we set the day value 12: "<<day_.getDay();
   day_.setDay(27);
   cout<<endl<<"After we set the day value 27: "<<day_.getDay();
   cout<<endl<<"The process is successful";

   /////
   
   cout<<endl<<endl<<"------Stream insertion operator is being tested------";
   cout<<endl<<"d1 object: "<<d1;

   cout<<endl<<"d2 object: "<<d2;

   cout<<endl<<"Successfully printed.";
   
   /////
   
   cout<<endl<<endl<<"------operator== is being tested------";
   cout<<endl<<"Checking if object d1 is equal to d2";
   if( d1 == d2) cout<<endl<<"The objects are same";
   else cout<<endl<<"The objects are not same";
   
   cout<<endl<<"Checking if object d1 is equal to itself";
   if( d1 == d1) cout<<endl<<"The objects are same";
   else cout<<endl<<"The objects are not same";
   cout<<endl<<"The process is successful";

   /////

   cout<<endl<<endl<<"------operator!= is being tested------";
   cout<<endl<<"Checking if object d1 is not equal to d2";
   if(d1 != d2) cout<<endl<<"The objects are not same";
   else cout<<endl<<"The objects are same";

   cout<<endl<<"Checking if object d1 is not equal to itself";
   if(d1 != d1) cout<<endl<<"The objects are not same";
   else cout<<endl<<"The objects are same";   
   cout<<endl<<"The process is successful";

   /////

   cout<<endl<<endl<<"------remove() method is being tested.------";
   
   cout<<endl<<"0th(10,24) index of object d1 will be removed from the set"; 
   cout<<endl<<endl<<"old d1";
   cout<<d1;
   d1.remove(0);
   cout<<endl<<endl<<"new d1";
   cout<<d1; 

   cout<<endl<<"4th(11,11) index of object d2 will be removed from the set";
   cout<<endl<<endl<<"old d2:";
   cout<<d2;
   cout<<endl<<endl<<"new d2:";
   d2.remove(4);
   cout<<d2;
   cout<<endl<<"The process is successful";

   /////

   cout<<endl<<endl<<"------operator+ is being tested------";
   cout<<endl<<"Day1 (DayOfYear data type) object containing 10th month and 24th day values will be added to d1.";
   d1+day1;
   cout<<d1;	

   cout<<endl<<"Day9 (DayOfYear data type) object containing 11th month and 11th day values will be added to d2.";
   d2+day9;
   cout<<d2;	  

   /////

   cout<<endl<<endl<<"------Operator+ (union set) is being tested------";
   cout<<endl<<"d1 and d2 objects obtained from DayofYearSet class will be collected and assigned to d3.";
   DayofYearSet d3 = d1 + d2;   
   cout<<d3;
   cout<<endl<<"d3 and d2 objects obtained from DayofYearSet class will be collected and assigned to d3.";
   cout<<d3;
   cout<<endl<<"The process is successful";

   /////

   cout<<endl<<endl<<"------Operator- (difference set) is being tested------";
   cout<<endl<<"d1-d2: ";
   d3 = d1-d2;
   cout<<d3;   
   
   cout<<endl<<endl<<"d2-d1: ";
   d3 = d2-d1;
   cout<<d3;
   cout<<endl<<"The process is successful";

   /////

   cout<<endl<<endl<<"------Operator- (removes an element from the set) is being tested------";
   cout<<endl<<"We will delete day5(1,14) element from the d3 set.";
   cout<<endl<<"old version of d3: "<<d3;
   d3 - day5;
   cout<<endl<<"new d3: "<<d3;

   cout<<endl<<"We will delete day9(11,11) element from the d3 set.";
   cout<<endl<<"old version of d3: "<<d3;
   d3 - day9;
   cout<<endl<<"new d3: "<<d3;   
   cout<<endl<<"The process is succesfull.";

   /////
   
   cout<<endl<<endl<<"------Operator^  intersection operator kontrol------";
   cout<<endl<<"The intersection of the set d1 and d2 will be printed on the screen";
   d3 = d1^d2;
   cout<<d3;

   cout<<endl<<"The intersection of the set d3 and d2 will be printed on the screen";
   d3 = d3^d2;
   cout<<d3;   
   cout<<endl<<"The process is successful.";

   /////
   

   cout<<endl<<endl<<"------Operator!  complement operator kontrol------";
   cout<<endl<<"Complement of d1: ";
   d3 = !d1;
   cout<<d3;

   cout<<endl<<"Complement of d2: ";
   d3 = !d2;
   cout<<d3;  
   cout<<endl<<"Process is successful";

   /////

   cout<<endl<<endl<<"------Operator[]  index operator kontrol------"; 
   
   cout<<endl<<"0th index of d1 will be printed on the screen";
   DayofYearSet::DayOfYear day11 = d1[0]; //Since I did not overload the stream insertion(<<) operator to print an object of the DayofYear data type directly to the screen, I print the received value like this
   d3 = {day11};
   cout<<endl<<d3;

   cout<<endl<<"3th index of d2 will be printed on the screen";
   day11 = d2[3];
   d3 = {day11};
   cout<<endl<<d3;
   cout<<endl<<"Process is successful";




}

