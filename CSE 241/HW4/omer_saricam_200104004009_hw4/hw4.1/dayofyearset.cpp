#ifndef _DAYOFYEARSET_
#define _DAYOFYEARSET_
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <vector>
#include "dayofyearset.h"

using namespace std;
using namespace doys;

const int DayofYearSet::DayOfYear::day_numbers_in_months[] = {31,29,31,30,31,30,31,31,30,31,30,31};

DayofYearSet::DayOfYear::DayOfYear(){}

DayofYearSet::DayOfYear::DayOfYear(const int month,const int day){

    if(month >= 1 && month <= 12){
       this->month = month;
    }
    
    else{
        cout<<endl<<"The month value must be between 1 and 12";
        return;
    } 

    if(day <= day_numbers_in_months[month-1]){
        this->day = day;
    }
    
    else{
        cout<<endl<<"There is no such day in this month";
        return;
    }
}

int DayofYearSet::DayOfYear:: getMonth() const{
    return month;
}


int DayofYearSet::DayOfYear:: getDay() const{
    return day;
}

void DayofYearSet::DayOfYear::setMonth(const int month){
    this->month = month;
}

void DayofYearSet::DayOfYear::setDay(const int day){
    this->day = day;
}


int DayofYearSet::DayOfYear::getDay_number_in_month(const int month_num){

    return day_numbers_in_months[month_num-1];
}



DayofYearSet::DayofYearSet(list<DayOfYear>& days) : dayofyear_objects(new DayOfYear[days.size()]) {
    
    size = days.size();

    copy(days.begin(), days.end(), dayofyear_objects);
}

DayofYearSet::DayofYearSet(initializer_list<DayOfYear> days) : dayofyear_objects(new DayOfYear[days.size()]) {
    
    size = days.size();

    copy(days.begin(), days.end(), dayofyear_objects);
}

DayofYearSet::~DayofYearSet(){

}

DayofYearSet::DayOfYear* DayofYearSet::getDayofyear_objects() const{
   return dayofyear_objects;
}


int DayofYearSet::Size() const{
    return size;
}


int DayofYearSet::iterator_(set<int> set1,const int index){

    set<int>::iterator it;
    int count = 0;
    for (it = set1.begin(); it != set1.end(); ++it){
       
       if(count == index) return *it;

       count++;
    }
      
}


ostream & doys::operator << (ostream &out, const DayofYearSet &r){

    out<<endl<<"----DayofYearSet details will be printed----";
    for(auto i=0; i<r.size; i++){
        out<<endl<<"For the "<<i+1<<". element:";
        out<<endl<<"month: "<<r.dayofyear_objects[i].getMonth();
        out<<endl<<"day: "<<r.dayofyear_objects[i].getDay();
    }

    return out;
}

bool DayofYearSet::operator==(DayofYearSet& r){

   if(size != r.Size())  return false;

   else{
  
     set<int> our_month;
     set<int> our_day;

     for(auto i=0; i<size; i++){
        our_month.insert(dayofyear_objects[i].getMonth());
        our_day.insert(dayofyear_objects[i].getDay());
     }

     set<int> r_month;
     set<int> r_day;
     for(int i=0; i<size; i++){
        r_month.insert(r.getDayofyear_objects()[i].getMonth());
        r_day.insert(r.getDayofyear_objects()[i].getDay());
     }

     for(decltype(1) i=0; i<size; i++){
        if(iterator_(our_month,i) != iterator_(r_month,i) || iterator_(our_day,i) != iterator_(r_day,i)) return false;
     }
     return true;

          
   }   
}


