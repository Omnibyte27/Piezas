/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
#include <string>

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

TEST(PiezasTest, multiDrop)
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

TEST(PiezasTest, pieceStatus2)
{
  Piezas obj;
  Piece test;
  Piece test2;
  Piece test3;
  obj.dropPiece(1);
  obj.dropPiece(1);
  obj.dropPiece(1);
  test = obj.pieceAt(0,1);
  test2 = obj.pieceAt(1,1);
  test3 = obj.pieceAt(2,1);
  ASSERT_TRUE(test == 'X' && test2 == 'O' && test3 == 'X');
}

TEST(PiezasTest, fullBoard)
{
  Piezas obj;
  Piece test;
  for(int i = 0; i < 3; i++)
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
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 2; j++)
    {
      obj.dropPiece(i);
    }
  }
  test = obj.gameState();
  ASSERT_TRUE(test == ' ');
}

TEST(PiezasTest, XWins)
{
  Piezas obj;
  Piece test;
  /*
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 2; j++)
    {
      obj.dropPiece(i);
    }
  }
  */
  obj.dropPiece(0);
  obj.dropPiece(0);
  obj.dropPiece(0);
  obj.dropPiece(1);
  obj.dropPiece(1);
  obj.dropPiece(1);
  obj.dropPiece(2);
  obj.dropPiece(2);
  obj.dropPiece(2);
  obj.dropPiece(3);
  obj.dropPiece(3);
  obj.dropPiece(3);
  test = obj.gameState();
  ASSERT_TRUE(test == '?');
}

TEST(PiezasTest, OWins)
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
