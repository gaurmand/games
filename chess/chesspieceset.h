#pragma once
#include <vector>
#include <cstdint>

namespace bg{

enum ChessPieceType {PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING};
enum Player {BLACK, WHITE};

struct Position{
  uint32_t row;
  uint32_t col;
};

struct ChessPiece{
  ChessPieceType type;
  Player player;
	Position pos;
  bool isCaptured = false;
	uint32_t numMoves = 0;
};
typedef std::vector<ChessPiece*> ChessPieces;

class ChessMove{
	ChessPiece* piece;
	Position to;
};

class ChessPieceSet{
	public:
    //default constructor
		ChessPieceSet();

    //Gets the specified chess piece
    //@player: the player's whos chess piece is returned
    //@pieceIndex: the ipiece's index in the player's ChessPiece array
    //Returns the ChessPiece
		ChessPiece* getChessPiece(Player player, uint32_t pieceIndex);

    //Gets the player's chess pieces
    //@player: the player's who's chess pieces are returned
    //Returns a vector of ChessPieces
		ChessPieces getPieces(Player player);

    //Gets the player's chess pieces of the specified type
    //@player: the player's who's chess pieces are returned
    //@type: the type of chess piece to return
    //Returns a vector of ChessPieces
		ChessPieces getPieces(Player player, ChessPieceType type);
  private:
    static const uint32_t NUM_PIECES = 16;

    //Set of BLACK's 16 chess pieces
    ChessPiece blackSet[NUM_PIECES];

    //Set of WHITE's 16 chess pieces
    ChessPiece whiteSet[NUM_PIECES];
};

} //namespace board_games