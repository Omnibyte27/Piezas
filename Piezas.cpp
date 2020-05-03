#include "Piezas.h"
#include <vector>
#include <iostream>
using namespace std;
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
  turn = X;
  board = {{Blank, Blank, Blank, Blank}, {Blank, Blank, Blank, Blank},{Blank, Blank, Blank, Blank}};
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
  board = {{Blank, Blank, Blank, Blank}, {Blank, Blank, Blank, Blank},{Blank, Blank, Blank, Blank}};
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/
Piece Piezas::dropPiece(int column)
{
  if(column > 3 || column < 0)
  {
    return Invalid; //Out of bounds, invalid input
  }
  for(int i = 0; i < 3; i++)
  {
    if(board[i][column] == Blank)
    {
      board[i][column] = turn;
      if(turn == X)
        turn = O;
      else
        turn = X;
      return Blank; //Open spot found
    }

  }
    return Invalid; //No spot found, column full
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
  if(row < 0 || row > 2 || column > 3 || column < 0)
    return Invalid; //Out of bounds
  else if(board[row][column] == Blank)
    return Blank;
  else if(board[row][column] == X)
    return X;
  else
    return O;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
  //Probably a better way to do this but I could not find a cleaner way to handle all the edgecases
  int playerX = 0;
  int playerO = 0;
  int maxCountR = 0;
  int maxCountC = 0;

  //Check if board is full
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      maxCountR = 0;
      maxCountC = 0;
      if(board[i][j] == Blank)
      {
        cout << "Spot missing: " << i << "," << j << endl;
        return Invalid;//Blank spot found, game isnt over
      }
      else if(board[i][j] == X || board[i][j] == O)
      {
/////////////////////////////////////////////////////////////////////////////
        if(i == 0)
        {
          //Case for {0,0} checked
          if(j == 0)
          {
            for(int k = 0; k < 3; k++)
            {
              if(board[k][j] != board[i][j])
                break;
              maxCountC++;
            }
            for(int l = 0; l < 4; l++)
            {
              if(board[i][l] != board[i][j])
                break;
              maxCountR++;
            }
          }
          //Case for {0,1},{0,2} checked
          else if(j == 1 || j == 2)
          {
            maxCountC++; //add one for the initial spot
            if(board[i+1][j] == board[i][j])
              maxCountC++;
              if(board[i+2][j] == board[i][j])
                maxCountC++;
            //{0,1}
            if(j == 1)
            {
              maxCountR++;
              if(board[i][j-1] == board[i][j])
                maxCountR++;
              if(board[i][j+1] == board[i][j])
                maxCountR++;
                if(board[i][j+2] == board[i][j])
                  maxCountR++;
            }
            //{0,2}
            else if(j == 2)
            {
              maxCountR++;
              if(board[i][j+1] == board[i][j])
                maxCountR++;
              if(board[i][j-1] == board[i][j])
                maxCountR++;
                if(board[i][j-2] == board[i][j])
                  maxCountR++;
            }
          }
          //Case for {0,3}
          else if(j == 3)
          {
            for(int k = 0; k < 3; k++)
            {
              if(board[k][j] != board[i][j])
                break;
              maxCountC++;
            }
            for(int l = 0; l < 4; l++)
            {
              if(board[i][3-l] != board[i][j])
                break;
              maxCountR++;
            }
          }
        }
/////////////////////////////////////////////////////////////////////////////
        else if(i == 1)
        {
          maxCountC++;
          maxCountR++;
          if(board[i+1][j] == board[i][j])
            maxCountC++;
          if(board[i-1][j] == board[i][j])
            maxCountC++;
          if(j == 0)
          {
            for(int l = 0; l < 3; l++)
            {
              if(board[i][l] != board[i][j])
                break;
              maxCountR++;
            }
          }
          else if(j == 1 || j == 2)
          {
            if(j == 1)
            {
              if(board[i][j-1] == board[i][j])
                maxCountR++;
              if(board[i][j+1] == board[i][j])
                maxCountR++;
                if(board[i][j+2] == board[i][j])
                  maxCountR++;
            }
            //{0,2}
            else if(j == 2)
            {
              if(board[i][j+1] == board[i][j])
                maxCountR++;
              if(board[i][j-1] == board[i][j])
                maxCountR++;
                if(board[i][j-2] == board[i][j])
                  maxCountR++;
            }
          }
          else if(j == 3)
          {
            for(int l = 3; l > -1; l--)
            {
              if(board[i][l] != board[i][j])
                break;
              maxCountR++;
            }
          }
        }
/////////////////////////////////////////////////////////////////////////////
        else if(i == 2)
        {
          //Case for {2,0}
          if(j == 0)
          {
            for(int k = 0; k < 3; k++)
            {
              if(board[2-k][j] != board[i][j])
                break;
              maxCountC++;
            }
            for(int l = 0; l < 4; l++)
            {
              if(board[i][l] != board[i][j])
                break;
              maxCountR++;
            }
          }
          //Case for {2,1},{2,2}
          else if(j == 1 || j == 2)
          {
            maxCountC++; //add one for the initial spot
            maxCountR++;
            if(board[i-1][j] == board[i][j])
              maxCountC++;
              if(board[i-2][j] == board[i][j])
                maxCountC++;
            //{2,1}
            if(j == 1)
            {
              if(board[i][j-1] == board[i][j])
                maxCountR++;
              if(board[i][j+1] == board[i][j])
                maxCountR++;
                if(board[i][j+2] == board[i][j])
                  maxCountR++;
            }
            //{2,2}
            else if(j == 2)
            {
              if(board[i][j+1] == board[i][j])
                maxCountR++;
              if(board[i][j-1] == board[i][j])
                maxCountR++;
                if(board[i][j-2] == board[i][j])
                  maxCountR++;
            }
          }
          //Case for {2,3}
          else if(j == 3)
          {
            for(int k = 0; k < 3; k++)
            {
              if(board[2-k][j] != board[i][j])
                break;
              maxCountC++;
            }
            for(int l = 3; l > -1; l--)
            {
              if(board[i][l] != board[i][j])
                break;
              maxCountR++;
            }
          }

        }
      }
/////////////////////////////////////////////////////////////////////////////
      //Adjusts biggest X score
      if(board[i][j] == X)
      {
        if(maxCountR > playerX)
          playerX = maxCountR;
        if(maxCountC > playerX)
          playerX = maxCountC;
      }
      //Adjusts biggest O score
      else if(board[i][j] == O)
      {
        if(maxCountR > playerO)
          playerO = maxCountR;
        if(maxCountC > playerO)
          playerO = maxCountC;
      }
    }
  }
  cout << "Player O score is : " << playerO << endl;
  cout << "Player X score is : " << playerX << endl;

  //PlayerO has the most points they win
  if(playerO > playerX)
    return O;
  //PlayerX has the most points they win
  else if(playerX > playerO)
    return X;
  //Tie Game
  return Blank;
}
