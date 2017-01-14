//INCLUDING HEADER FILES


#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <ctime>
using namespace std;


// constants
#define DIM_MIN 3
#define DIM_MAX 6


// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void saves_moves(void);
void Shuffler(int *array, int n);
int moves=0;
string mode;

int main()
{
    //Sleep so that the title appears after a while
Sleep(2800);
//Title appears
    greet();
    system("CLS");
    cout << endl << endl << endl;
int starter;
int movesleft=1;
while(1)

{
  cout << "To START GAME  press \"1\" " << endl;
  cout << "For Instructions press \"2\" "<< endl;
  cout << "Press \"3\" to EXIT." << endl;
  cin >> starter;
  system ("CLS");
  while(true)
  {

if (starter==1)
    {
HANDLE hConsole;
hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,10);
    cout << "Enter Board difficulty level: (3-6) ";
    cin >> d;

    cout << "FOR EASY MODE: Press \"E\"\n";
    cout << "FOR MASTER MODE: Press \"H\"\n";
    cin >> mode;


    if (d < DIM_MIN || d > DIM_MAX)
    {
        cout << "Board must be between " << DIM_MIN << " x " <<  DIM_MIN <<   " and " << DIM_MAX << " x " <<DIM_MAX << endl << endl;
        return 2;
    }

    // initialize the board
    init();
    // accept moves until game is won
    while (true)
                 {

        // draw the current state of the board
        cout <<endl;
        cout <<endl;
        cout <<endl;
        cout <<endl;

        draw();
        saves_moves();
        // prompt for move

 SetConsoleTextAttribute(hConsole,13);
 cout<<endl << endl;
  // check for win
  if (won())
        {
            cout << "congratulations genius!\n";
            break;
        }

if (movesleft==0)
{
    cout << "You lose!! Try the Easy Mode! " << endl;
    exit(1);
}

        cout << "Tile to move: ";
        int tile;
        cin >> tile;
        SetConsoleTextAttribute(hConsole,10);
        cout << "Moves = " << moves << endl;
        moves += 1;
        system ("CLS");
        if ((mode == "H") || (mode == "h"))
            {
                int total_moves = 0;
                if (d == 3)
                    total_moves = 300;
                if (d == 4)
                    total_moves = 400;
                if (d == 5)
                    total_moves = 500;
                if (d == 6)
                    total_moves = 600;
                if (d == 7)
                    total_moves = 700;
                if (d == 8)
                    total_moves = 800;
                if (d == 9)
                    total_moves = 900;

    movesleft=total_moves-moves;

cout <<"Moves Left = "<< total_moves - moves << endl;



            }
        // quit if user inputs 0 (for testing)





        if (tile == 0)
        {

            break;
        }

        // move if possible, else report illegality
        if (!move(tile))
        {
            cout << "Illegal move" << endl;
        }

             }
     }

     // INSTRUCTIONS!!
     if (starter==2)
     {
         cout << "The Game has 3 to 6 board difficulty levels." << endl;
         cout <<"The game has 2 modes. EASY and HARD. Easy mode has unlimited moves and Hard mode has limited moves." << endl;
         cout <<"The moves left are displayed on the top of the screen!" << endl;
    cout << "Enter the number in the tile to move the tile towards the empty space." << endl;
    cout << "Notice that only the adjacent tiles can be moved in the blank space." << endl;
    cout << "The Numbers are Initially in Descending Order.You have to arrange them in Ascending Order to win the game.Good Luck with that!"<< endl;
    string s;
    cout << endl << endl << endl;
    cout << "Press B to go back to main menu: ";
    cin>> s;
    system("CLS");
    if (s=="B"|| s=="b")
    {
        break;
    }
     }
     if (starter==3)
     {
         string quitter;
         cout << "Are you sure? (yes/no): "<< endl;
         cin>> quitter;
         system("CLS");
         if (quitter=="yes" ||quitter=="Yes" || quitter=="YES")
         {
               exit(0);
         }
       if (quitter=="no" ||quitter=="No" || quitter=="NO")
       {
           break;
       }
     }
  }
}

return 0;
}


