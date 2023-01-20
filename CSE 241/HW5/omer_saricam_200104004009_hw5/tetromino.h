#ifndef _TETROMINO_H_
#define _TETROMINO_H_
#include <vector>
#include <array>


using namespace std;


namespace tetromino_namespace{

enum class tetrominos{I='I',O='O',T='T',J='J',L='L',S='S',Z='Z'};




class Tetromino{

   private:                     
                                 
       char** our_tetro = nullptr;     
       char letter;
       
       int tetro_row;
       int tetro_column;                                      


    public:        
       
       Tetromino();                      
                                  
       Tetromino(tetrominos shape_type,char input2); 
       
       ~Tetromino(); //Frees the space allocated to our_tetro variable
       
       void print();
       /*
       * parameters: none
       *
       * to do: prints the tetromino(our_tetro variable) on the screen
       *
       * return: nothing
       *
       */
       
       void rotate(const int direction);              
       /*
       * parameters: takes as parameter which direction the tetromino wants to be rotated(left=1 right=0)
       *
       * to do: rotates the tetromino in the specified direction
       *
       * return: nothing
       *
       */
             
       
       char** get_our_tetro() const; //returns the our_tetro private data member

       int get_tetro_row() const;  //returns the tetro_row private data member
       
       int get_tetro_column() const;  //returns the tetro_column private data member
       
       char get_letter() const;  //returns the get_letter private data member
       
       void operator=(const Tetromino& t1);  //It assigns the private data members of the tetromino object, which is taken as a parameter, to the desired tetromino object.
};


}














#endif
