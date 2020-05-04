/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
#include <iostream>

using namespace std;

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, reset)
{
  Piezas obj;
  Piece test;
  obj.dropPiece(1);
  obj.reset();
  test = obj.pieceAt(0,1);
  ASSERT_TRUE(test == ' ');
}

TEST(PiezasTest, checkDrop)
{
  Piezas obj;
  Piece test;
  Piece test2;
  Piece test3;
  Piece test4;
  test = obj.dropPiece(0);
  test2 = obj.dropPiece(1);
  test3 = obj.dropPiece(2);
  test4 = obj.dropPiece(3);
  ASSERT_TRUE(test == ' ' && test2 == ' ' && test3 == ' ' && test4 == ' ');
}

TEST(PiezasTest, columnFull)
{
  Piezas obj;
  Piece test;
  obj.dropPiece(1);
  obj.dropPiece(1);
  obj.dropPiece(1);
  test = obj.dropPiece(1);
  ASSERT_TRUE(test == '?');
}

TEST(PiezasTest, checkDropBounds)
{
  Piezas obj;
  Piece test;
  test = obj.dropPiece(-1);
  ASSERT_TRUE(test == '?');
}

TEST(PiezasTest, checkDropBounds2)
{
  Piezas obj;
  Piece test;
  test = obj.dropPiece(4);
  ASSERT_TRUE(test == '?');
}

TEST(PiezasTest, pieceStatus)
{
  Piezas obj;
  Piece test;
  obj.dropPiece(1);
  test = obj.pieceAt(0,1);
  ASSERT_TRUE(test == 'X');
}

TEST(PiezasTest, outOfBounds)
{
  Piezas obj;
  Piece test;
  test = obj.pieceAt(5,1);
  ASSERT_TRUE(test == '?');
}

TEST(PiezasTest, properPlacement)
{
  Piezas obj;
  obj.dropPiece(0); //X 1
  obj.dropPiece(0); //O 2
  obj.dropPiece(1); //X 3
  obj.dropPiece(3); //O 4
  obj.dropPiece(2); //X 5
  obj.dropPiece(2); //O 6
  obj.dropPiece(0); //X 7
  obj.dropPiece(3); //O 8
  obj.dropPiece(1); //X 9
  obj.dropPiece(2); //O 10
  obj.dropPiece(3); //X 11
  obj.dropPiece(1); //O 12

// Board state should be
// X O O X
// O X O O
// X X X O
  ASSERT_TRUE(obj.pieceAt(0,0) == 'X' && obj.pieceAt(0,1) == 'X' && obj.pieceAt(0,2) == 'X'
   && obj.pieceAt(0,3) == 'O' && obj.pieceAt(1,0) == 'O' && obj.pieceAt(1,1) == 'X' && obj.pieceAt(1,2) == 'O'
   && obj.pieceAt(1,3) == 'O' && obj.pieceAt(2,0) == 'X' && obj.pieceAt(2,1) == 'O' && obj.pieceAt(2,2) == 'O'
   && obj.pieceAt(2,3) == 'X');
}

TEST(PiezasTest, notfullBoard)
{
  Piezas obj;
  Piece test;
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 2; j++)
    {
      obj.dropPiece(i);
    }
  }
  test = obj.gameState();
  ASSERT_TRUE(test == '?');
}

TEST(PiezasTest, tieGame)
{
  Piezas obj;
  Piece test;
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      obj.dropPiece(i);
    }
  }
  test = obj.gameState();
  ASSERT_TRUE(test == ' ');
}

TEST(PiezasTest, boardFull)
{
  Piezas obj;
  Piece test;
  Piece test1;
  Piece test2;
  Piece test3;

  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      obj.dropPiece(i);
    }
  }
  test = obj.dropPiece(0);
  test1 = obj.dropPiece(1);
  test2 = obj.dropPiece(2);
  test3 = obj.dropPiece(3);
  ASSERT_TRUE(test == '?' && test1 == '?' && test2 == '?' && test3 == '?');
}

TEST(PiezasTest, XWins)
{
  Piezas obj;
  Piece test;
  obj.dropPiece(0); //X 1
  obj.dropPiece(0); //O 2
  obj.dropPiece(1); //X 3
  obj.dropPiece(3); //O 4
  obj.dropPiece(2); //X 5
  obj.dropPiece(2); //O 6
  obj.dropPiece(0); //X 7
  obj.dropPiece(3); //O 8
  obj.dropPiece(1); //X 9
  obj.dropPiece(2); //O 10
  obj.dropPiece(3); //X 11
  obj.dropPiece(1); //O 12

// Board state should be
// X O O X
// O X O O
// X X X O
  test = obj.gameState();
  ASSERT_TRUE(test == ' ');
// ASSERT_TRUE(test == 'O');
// ASSERT_TRUE(test == ' ');
// ASSERT_TRUE(test == '?');
}
