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

TEST(PiezasTest, checkDrop)
{
  Piezas obj;
  Piece test;
  test = obj.dropPiece(0);
  ASSERT_TRUE(test == ' ');
}

TEST(PiezasTest, checkDrop2)
{
  Piezas obj;
  Piece test;
  test = obj.dropPiece(1);
  ASSERT_TRUE(test == ' ');
}

TEST(PiezasTest, checkDrop3)
{
  Piezas obj;
  Piece test;
  test = obj.dropPiece(2);
  ASSERT_TRUE(test == ' ');
}

TEST(PiezasTest, checkDrop4)
{
  Piezas obj;
  Piece test;
  test = obj.dropPiece(3);
  ASSERT_TRUE(test == ' ');
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
