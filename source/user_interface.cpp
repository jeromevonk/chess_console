#include "includes.h"
#include "user_interface.h"

// Save the next message to be displayed (regardind last command)
string next_message;

//---------------------------------------------------------------------------------------
// User interface
// All the functions regarding the user interface are in this section
// Logo, Menu, Board, messages to the user
//---------------------------------------------------------------------------------------
void createNextMessage( string msg )
{
   next_message = msg;
}

void appendToNextMessage( string msg )
{
   next_message += msg;
}
void clearScreen(void)
{
   system("cls");
}

void printLogo(void)
{
   cout << "    ======================================\n";
   cout << "       _____ _    _ ______  _____ _____\n";
   cout << "      / ____| |  | |  ____|/ ____/ ____|\n";
   cout << "     | |    | |__| | |__  | (___| (___ \n";
   cout << "     | |    |  __  |  __|  \\___ \\\\___ \\ \n";
   cout << "     | |____| |  | | |____ ____) |___) |\n";
   cout << "      \\_____|_|  |_|______|_____/_____/\n\n";
   cout << "    ======================================\n\n";
}

void printMenu(void)
{
   cout << "Commands: (N)ew game\t(M)ove \t(U)ndo \t(S)ave \t(L)oad \t(Q)uit \n";
}

void printMessage(void)
{
   cout << next_message << endl;

   next_message = "";
}

void printLine(int iLine, int iColor1, int iColor2, Game& game)
{
   // Example (for CELL = 6):

   //  [6-char]
   //  |______| subline 1
   //  |___Q__| subline 2
   //  |______| subline 3

   // Define the CELL variable here. 
   // It represents how many horizontal characters will form one square
   // The number of vertical characters will be CELL/2
   // You can change it to alter the size of the board (an odd number will make the squares look rectangular)
   int CELL = 6;

   // Since the width of the characters BLACK and WHITE is half of the height,
   // we need to use two characters in a row.
   // So if we have CELL characters, we must have CELL/2 sublines
   for (int subLine = 0; subLine < CELL/2; subLine++)
   {
      // A sub-line is consisted of 8 cells, but we can group it
      // in 4 iPairs of black&white
      for (int iPair = 0; iPair < 4; iPair++)
      {
         // First cell of the pair
         for (int subColumn = 0; subColumn < CELL; subColumn++)
         {
            // The piece should be in the "middle" of the cell
            // For 3 sub-lines, in sub-line 1
            // For 6 sub-columns, sub-column 3
            if ( subLine == 1 && subColumn == 3)
            {
               cout << char(game.getPieceAtPosition(iLine, iPair*2) != 0x20 ? game.getPieceAtPosition(iLine, iPair*2) : iColor1);
            }
            else
            {
               cout << char(iColor1);
            }
         }

         // Second cell of the pair
         for (int subColumn = 0; subColumn < CELL; subColumn++)
         {
            // The piece should be in the "middle" of the cell
            // For 3 sub-lines, in sub-line 1
            // For 6 sub-columns, sub-column 3
            if ( subLine == 1 && subColumn == 3)
            {
               cout << char(game.getPieceAtPosition(iLine,iPair*2+1) != 0x20 ? game.getPieceAtPosition(iLine,iPair*2+1) : iColor2);
            }
            else
            {
               cout << char(iColor2);
            }
         }
      }

      // Write the number of the line on the right
      if ( 1 == subLine )
      {
         cout << "   " << iLine+1;
      }

      cout << "\n";

   }
}

void printSituation(Game& game)
{
   // Last moves - print only if at least one move has been made
   if ( 0 != game.rounds.size() )
   {
      cout << "Last moves:\n";

      int iMoves = game.rounds.size();
      int iToShow = iMoves >= 5 ? 5 : iMoves;

      string space = "";

      while( iToShow-- )
      {
         if ( iMoves < 10 )
         {
            // Add an extra hardspace to allign the numbers that are smaller than 10
            space = " ";
         }

         cout << space << iMoves << " ..... " <<  game.rounds[iMoves-1].white_move.c_str() << " | " << game.rounds[iMoves - 1].black_move.c_str() << "\n";
         iMoves--;
      }

      cout << "\n";
   }

   // Captured pieces - print only if at least one piece has been captured
   if ( 0 != game.white_captured.size() || 0 != game.black_captured.size() )
   {
      cout << "---------------------------------------------\n";
      cout << "WHITE captured: ";
      for (unsigned i = 0; i < game.white_captured.size(); i++)
      {
         cout << char(game.white_captured[i]) << " ";
      }
      cout << "\n";

      cout << "black captured: ";
      for (unsigned i = 0; i < game.black_captured.size(); i++)
      {
         cout << char(game.black_captured[i]) << " ";
      }
      cout << "\n";

      cout << "---------------------------------------------\n";
   }

   // Current turn
   cout << "Current turn: " << (game.getCurrentTurn() == Chess::WHITE_PIECE ? "WHITE (upper case)" : "BLACK (lower case)") << "\n\n";

}

void printBoard(Game& game)
{
   cout << "   A     B     C     D     E     F     G     H\n\n";

   for (int iLine = 7; iLine >= 0; iLine--)
   {
      if ( iLine%2 == 0)
      {
         // Line starting with BLACK
         printLine(iLine, BLACK_SQUARE, WHITE_SQUARE, game);
      }

      else
      {
         // Line starting with WHITE
         printLine(iLine, WHITE_SQUARE, BLACK_SQUARE, game);
      }
   }
}