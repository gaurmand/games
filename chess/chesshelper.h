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

} //namespace bg