/**
* Greets player.
*/
void greet(void)
{
HANDLE hConsole;
    hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(hConsole,3);
 cout << endl<< endl<< endl;
    cout << "         GGGGGGG             AAAAAA        MMMMMM          MMMMMM   EEEEEEEEEEEE                  OOOO         FFFFFFFFFFFFFF" << endl;
Sleep(50);
    cout << "       GGGGGGGGG            AAAAAAAA       MMMM MM        MM MMMM   EEEEEEEEEEEE                OOOOOOOO       FFFFFFFFFFFFFF" << endl;
Sleep(50);
    cout << "     GGGG                  AAAA  AAAA      MMMM  MM      MM  MMMM   EEEE                      OOOO    OOOO     FFFF" << endl;
Sleep(50);
    cout << "    GGGG                  AAAA    AAAA     MMMM   MM    MM   MMMM   EEEE                     OOOO      OOOO    FFFF" << endl;
Sleep(50);
    cout << "   GGGG                  AAAA      AAAA    MMMM    MM  MM    MMMM   EEEE                    OOOO        OOOO   FFFF"  << endl;
Sleep(50);
    cout << "   GGGG                 AAAAAAAAAAAAAAAA   MMMM     MMMM     MMMM   EEEEEEEEEEEE            OOOO        OOOO   FFFFFFFFFFFF" << endl;
Sleep(50);
    cout << "   GGGG                 AAAA        AAAA   MMMM              MMMM   EEEEEEEEEEEE            OOOO        OOOO   FFFFFFFFFFFF" << endl;
Sleep(50);
    cout << "   GGGG                 AAAA        AAAA   MMMM              MMMM   EEEE                    OOOO        OOOO   FFFF" << endl;
Sleep(50);
    cout << "    GGGG                AAAA        AAAA   MMMM              MMMM   EEEE                     OOOO      OOOO    FFFF" << endl;
Sleep(50);
    cout << "     GGGG    GGGGGGG    AAAA        AAAA   MMMM              MMMM   EEEE                      OOOO    OOOO     FFFF"    << endl;
Sleep(50);
    cout << "       GGGGGGGGGG  GG   AAAA        AAAA   MMMM              MMMM   EEEEEEEEEEEE                OOOOOOOO       FFFF" << endl;
Sleep(50);
    cout << "         GGGGGGG   GG   AAAA        AAAA   MMMM              MMMM   EEEEEEEEEEEE                  OOOO         FFFF"  << endl;
Sleep(50);
    cout << endl << endl<< endl;
    cout << "       FFFFFFFFFFFFFF   IIIIIIIIIIIIII   FFFFFFFFFFFFFF   TTTTTTTTTTTTTT   EEEEEEEEEEEEEE   EEEEEEEEEEEEEE   NNNNNN           NNNN" << endl;
Sleep(50);
    cout << "       FFFFFFFFFFFFFF   IIIIIIIIIIIIII   FFFFFFFFFFFFFF   TTTTTTTTTTTTTT   EEEEEEEEEEEEEE   EEEEEEEEEEEEEE   NNNN NN          NNNN" << endl;
Sleep(50);
    cout << "       FFFF                  IIII        FFFF                  TTTT        EEEE             EEEE             NNNN  NN         NNNN" << endl;
Sleep(50);
    cout << "       FFFF                  IIII        FFFF                  TTTT        EEEE             EEEE             NNNN   NN        NNNN" << endl;
Sleep(50);
    cout << "       FFFF                  IIII        FFFF                  TTTT        EEEE             EEEE             NNNN    NN       NNNN" << endl;
Sleep(50);
    cout << "       FFFFFFFFFFFF          IIII        FFFFFFFFFFFF          TTTT        EEEEEEEEEEEEEE   EEEEEEEEEEEEEE   NNNN     NN      NNNN" << endl;
Sleep(50);
    cout << "       FFFFFFFFFFFF          IIII        FFFFFFFFFFFF          TTTT        EEEEEEEEEEEEEE   EEEEEEEEEEEEEE   NNNN      NN     NNNN" << endl;
Sleep(50);
    cout << "       FFFF                  IIII        FFFF                  TTTT        EEEE             EEEE             NNNN       NN    NNNN" << endl;
Sleep(50);
    cout << "       FFFF                  IIII        FFFF                  TTTT        EEEE             EEEE             NNNN        NN   NNNN" << endl;
Sleep(50);
    cout << "       FFFF                  IIII        FFFF                  TTTT        EEEE             EEEE             NNNN         NN  NNNN" << endl;
Sleep(50);
    cout << "       FFFF             IIIIIIIIIIIIII   FFFF                  TTTT        EEEEEEEEEEEEEE   EEEEEEEEEEEEEE   NNNN          NN NNNN" << endl;
Sleep(50);
    cout << "       FFFF             IIIIIIIIIIIIII   FFFF                  TTTT        EEEEEEEEEEEEEE   EEEEEEEEEEEEEE   NNNN           NNNNNN" << endl;

Sleep(1000);

}

/**
* Initializes the game's board with tiles numbered 1 through d*d - 1
* (i.e., fills 2D array with values but does not actually print them).
*/

