#pragma once
#include <vector>
#include <cstdint>

namespace bg{

enum ChessPieceType {PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING, EMPTY};
enum Player {BLACK, WHITE, NONE};

struct Position{
  uint32_t row;
  uint32_t col;
};
typedef std::vector<Position> Positions;

struct ChessPiece{
  ChessPieceType type;
  Player player;
  Position pos;
  bool isCaptured = false;
	uint32_t numMoves = 0;
};
typedef std::vector<ChessPiece*> ChessPieces;

} //namespace bg