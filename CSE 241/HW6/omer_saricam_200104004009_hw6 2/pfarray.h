//This is the header file pfarray.h. This is the interface for the class 
//PFArray. Objects of this type are partially filled arrays with base type T.
#ifndef PFARRAY_H
#define PFARRAY_H
#include <iostream>
#include <memory>


using namespace std;



namespace PFArraySavitch
{
    template<class T>
    class PFArray
    {
    public:
        PFArray( ); //Initializes with a capacity of 10.

        PFArray(const PFArray<T>& rightSide);

        void addElement(const T& element);

        bool full( ) const; //Returns true if the array is full, false otherwise. 

        int getCapacity( ) const;

        int getNumberUsed( ) const;

        void emptyArray( );
        //Resets the number used to zero, effectively emptying the array.

        T& operator[](const int index);
        //Read and change access to elements 0 through numberUsed - 1.

        void operator =(const PFArray<T>& rightSide);
        
        virtual ~PFArray( );

        //The methods so far came ready-made from the PFArray class.
        //link: https://github.com/sglbl/sglbl.github.io/tree/main/Others/Cpp_Source_Codes/Ch16
        //I added the next ones according to what was requested from the homework.

        class Iterator {
            public:   
		
		//https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
		using iterator_category = std::forward_iterator_tag;
		using difference_type   = std::ptrdiff_t;
		using value_type        = int;
		using pointer           = int*;
		using reference         = int&;		
		            
                Iterator();

                Iterator(T* current);

                T& operator*() const;

                Iterator& operator++();

                bool operator!=(const Iterator& other) const;

                T* operator->() const;

                Iterator& operator--();

                bool operator==(const Iterator& other) const;

                T* getCurrent_() const;

                Iterator operator-(const Iterator& other) const;

                bool operator<(const Iterator& other) const;
                bool operator>(const Iterator& other) const ;
                Iterator operator+(int i) ;
                Iterator operator-(int i) ;
                

            private:
                T* current_;
        };

        void shared_ptr_copy(shared_ptr<T> sp1, const shared_ptr<T> sp2);
        //Equalizes the elements of one shared_ptr variable to another. But they don't show the same memory space.

        int empty() const;
        //Test whether container is empty 

        int size() const;
        //Return container size 

        void clear();   
        //Clear all content  

        void erase(const Iterator& it); 
        //Erase elementpointed by the given iterator 
       
        Iterator begin();
        //Return iterator to beginning  

        Iterator end(); 
        //Return iterator to end 

        Iterator cbegin() const;
        //Returna constantiterator to beginning 

        Iterator cend() const;    
        //Return a constant iterator to end 
        
        PFArray(PFArray<T>&& other);  
        //Move constuctor

        void operator=(PFArray<T>&& other);
        //Move assignment operator

        shared_ptr<T> getA() const{return a;}

        void setCapacity(const int num){ capacity = num; }

        void setUsed(const int num){ used = num; } 

        void setA(const shared_ptr<T> a_){ a = a_;}   
           

        
    private:
        shared_ptr<T> a; //for an array of .
        int capacity; //for the size of the array.
        int used; //for the number of array positions currently in use.
    };
    
    

}



#endif //PFARRAY_H