bool DayofYearSet::operator!=(DayofYearSet& r){

   if(size != r.Size())  return true;

   else{
  
     set<int> our_month;
     set<int> our_day;

     for(int i=0; i<size; i++){
        our_month.insert(dayofyear_objects[i].getMonth());
        our_day.insert(dayofyear_objects[i].getDay());
     }

     set<int> r_month;
     set<int> r_day;
     for(int i=0; i<size; i++){
        r_month.insert(r.getDayofyear_objects()[i].getMonth());
        r_day.insert(r.getDayofyear_objects()[i].getDay());
     }

     for(int i=0; i<size; i++){

        if(iterator_(our_month,i) != iterator_(r_month,i) || iterator_(our_day,i) != iterator_(r_day,i)) return true;
     }
     return false;

          
   }   
}


void DayofYearSet::remove(const int index) {

    DayOfYear* temp_dayofyear_objects = new DayOfYear[size - 1];

    //copying elements from the old array to the new array, skipping the element at the specified index
    for (int i = 0; i < index; i++) {
        temp_dayofyear_objects[i] = dayofyear_objects[i];
    }
    for (int i = index; i < size - 1; i++) {
        temp_dayofyear_objects[i] = dayofyear_objects[i + 1];
    }

    //size is reduced by 1 because an element is removed
    size = size - 1;

    //deleting the old array 
    delete[] dayofyear_objects;
    dayofyear_objects = nullptr;

    //reassigning the dayofyear_objects pointer to the new array
    dayofyear_objects = temp_dayofyear_objects;
}


void DayofYearSet::operator+(const DayofYearSet::DayOfYear& d){

    //I am checking this as the same element cannot be added to the set
    for(int i=0; i<size; i++){
       if(d.getMonth() == dayofyear_objects[i].getMonth() && d.getDay() == dayofyear_objects[i].getDay()) return; 
    }

    DayOfYear* temp_dayofyear_objects = new DayOfYear[size+1];
    for(int i = 0; i<size; i++){
        
         temp_dayofyear_objects[i] = dayofyear_objects[i];
    }
    temp_dayofyear_objects[size].setMonth(d.getMonth());
    temp_dayofyear_objects[size].setDay(d.getDay());
    size = size+1; 

    delete[] dayofyear_objects;

    dayofyear_objects = temp_dayofyear_objects; 

}

DayofYearSet DayofYearSet::operator+(const DayofYearSet& d){
    

     vector<int> our_month;
     vector<int> our_day;

     for(int i=0; i<size; i++){
        our_month.push_back(dayofyear_objects[i].getMonth());
        our_day.push_back(dayofyear_objects[i].getDay());
     }

     vector<int> d_month;
     vector<int> d_day;
     for(int i=0; i<d.Size(); i++){
        d_month.push_back(d.getDayofyear_objects()[i].getMonth());
        d_day.push_back(d.getDayofyear_objects()[i].getDay());
     }
     
     //If both sets have the same date, I delete one
     for(int i=0; i<our_month.size(); i++){
        
        vector<int>::iterator it1 = d_month.begin();
        vector<int>::iterator it2 = d_day.begin();
        
        for(int j=0; j<d_month.size(); j++){

            if(our_month[i] == d_month[j] && our_day[i] == d_day[j]){
               d_month.erase(it1);
               d_day.erase(it2);
               
            }
            it1++; it2++;
            
        }
     }

     for(int i = 0; i<d_month.size(); i++){
        our_month.push_back(d_month[i]);
        our_day.push_back(d_day[i]);
     }

     list<DayofYearSet::DayOfYear> list1;

     for(int i = 0; i <our_month.size(); i++){
        DayofYearSet::DayOfYear temp{our_month[i],our_day[i]};
        list1.push_back(temp);
     }
     
     DayofYearSet will_be_returned(list1);
     return will_be_returned;


}


