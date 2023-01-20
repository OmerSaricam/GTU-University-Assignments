#ifndef _TETRIS_H_
#define _TETRIS_H_
#include <vector>

using namespace std;



class Tetris{


   public:
      
      vector<vector<char>> table; 
      
      Tetris(const int table_row,const int table_column);
      /*
      * parameters: It takes the length of the table row and table column
      *
      * to do: creates a Tetris object. Arranges the table variable.
      *
      */      
      
      void add(const Tetromino t1);   //buna const koyabilirsin
      /*
      * parameters: takes a Tetromino object
      *
      * to do: Adds tetromino to the table. The new Tetrominowill be added at the top row in the middle.
      *
      * return: nothing
      */
      
      template<typename T>      
      int canfit(vector<vector<char>> tetro,T x,T y,const char letter);   
      /*
      * parameters: canfit() function takes another tetromino(tetro), the relative position of the other tetromino(x and y) and the specific letter of the tetromino.
      *
      * to do: It checks whether there is a suitable place for the tetromino entered in the coordinates specified in the table.
      *        It also checks for a space in the bottom line, which breaks the bestfit condition.
      *
      * return: If the tetromino can fit at the specified position without any holes, then it returns 1; returns 2 if the region is suitable but if the bestfit condition does not occur because but there is a space in between; returns 3 if it is not a best fit because it is outside the table; otherwise returns 0.
      */
      
      void Fit(int &row,int &column,const int target_row,const int target_column,Tetromino &t1,const int direction);
       /*
      * parameters: Gets the current row and column coordinates of the tetromino, the target row and target column coordinates, the tetromino to be printed on the screen, 
      *             whether the tetromino will move to the left or to the right(direction).
      *
      * to do: rotates and moves the added Tetrominoso that when it is dropped to the bottomit will produce the best fit.
      *
      * return: nothing
      */
           
      void draw(); //Tetromino print fonk ile aynı
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
      * to do: animate theadded tetromino dropping to the bottom of the board
      *
      * return: nothing
      */
            
      vector<int> where_to_put(Tetromino &t1); //2 elemanlı vektör döndürecek
      /*
      * parameters: tetromino that we want to find where it fits best in the table
      *
      * to do: Finds the best coordinate in the table for the tetromino using the canfit method.
      *
      * return: the best coordinates it finds.
      */   
   
   private:
   
      int table_row;
      int table_column;



};




























#endif
