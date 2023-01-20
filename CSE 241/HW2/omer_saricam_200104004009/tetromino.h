#ifndef _TETROMINO_H_
#define _TETROMINO_H_
#include <vector>

using namespace std;




enum class tetrominos{I='I',O='O',T='T',J='J',L='L',S='S',Z='Z'};


vector<vector<char>> table_maker(int number1);
/*
* parameters: Number of tetrominos entered by the user
*
* to do: creates table 4*(number1*4). Creates the table where the game will be played, that is, the tetrominos will be lined up.
*
* return: the table it creates
*/



class Tetromino{

   private:
              
       vector<vector<char>> I1 { {'I','I','I','I'}};
       
       vector<vector<char>> O1 { {'O','O'},
                                 {'O','O'} };
       
       vector<vector<char>> T1 { {'T','T','T'},
                                 {' ','T',' '}};
       
       vector<vector<char>> J1 { {' ','J'},
                                 {' ','J'},
                                 {'J','J'}};
       
       vector<vector<char>> L1 { {'L',' '},
                                 {'L',' '},
                                 {'L','L'}};
       
       vector<vector<char>> S1 { {' ','S','S'},
                                 {'S','S',' '}};
       
       vector<vector<char>> Z1 { {'Z','Z',' '},
                                 {' ','Z','Z'}};                      


    public:        
       //vector<vector<vector<char>>> types1; //I'm storing user-entered 2D tetrominos in this 3D vector.     
       vector<vector<char>> our_tetro;
       
       char letter;
       
       Tetromino();                      
                                  
       Tetromino(tetrominos shape_type,char input2); //parametreler değişti
       
       void print(vector<vector<char>> vect);
       /*
       * parameters: tetromino to be printed(vect)
       *
       * to do: prints the entered tetromino on the screen
       *
       * return: nothing
       *
       */
       
                     
       vector<vector<char>> rotate(vector<vector<char>> vect,int direction);
       /*
       * parameters: takes as parameter which direction the tetromino wants to be rotated(left=1 right=0) and takes tetromino to be rotated(vect).
       *
       * to do: rotates the tetromino entered as a parameter in the specified direction
       *
       * return: rotated tetromino
       *
       */
             
             
       bool canFit(vector<vector<char>> tetro,vector<vector<char>> table,int x,int y);     
       /*
       * parameters: canFit() function takes another tetromino(tetro), the relative position of the other tetromino(x and y) and the table where I lined up the tetrominos 
       *              I didn't define table vector as a global because teachers was against the use of a global variable, so I sent it as a parameter.
       *
       * to do:: It checks whether there is a suitable place for the tetromino entered in the coordinates specified in the table.
       *         It also checks for a space in the bottom line, which breaks the bestfit condition.
       *
       * return:  If the other can fit at the specified position without any holes, then it returns true, otherwise it returns false
       */
       
       
       void putShape(vector<vector<char>> table,vector<Tetromino> tetro_objects);  //parametre eklendi
       /*
       * parameters: the table where I lined up the tetrominos
       *
       * to do: Using the canFit function, it checks whether the region in the table is suitable or not, if it is, it puts that tetromino in the table.
       *        Starting from the x=3 y=0 index of the table for each tetromino, it checks with the canFit function whether that cell and other cells where the tetromino will be placed are suitable.
       *        if that region is not suitable, it rotates the shape counterclockwise   
       *        Even if we rotate it 4 times, if that region is not suitable for the tetromino, we increase the y value by 1 and start to control the other region.
       *        If the y value is greater than one less than the number of columns in the table, all regions in the table have been checked.
       *        This means that the bestFit status cannot be created with the tetromino sequence entered by the user. 
       *        Then we need to change the order. I move the tetrominos one step to the right. vector[2] equals vector[1], vector[2] replaces vector[3] for example
       *        If the bestFit status cannot be obtained no matter how much we slide, the screen displays the bestFit status cannot be obtained with the tetrominos we have. 
       *        For example, if Z O Z is entered, the bestFit status will never be achieved. Because there will always be a gap in the bottom line.
       *
       * return: nothing         
       */  
       
};

















#endif
