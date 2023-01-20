//This is the implementation file: pfarray.cpp. 
//This is the implementation of the template class PFArray.
//The interface for the template class PFArray is in the file pfarray.h.

#include "pfarray.h"
#include <iostream>
#include <memory>
#include <string>
#include <algorithm>

using namespace std;

namespace PFArraySavitch
{

    template<class T>
    PFArray<T>::PFArray( ) :capacity(10), used(0)  
    {
        a = shared_ptr<T>(new T[10], std::default_delete<T[]>());
        //The array is first created with a capacity of 10 elements. If not enough, its area is doubled.
    }



    template<class T>
    PFArray<T>::PFArray(const PFArray<T>& rightSide) 
    {
        if (capacity != rightSide.getCapacity())
        {
            a= shared_ptr<T>(new T[rightSide.getCapacity()], std::default_delete<T[]>());

        }

        capacity = rightSide.getCapacity();
        used = rightSide.getNumberUsed();
        for (int i = 0; i < used; i++)
            a.get()[i] = rightSide.getA().get()[i];
    }

    template<class T>
    void PFArray<T>::addElement(const T& element)
    {
        if (used >= capacity)
        {
            shared_ptr<T> temp = shared_ptr<T>(new T[capacity], std::default_delete<T[]>());
            this->shared_ptr_copy(temp,a);
            
            a= shared_ptr<T>(new T[capacity*2], std::default_delete<T[]>());

            this->shared_ptr_copy(a,temp);
            capacity = capacity*2;
        }
        
        a.get()[used] = element;
        used++;
    }

    template<class T>
    bool PFArray<T>::full( ) const    
    {
        return (capacity == used);
    }

    template<class T>
    int PFArray<T>::getCapacity( ) const
    {
        return capacity;
    }

    template<class T>
    int PFArray<T>::getNumberUsed( ) const
    {
        return used;
    }

    template<class T>
    void PFArray<T>::emptyArray( ) 
    {
        used = 0;
    }

    template<class T>
    T& PFArray<T>::operator[](const int index)
    {

      try{
        if (index >= used){
            throw -1;
        }
      }
      catch(int x){
        cout<<endl<<"Exception caught! Illegal index in PFArray. Error: ";
      }  

      return a.get()[index];
    }

    template<class T>
    void PFArray<T>::operator =(const PFArray<T>& rightSide)
    {
        if (capacity != rightSide.getCapacity())
        {
            a= shared_ptr<T>(new T[rightSide.getCapacity()], std::default_delete<T[]>());

        }

        capacity = rightSide.getCapacity();
        used = rightSide.getNumberUsed();
        for (int i = 0; i < used; i++)
            a.get()[i] = rightSide.getA().get()[i];
    }
    

    template<class T>
    PFArray<T>::~PFArray( )
    {

    }
    
    template<class T>
    void PFArray<T>::shared_ptr_copy(shared_ptr<T> sp1, const shared_ptr<T> sp2){
       
       for(int i=0; i<capacity; i++){
          sp1.get()[i] = sp2.get()[i];
       }
    }

    template<class T> 
    int PFArray<T>::empty() const{
        
        if(used == 0) return 1;
        else return 0;
    }

    template<class T> 
    int PFArray<T>::size() const{
        
        return used;
    }

    template<class T> 
    void PFArray<T>::clear() {
        for (int i = 0; i < used; i++) {
            a.get()[i] = T();
        }
        used = 0;
    }

    template<class T> 
    PFArray<T>::Iterator::Iterator(T* current) : current_(current) {}

    template<class T> 
    PFArray<T>::Iterator::Iterator() {}
    
    template<class T> 
    T& PFArray<T>::Iterator::operator*() const {
        return *current_;
    }

    template<class T> 
    typename PFArray<T>::Iterator& PFArray<T>::Iterator::operator++() {
        ++current_;
        return *this;
    }

    template<class T> 
    bool PFArray<T>::Iterator::operator!=(const Iterator& other) const {
        return current_ != other.getCurrent_();
    }

    template<class T> 
    T* PFArray<T>::Iterator::operator->() const {
        return current_;
    }    

    template<class T> 
    typename PFArray<T>::Iterator& PFArray<T>::Iterator::operator--() {
        --current_;
        return *this;
    }

    template<class T> 
    bool PFArray<T>::Iterator::operator==(const Iterator& other) const {
        return current_ == other.getCurrent_();
    }        

    template<class T> 
    T* PFArray<T>::Iterator::getCurrent_() const{
        return current_;
    }

    template<class T>
    bool PFArray<T>::Iterator::operator<(const Iterator& other) const { return current_ < other.getCurrent_(); }

    template<class T>
    bool PFArray<T>::Iterator::operator>(const Iterator& other) const { return current_ > other.getCurrent_(); }

    template<class T>
    typename PFArray<T>::Iterator PFArray<T>::Iterator::operator+(int i) { Iterator it = *this; it.current_ += i; return it; }

    template<class T>
    typename PFArray<T>::Iterator PFArray<T>::Iterator::operator-(int i) { Iterator it = *this; it.current_ -= i; return it; }












    template<class T> 
    typename PFArray<T>::Iterator PFArray<T>::begin() {
        
        return Iterator(a.get());        
    }

    template<class T> 
    typename PFArray<T>::Iterator PFArray<T>::end() {
        return Iterator(a.get() + used);
    }     

    template<class T> 
    void PFArray<T>::erase(const Iterator& it) {
        T* element = it.getCurrent_();
        int index = element - a.get();
        for (int i = index; i < used - 1; i++) {
            a.get()[i] = a.get()[i + 1];
        }
        used--;
    }

    template<class T> 
    typename PFArray<T>::Iterator PFArray<T>::cbegin() const {
        return Iterator(a.get());
    }
    
    template<class T> 
    typename PFArray<T>::Iterator PFArray<T>::cend() const {
        return Iterator(a.get() + used);
    }

    template<class T> 
    PFArray<T>::PFArray(PFArray<T>&& other){
    
        a = other.getA();
        capacity = other.getCapacity(); 
        used = other.getNumberUsed();
          
        other.setCapacity(0);
        other.setUsed(0);
        other.setA(nullptr);
    }


    template<typename T> 
    void PFArray<T>::operator=(PFArray<T>&& other) {
        a = other.getA();
        capacity = other.getCapacity(); 
        used = other.getNumberUsed();

        other.setCapacity(0);
        other.setUsed(0);
        other.setA(nullptr);        
    }   

   

                

}