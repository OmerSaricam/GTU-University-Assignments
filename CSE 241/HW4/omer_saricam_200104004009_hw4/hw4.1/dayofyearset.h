#ifndef _DAYOFYEARSET_H_
#define _DAYOFYEARSET_H_
#include <list>
#include <set>
#include <iostream>


using namespace std;

namespace doys{  //day of year set


   class DayofYearSet{



      public:
         
         class DayOfYear{

            private:
               int month;
               int day;
               static const int day_numbers_in_months[];
               
            public:
               
               DayOfYear();

               DayOfYear(const int month,const int day);

               int getMonth() const;
               //returns the month value

               int getDay() const;
               //returns de day value

               void setMonth(const int month);
               //set the month value

               void setDay(const int day);
               //set the day value

               static int getDay_number_in_month(const int month_num);
               //It detects the value entered as a parameter as a month and returns the number of days in that month.
                               
         };

         DayofYearSet(list<DayOfYear>& days);
         //This is the second constructor I wrote to speed things up. The logic is the same as the other. It takes parameter from list type and assigns it to dayofyear_objects variable.

         DayofYearSet(initializer_list<DayOfYear> days);
         //list initializer constructor that takes lists such as {d1, d2, d3}, where d’s are DayOfYearobjects.

         ~DayofYearSet();

         DayOfYear* getDayofyear_objects() const;
         //returns the dayofyear_objects variable;

         int Size() const; //getSize();
         //Returns the size value. We can assume this as getSize();

         int iterator_(set<int> set1,const int index);
         //returns what value is in the index entered as a parameter in a set.

         friend ostream & operator << (ostream &out, const DayofYearSet &r);
         //It prints the month and day values of the elements in the dayofyear_object array from the DayOfYear data type in the object derived from the DayofYearSet class.

         bool operator==(DayofYearSet& r);
         //Checks the equality of the two sets. Returns 1 if equal, 0 otherwise.

         bool operator!=(DayofYearSet& r);
         //Checks the equality of the two sets. Returns 0 if equal, 1 otherwise.

         void remove(const int index);
         //Removes the element at the specified index from the set.

         void operator+(const DayofYearSet::DayOfYear& d);
         //adds an element to the set.

         DayofYearSet operator+(const DayofYearSet& d);
         //returns the union set.

         DayofYearSet operator-(const DayofYearSet& d);
         //returns the differenceset.

         void operator-(const DayofYearSet::DayOfYear& d);
         //removes an element from the set

         DayofYearSet operator^(const DayofYearSet& d);
         //returns the intersectionset.

         DayofYearSet operator!();
         //returns the complement set

         DayofYearSet::DayOfYear operator[](const int index);
         //returns the element at given position.

         private:
         
            DayOfYear* dayofyear_objects = nullptr;
            
            int size;
   };

}


#endif