void init(void)
{
    int array1[(d*d)-1];
    int i=0;
    for (int row_Init = 0; row_Init< d; row_Init++)
      {
          for (int col_Init = 0; col_Init < d; col_Init++)
          {
    array1[i]=d*row_Init+col_Init+1;
    i=i+1;
          }
      }
      Shuffler(array1,(d*d)-1);
      for (int row_Init = 0; row_Init< d; row_Init++)
      {
          for (int col_Init = 0; col_Init < d; col_Init++)
          {

              board[row_Init][col_Init]=array1[d*row_Init+col_Init];
  }
}
board[d-1][d-1]=-1;
}

/**
* Prints the board in its current state.
*/
void draw(void)
{

    for (int draw_row = 0; draw_row < d; draw_row++)
    {
        HANDLE hConsole;
    hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole,0);
           cout <<"                         ";
        for (int draw_col = 0; draw_col < d; draw_col++)
      {
           if (board[draw_row][draw_col] == -1)
             {
                  // hides -1 behind underscore
 SetConsoleTextAttribute(hConsole,8);
                  cout << "       _";
                  continue;
             }

       //prints numbers
 SetConsoleTextAttribute(hConsole,12);
       cout << "    " << setw(4)<<  board[draw_row][draw_col];

      }
    cout << endl << endl;
    }
    cout <<endl << endl;
//    if ((mode == "h") || (mode == "H"))
//int total_moves = 0;





//moves++;




}




/**
* If tile borders empty space, moves tile and returns true, else
* returns false.
*/
bool move(int tile)

{
   //finding the index of tile...
    int indexrow, indexcol;
    for (int move_row = 0; move_row < d ; move_row++)
   {
         for (int move_col = 0; move_col < d; move_col++)
         if( tile == board[move_row][move_col])
         {
         indexrow = move_row ;
         indexcol = move_col ;
         break;
         }
   }

  //To avoid segmentation fault: if input tile is not in the board.
  if ((indexrow>d) || (indexcol>d))
  return false;

  //SWAPPING...
  if ((board[indexrow +1][indexcol]) == -1)
  {
      int temp = board[indexrow][indexcol];
      board[indexrow][indexcol] = board[indexrow +1][indexcol];
      board[indexrow +1][indexcol] = temp;
      return true;
  }
   else if ((board[indexrow - 1][indexcol]) == -1)
  {
      int temp = board[indexrow][indexcol];
      board[indexrow][indexcol] = board[indexrow -1][indexcol];
      board[indexrow -1][indexcol] = temp;
      return true;
  }
   else if ((board[indexrow ][indexcol + 1]) == -1)
  {
      int temp = board[indexrow][indexcol];
      board[indexrow][indexcol] = board[indexrow][indexcol + 1];
      board[indexrow][indexcol + 1] = temp;
      return true;
  }
   else if ((board[indexrow ][indexcol - 1]) == -1)
  {
      int temp = board[indexrow][indexcol ];
      board[indexrow][indexcol] = board[indexrow ][indexcol - 1];
      board[indexrow][indexcol - 1] = temp;
      return true;
  }
  else
  {
      return false;
  }
}

bool won(void)
{

    for ( int won_row = 0; won_row < d-1; won_row++ )
    {
             for( int won_col = 0; won_col < d-1; won_col++)
        {
            //appropriate conditions to ensure true is returned only if game is won
            if (((board[won_row][won_col + 1]) < (board[won_row][won_col] +1 )) || (board[won_row+1][won_col] != (board[won_row][won_col] + d)) || (board[d-1][d-1] != -1))
            return false;
        }

    }
return true;
}


/**
* Saves the moves in a text file so that you can keep a record of the moves
* you made in the game.
*/
void saves_moves(void)
{
    // log
    const char* log = "moves.txt";
    // delete existing log, if any, before first save
    static bool saved = false;
    if (!saved)
    {
        unlink(log);
        saved = true;
    }
    // open log
    FILE* p = fopen(log,"a");
    if (p == NULL)
    {
        return;
    }
    // log board
    fprintf(p, "{");
    for (int i = 0; i < d; i++)
    {
        fprintf(p, "{");
        for (int j = 0; j < d; j++)
        {
            fprintf(p, "%i", board[i][j]);
            if (j < d - 1)
            {
                fprintf(p, ",");
            }
        }
        fprintf(p, "}");
        if (i < d - 1)
        {
            fprintf(p, ",");
        }
    }
    fprintf(p, "}\n");
    // close log
    fclose(p);
}

/**
* Shuffles the numbers!! so that random numbers are printed on the board.
*/
void Shuffler(int *array1, int n)
 {
    srand(time(0));
  int s,t , temp, upperbound;

  for (s = n - 1; s > 0; s--)
    {
    upperbound = RAND_MAX - ((RAND_MAX % (s + 1)) + 1);
    do
    {
      t = rand() % (s + 1);
    }
    while (t > upperbound);
    temp = array1[t];
    array1[t] = array1[s];
    array1[s] = temp;
  }
}
