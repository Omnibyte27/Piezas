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

TEST(PiezasTest, checkInitial)
{
  Piezas obj;
  char test = (obj.dropPiece(1))Enums.DivisonStatus.Active;
//  string test = obj.dropPiece(1).ToString();
  ASSERT_TRUE(test == ' ');
}
