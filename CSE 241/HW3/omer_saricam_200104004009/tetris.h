#ifndef _TETRIS_H_
#define _TETRIS_H_
#include <vector>

using namespace std;
using namespace tetromino_namespace;

namespace tetris_namespace{

class Tetris{


   public:
      
      
      Tetris(const int table_row,const int table_column);
      /*
      * parameters: It takes the length of the table row and table column
      *
      * to do: creates a Tetris object. Arranges the table variable.
      *
      */      
      
      ~Tetris();  //Frees the space allocated to table variable
      
      void add(const Tetromino& t1); 
      /*
      * parameters: takes a Tetromino object
      *
      * to do: Adds tetromino to the table. The new Tetromino will be added at the top row in the middle.
      *
      * return: nothing
      */
      
      template<typename T>      
      int position_ctrl(Tetromino &t1,T x,T y);   
      /*
      * parameters: position_ctrl() function takes another tetromino object, the relative position of the other tetromino(x and y).
      *
      * to do: It checks whether there is a suitable place for the tetromino entered in the coordinates specified in the table
      *
      * return: If the tetromino can fit at the specified position completely, then it returns 1; returns 3 if there is a problem because of the bounds of the table; otherwise returns 0.
      */
      
           
      void draw(); 
      /*
      * parameters: nothing
      *  
      * to do: draws the Tetris board. It will optionally start the drawing from the top
      *
      * return: nothing
      */
            
      void animate(Tetromino &t1);
      /*
      * parameters: tetromino to be animated
      *
      * to do: animate the added tetromino dropping to the bottom of the board
      *
      * return: nothing
      */
            
      int where_to_put(Tetromino &t1,const int target_column); 
      /*
      * parameters: tetromino that we want to find where it must drop in the table, and the column value that user entered.
      *
      * to do: Calculates where the tetromino will fall on the table.
      *
      * return: the row value of where the tetromino will drop
      */   
      
      char** array_copy(char const* const* array, const int row, const int column); 
      /*
      * parameters: array that we want to copy, row and column value of that array.
      *
      * to do: Copies the array entered as a parameter
      *
      * return: the copied array
      */        
            
      char** get_table() const;  //returns the table private data member
      
      void set_table(char const* const* array); //Copies the array entered as a parameter to the table private data member of the object
      
      int get_table_row() const;  //returns the table_row private data member
      
      int get_table_column() const;  //returns the table_column private data member
      
      void operator+=(Tetromino& t1);  //adds a Tetromino to the board. The new Tetromino will be added at the top row in the middle
   
   private:
      
      char **table=nullptr;
      int table_row;
      int table_column;



};


}

























#endif
