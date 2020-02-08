#pragma once
#include <vector>
#include <cstdint>
#include "chesspieceset.h"

namespace bg{

class ChessBoard{
  public:
    //Deleted default constructor
    ChessBoard() = delete;

    //Constructor initializes the board using the chesspieces in chessSet
    //@chessSet: a pointer to cHessSet object
    ChessBoard(ChessPieceSet* chessSet);

    //Gets the ChessPiece at the specified position
    //@pos: the board position to check for a chessPiece
    //Returns a pointer to the ChessPiece, or nullptr if empty
    ChessPiece* getPiece(Position pos);

    //Moves the specified piece to the specified position
    //@piece: a pointer to the ChessPiece to be moved
    //@to: a positon to move the ChessPiece to
    //Returns true on success, false on failure
    bool movePiece(ChessPiece* piece, Position to);

    //Checks if a ChessPiece is at its position on the board
    //@piece: a pointer to the ChessPiece to be checked
    //Returns true or false
    bool isPieceAtPosition(ChessPiece* piece);

    //Checks if a position on the board has no pieces on it
    //@pos: the positon to check
    //Returns true or false
    bool isPositionEmpty(Position pos);

    //Checks if a position on the board is valid
    //@pos: the positon to check
    //Returns true or false
    bool isPositionValid(Position pos);

    static const uint32_t NUM_ROWS = 8;
    static const uint32_t NUM_COLUMNS = 8;

  private:
    //Stores the current state of the chess board
    ChessPiece* board[NUM_ROWS][NUM_COLUMNS];
};

} //namespace bg