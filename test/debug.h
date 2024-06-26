#pragma once

#include <io.h>
#include <fcntl.h>


//---------------------------------------------------------------------------------------
// Some useful positions
//---------------------------------------------------------------------------------------

const char ach_debug_rooks_only[8][8] =
{
   { 'R',  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 'R' },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 'R',  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 'R' },
};

const char ach_debug_bishops_only[8][8] =
{
   { 0x20, 0x20, 'B',  0x20, 0x20, 'B',  0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 'b',  0x20, 0x20, 'b',  0x20, 0x20 },
};

const char ach_debug_queens_only[8][8] =
{
   { 0x20, 0x20, 0x20, 'Q',  0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 'q',  0x20, 0x20, 0x20, 0x20 },
};

const char ach_debug_kings_only[8][8] =
{
   { 0x20, 0x20, 0x20, 0x20, 'K',  0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 'k',  0x20, 0x20, 0x20 },
};

const char ach_debug_check[8][8] =
{
   { 0x20, 0x20, 0x20, 'Q', 'K',   0x20, 0x20, 'R' },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 'q',  'k',  0x20, 0x20, 'R' },
};

const char ach_debug_jeopardy[8][8] =
{
   { 0x20, 0x20, 0x20, 0x20, 'K' , 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 'Q' , 0x20, 0x20, 0x20, 'R' , 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 'B'  },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 'k',  0x20, 0x20, 0x20 },
};

const char ach_debug_checkmate[8][8] =
{
   { 'R',  'N',  'B',  'Q',  'K',  'B',  'N',  'R'  },
   { 'P',  'P',  'P',  'P',  0x20, 0x20, 'P',  'P'  },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20,  'n', 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20,  'r',  'r', 0x20, 0x20 },
   { 'p',  'p',  'p',  'p',  0x20,  'p',  'p',  'p' },
   { 0x20,  'n',  'b',  'q',  'k',  'b', 0x20,  0x20},
};

const char ach_debug_not_checkmate[8][8] =
{
   { 'R',  'N',  'B',  'Q',  'K',  'B',  'N',  'R'  },
   { 'P',  'P',  'P',  'P',  'P',  0x20, 'P',  'P'  },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20,  'n', 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20,  'r', 0x20, 0x20 },
   { 'p',  'p',  'p',  'p',  0x20,  'p',  'p',  'p' },
   { 0x20,  'n',  'b',  'q',  'k',  'b', 0x20,  0x20},
};

// DEBUG
//memcpy(board, ach_debug_rooks_only,  sizeof(char) * 8 * 8);
//memcpy(board, ach_debug_bishops_only, sizeof(char) * 8 * 8);
//memcpy(board, ach_debug_queens_only,  sizeof(char) * 8 * 8);
//memcpy(board, ach_debug_kings_only,   sizeof(char) * 8 * 8);
//memcpy(board, ach_debug_check, sizeof(char) * 8 * 8);



void printEmptyBoard(void)
{
   int CELL = 8;

   for (int i = 0; i < 8; i++)
   {
      // Line starting with WHITE
      if ( i%2 == 0)
      {
         for (int z = 0; z < CELL/2; z++)
         {
            cout << "   ";
            for (int w = 0; w < 4; w++)
            {
               for (int j = 0; j < CELL; j++)
               {
                  cout << char(0xDB);
               }

               for (int j = 0; j < CELL; j++)
               {
                  cout << char(0xFF);
               }
            }
            cout << "\n";
          }
      }
      // Line starting with BLACK
      else
      {
         for (int z = 0; z < CELL/2; z++)
         {
            cout << "   ";
            for (int w = 0; w < 4; w++)
            {
                  for (int j = 0; j < CELL; j++)
                  {
                     cout << char(0xFF);
                  }

                  for (int j = 0; j < CELL; j++)
                  {
                     cout << char(0xDB);
                  }
            }
            cout << "\n";
         }
      }
   }
}

void printChessPiecesUnicode()
{
   _setmode(_fileno(stdout), _O_WTEXT);
   std::wcout << L'\u2654' << ' ' <<  L'\u2655' << ' ' << L'\u2656' << ' ' << L'\u2657' << ' ' << L'\u2658' << ' ' << L'\u2659' << endl;
   std::wcout << L'\u265A' << ' ' <<  L'\u265B' << ' ' << L'\u265C' << ' ' << L'\u265D' << ' ' << L'\u265E' << ' ' << L'\u265F' << endl;
}

#endif
