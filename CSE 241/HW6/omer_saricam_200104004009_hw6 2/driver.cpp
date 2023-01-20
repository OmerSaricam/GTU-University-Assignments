#include <iostream>
#include <memory>
#include <string>
#include <algorithm>

#include "pfarray.h"
#include "pfarray.cpp"


using namespace std;

using namespace PFArraySavitch;

    
    
int main()
{
 
  cout<<endl<<endl<<"-----A PFArray object(arr1) with capacity 10 is created-----";

  PFArray<int> arr1;
  cout<<endl<<endl<<"-----addElement() method is being tested-----"<<endl;
  cout<<"The values 1,2,3,4,5 will be assigned to arr1";
  arr1.addElement(1);
  arr1.addElement(2);
  arr1.addElement(3);
  arr1.addElement(4);
  arr1.addElement(5);
  cout <<endl<< "arr1: ";
  for (auto it = arr1.begin(); it != arr1.end(); ++it)
    cout << *it << ' ';
  cout << endl;



  cout<<endl<<endl<<"-----Copy constructor is being tested-----"<<endl;
  PFArray<int> arr2(arr1);
  cout<<"arr1 values copied to arr2";
  cout << endl <<"arr2: ";
  for (auto it = arr2.begin(); it != arr2.end(); ++it)
    cout << *it << ' ';
  cout << endl;



  cout<<endl<<endl<<"----- Assignment operator is being tested -----"<<endl;
  PFArray<int> arr3;
  arr3 = arr1;
  cout<<"arr1 values assigned to arr3";
  cout << endl << "arr3: ";
  for (auto it = arr3.begin(); it != arr3.end(); ++it)
    cout << *it << ' ';
  cout << endl;



  cout<<endl<<endl<<"-----getCapacity() method is being tested."<<endl;
  cout<<"Capacity of arr3: "<<arr3.getCapacity(); 

  cout<<endl<<endl<<"-----getNumberUsed() method is being tested."<<endl;
  cout<<"Used number of arr3: "<<arr3.getNumberUsed();   
  


  cout<<endl<<endl<<"-----emptyArray() method is being tested.-----"<<endl;
  arr3.emptyArray();
  cout << "arr3 after emptying: ";
  for (auto it = arr3.begin(); it != arr3.end(); ++it)
    cout << *it << ' ';
  cout << endl;



  cout<<endl<<endl<<"----- full() method is being tested.-----"<<endl;
  cout << "arr1 is full: " <<  arr1.full() << endl;
  arr1.addElement(6);
  arr1.addElement(7);
  arr1.addElement(8);
  arr1.addElement(9);
  arr1.addElement(10);
  cout << "(After adding up to the capacity)arr1 is full: " <<  arr1.full() << endl;



  cout<<endl<<endl<<"-----The [] operator is being tested.-----"<<endl;
  cout << "arr1[3] = " << arr1[3] << endl;
  arr1[3] = 100;
  cout << "(after arr1[3] = 100 operation done.)arr1[3] = " << arr1[3] << endl;
  cout<<endl<<"arr[15]: "<<arr1[15];

  



  cout<<endl<<endl<<"++++++++++The methods tested so far were those that exist in the PFArray class. Now newly added methods will be tested++++++++++"<<endl<<endl<<endl<<endl<<endl<<endl;





  cout<<endl<<endl<<"-----shared_ptr_copy() method is being tested-----"<<endl;
  shared_ptr<int> shptr1 = make_shared<int>(25);
  shared_ptr<int> shptr2 = make_shared<int>(30);
  cout<<"Created 2 shared_ptr variables named shptr1 containing the value 25 and shrptr2 containing the value 30. With this method, the value of shptr1 will be equal to shptr2.";
  arr1.shared_ptr_copy(shptr1,shptr2);
  cout<<endl<<"shptr1: "<<*shptr1;
  


  cout<<endl<<endl<<"-----empty() method is being tested-----"<<endl;
  cout<<"Is arr1 object empty?: "<<arr1.empty();



  cout<<endl<<endl<<"-----size() method is being tested-----"<<endl;
  cout << "arr1: "<<endl;
  for (auto it = arr1.begin(); it != arr1.end(); ++it)
    cout << *it << ' '; 
  cout<<endl<<"What is the size of arr1?: "<<arr1.size();  



  cout<<endl<<endl<<"-----clear() method is being tested-----"<<endl;  
  cout << "arr2 before clear(): "<<endl;
  for (auto it = arr2.begin(); it != arr2.end(); ++it)
    cout << *it << ' ';  
  arr2.clear();
  cout <<endl<< "arr2 after clear(): "<<endl;
  for (auto it = arr2.begin(); it != arr2.end(); ++it)
    cout << *it << ' ';  
  
  

  cout<<endl<<endl<<"-----erase() method is being tested-----"<<endl;
  cout << "arr1 before erasing element at index 1: ";
  for (auto it = arr1.begin(); it != arr1.end(); ++it)
    cout << *it << ' ';  
  arr1.erase(++arr1.begin());
  cout <<endl<< "arr1 after erasing element at index 1: ";
  for (auto it = arr1.begin(); it != arr1.end(); ++it)
    cout << *it << ' ';
  cout << endl;  

  {
  cout<<endl<<endl<<"-----begin() method is being tested-----"<<endl;
  auto it = arr1.begin();
  cout<<"*begin() of arr1: "<<*it;
  }
  
  {
  cout<<endl<<endl<<"-----end() method is being tested-----"<<endl;
  auto it = arr1.end();
  cout<<"*end() of arr1: "<<*it;
  }
  {
  cout<<endl<<endl<<"-----cbegin() method is being tested-----"<<endl;
  auto it = arr1.cbegin();
  cout<<"*cend() of arr1: "<<*it;
  }
  {
  cout<<endl<<endl<<"-----cend() method is being tested-----"<<endl;
  auto it = arr1.cend();
  cout<<"*cend() of arr1: "<<*it;  
  }
  

  
  cout<<endl<<endl<<"-----Testing the iterator-----"<<endl;
  cout << "arr1: ";
  for (auto it = arr1.begin(); it != arr1.end(); ++it)
    cout << *it << ' ';
  cout << endl;


  cout<<endl<<endl<<"-----operator*() is being tested-----"<<endl;
  auto it = arr1.begin();
  cout<<"*it(arr1.begin()): "<<*it; 

  cout<<endl<<endl<<"-----operator++() is being tested-----"<<endl;
  cout<<"*(++i): "<<*(++it);

  cout<<endl<<endl<<"-----operator!= is being tested-----"<<endl;
  auto it2 = arr1.end();
  cout<<"*it: "<<*it<<"   *it2: "<<*it2;
  if( it != it2) cout<<endl<<"They are not equal";
  else cout<<endl<<"They are equal";

  cout<<endl<<endl<<"-----operator->() is being tested-----"<<endl;
  cout<<"I couldn't find any field in the code that required using this";

  cout<<endl<<endl<<"-----operator--() is being tested-----"<<endl;
  cout<<"*(--i): "<<*(--it);

  cout<<endl<<endl<<"-----operator== is being tested-----"<<endl;
  cout<<"*it: "<<*it<<"   *it2: "<<*it2;
  if( it == it2) cout<<endl<<"They are equal";
  else cout<<endl<<"They are not equal";

  cout<<endl<<endl<<"-----getCurrent_() is being tested-----"<<endl;
  auto temp = it.getCurrent_();
  cout<<"auto temp = it.getCurrent_(); ";
  cout<<endl<<"temp: "<<temp;
  cout<<endl<<"*temp: "<<*temp;
  



  cout<<endl<<endl<<"-----Compability with range based loop is being tested-----"<<endl;
  cout<<"arr1: ";
  for(int x: arr1){
    cout << x << ' ';
  }


  cout<<endl<<endl<<"-----Compability with std::for_each is being tested-----"<<endl;
    for_each(arr1.begin(), arr1.end(), [](int x) {
            cout << x << ' ';
    }); 


  cout<<endl<<endl<<"-----Compability with std::find() is being tested-----"<<endl;  
   PFArray<int>::Iterator it3 = std::find(arr1.begin(), arr1.end(),7);
   cout<<"We wanted it to find the value 7 in arr1: *it3: "<<*it3<<endl;
   it3 = std::find(arr1.begin().getCurrent_(), arr1.end().getCurrent_(),33);
   cout<<"We wanted it to find the value 33 in arr1(there is not): *it3: "<<*it3<<endl;
   cout<<"Returned the last value as expected";

  

  cout<<endl<<endl<<"-----Compability with std::sort() is being tested-----"<<endl; 
  sort(arr1.begin().getCurrent_(), arr1.end().getCurrent_());
  cout << "arr1 after sorting: ";
  for (auto it = arr1.begin(); it != arr1.end(); ++it)
    cout << *it << ' ';
  cout << endl;
  


  cout<<endl<<endl<<"-----Move semantic functions is being tested-----"<<endl;
  PFArray<int> arr4;
  arr4 = move(arr1);
  cout<<"arr1 is moved to arr4"<<endl;
  cout << "arr4 after moving: ";
  for (auto it = arr4.begin(); it != arr4.end(); ++it)
    cout << *it << ' ';
  cout << '\n';  
  cout << "arr1 after moving: ";
  for (auto it = arr1.begin(); it != arr1.end(); ++it)
    cout << *it << ' ';
  cout << endl;




}
