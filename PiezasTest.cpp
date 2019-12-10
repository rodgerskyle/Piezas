/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
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

TEST(PiezasTest, resetTest) {
	Piezas Game;
	Game.dropPiece(2);
	Game.reset();
	ASSERT_EQ(Game.pieceAt(0,2), Blank);
}

TEST(PiezasTest, dropPieceBounds) {
	Piezas Game;
	ASSERT_EQ(Game.dropPiece(5), Invalid);
}

TEST(PiezasTest, dropPieceTurnLogic) {
	Piezas Game;
	Game.dropPiece(2);
	Game.dropPiece(2);
	ASSERT_EQ(Game.dropPiece(2), X);
}

TEST(PiezasTest, dropPieceOverflow) {
	Piezas Game;
	Game.dropPiece(2);
	Game.dropPiece(2);
	Game.dropPiece(2);
	ASSERT_EQ(Game.dropPiece(2), Blank);
}

TEST(PiezasTest, pieceAtBounds) {
	Piezas Game;
	ASSERT_EQ(Game.pieceAt(0,5), Invalid);
}

TEST(PiezasTest, pieceAtTile) {
	Piezas Game;
	Game.dropPiece(2);
	ASSERT_EQ(Game.pieceAt(0,2), X);
}

TEST(PiezasTest, pieceAtBlank) {
	Piezas Game;
	ASSERT_EQ(Game.pieceAt(0,2), Blank);
}

TEST(PiezasTest, gameStateNotDone) {
	Piezas Game;
	Game.dropPiece(0); //X
	Game.dropPiece(1); //O
	ASSERT_EQ(Game.gameState(), Invalid);
}

TEST(PiezasTest, gameStateXWin) {
	Piezas Game;
	Game.dropPiece(0); //X
	Game.dropPiece(1); //O
	Game.dropPiece(0); //X
	Game.dropPiece(2); //O
	Game.dropPiece(0); //X
	Game.dropPiece(1); //O
	Game.dropPiece(3); //X
	Game.dropPiece(1); //O
	Game.dropPiece(3); //X
	Game.dropPiece(2); //O
	Game.dropPiece(1); //X
	Game.dropPiece(3); //O
	ASSERT_EQ(Game.gameState(), X);
}

TEST(PiezasTest, gameStateOWin) {
	Piezas Game;
	Game.dropPiece(1); //X
	Game.dropPiece(0); //O
	Game.dropPiece(2); //X
	Game.dropPiece(0); //O
	Game.dropPiece(3); //X
	Game.dropPiece(0); //O
	Game.dropPiece(1); //X
	Game.dropPiece(1); //O
	Game.dropPiece(3); //X
	Game.dropPiece(2); //O
	Game.dropPiece(2); //X
	Game.dropPiece(3); //O
	ASSERT_EQ(Game.gameState(), O);
}

TEST(PiezasTest, gameStateTie) {
	Piezas Game;
	Game.dropPiece(1); //X
	Game.dropPiece(0); //O
	Game.dropPiece(0); //X
	Game.dropPiece(0); //O
	Game.dropPiece(3); //X
	Game.dropPiece(1); //O
	Game.dropPiece(1); //X
	Game.dropPiece(2); //O
	Game.dropPiece(2); //X
	Game.dropPiece(2); //O
	Game.dropPiece(2); //X
	Game.dropPiece(3); //O
	Game.dropPiece(3); //X
	ASSERT_EQ(Game.gameState(), Blank);
}