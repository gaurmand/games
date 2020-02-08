#include "chesshelper.h"

namespace bg{

class ChessMove{
  ChessPiece* piece;
	Position to;

  static ChessMove getMoveFromSting(char* moveStr);
};

} //namespace bg