DayofYearSet DayofYearSet::operator-(const DayofYearSet& d){

     vector<int> our_month;
     vector<int> our_day;

     for(int i=0; i<size; i++){
        our_month.push_back(dayofyear_objects[i].getMonth());
        our_day.push_back(dayofyear_objects[i].getDay());
     }

     vector<int> d_month;
     vector<int> d_day;
     for(int i=0; i<d.Size(); i++){
        d_month.push_back(d.getDayofyear_objects()[i].getMonth());
        d_day.push_back(d.getDayofyear_objects()[i].getDay());
     }
     
     //Elements that are the same as the removed set are identified here and removed from the subtracted set.
     vector<int>::iterator it1 = our_month.begin();
     vector<int>::iterator it2 = our_day.begin();     
     for(int i=0; i<our_month.size(); i++){
               
        for(int j=0; j<d_month.size(); j++){

            if(our_month[i] == d_month[j] && our_day[i] == d_day[j]){
               our_month.erase(it1);
               our_day.erase(it2);
               i--;
               it1--;
               it2--;
                              
            }       
            
        }
        it1++; it2++;
     }

     list<DayofYearSet::DayOfYear> list1;

     for(int i = 0; i <our_month.size(); i++){
        DayofYearSet::DayOfYear temp{our_month[i],our_day[i]};
        list1.push_back(temp);
     }
     
     DayofYearSet will_be_returned(list1);
     return will_be_returned;

}    


void DayofYearSet::operator-(const DayofYearSet::DayOfYear& d){

    for(int i=0; i<size; i++){

       if(dayofyear_objects[i].getMonth() == d.getMonth() && dayofyear_objects[i].getDay() == d.getDay()){
          remove(i);
          return;
       } 
    }

    cout<<" No element found matching the entered values";
}


DayofYearSet DayofYearSet::operator^(const DayofYearSet& d){

     vector<int> our_month;
     vector<int> our_day;

     for(int i=0; i<size; i++){
        our_month.push_back(dayofyear_objects[i].getMonth());
        our_day.push_back(dayofyear_objects[i].getDay());
     }

     vector<int> d_month;
     vector<int> d_day;
     for(int i=0; i<d.Size(); i++){
        d_month.push_back(d.getDayofyear_objects()[i].getMonth());
        d_day.push_back(d.getDayofyear_objects()[i].getDay());
     }
     
     //I detect common elements in two sets and assign them to another vector
     vector<int> common_month;
     vector<int> common_day;

     for(int i=0; i<our_month.size(); i++){
        
        for(int j=0; j<d_month.size(); j++){

            if(our_month[i] == d_month[j] && our_day[i] == d_day[j]){
               common_month.push_back(our_month[i]);
               common_day.push_back(our_day[i]);   
            }       
            
        }

     }

     list<DayofYearSet::DayOfYear> list1;

     for(int i = 0; i <common_month.size(); i++){
        DayofYearSet::DayOfYear temp{common_month[i],common_day[i]};
        list1.push_back(temp);
     }
     
     DayofYearSet will_be_returned(list1);
     return will_be_returned;

}


DayofYearSet DayofYearSet::operator!(){

    vector<int> all_months;
    vector<int> all_days;

    for(int i=1; i<=12; i++){
    
        for(int j=1; j<= DayOfYear::getDay_number_in_month(i); j++){
           all_months.push_back(i);
           all_days.push_back(j);
        }
    }

    vector<int> complement_months;
    vector<int> complement_days;

    for(int i=0; i<366; i++){ 
        
        int flag1=0;
        for(int k=0; k<size; k++){

           if(all_months[i] == dayofyear_objects[k].getMonth() && all_days[i] == dayofyear_objects[k].getDay()) flag1 = 1;  

        }
        if(flag1 == 0){
                complement_months.push_back(all_months[i]);
                complement_days.push_back(all_days[i]);            
        }    
    }

     list<DayofYearSet::DayOfYear> list1;

     for(int i = 0; i <complement_months.size(); i++){
        DayofYearSet::DayOfYear temp{complement_months[i],complement_days[i]};
        list1.push_back(temp);
     }
     
     DayofYearSet will_be_returned(list1);
     return will_be_returned;        


}

DayofYearSet::DayOfYear DayofYearSet::operator[](const int index){

    if(index < size){
        return dayofyear_objects[index];
    }

    else{
        cout<<endl<<"There is no such index value";
        exit(-1);
    }
}

#endif
