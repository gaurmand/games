#pragma once
#include <vector>
#include <cstdint>
#include "chesspieceset.h"

namespace bg{

class ChessBoard{
  public:
    //Default constructor initializes an empty board
    ChessBoard();

    //Constructor initializes the board and chessSet to the normal initial chess positions
    //@chessSet: a pointer to chessPieceSet object
    ChessBoard(ChessPieceSet* chessSet);

    //Constructor initializes the board and chessSet using the Positions vectors
    //@chessSet: a pointer to chessPieceSet object
    //@blackPos: vector of 16 positons for the black pieces
    //@whitePos: vector of 16 positons for the white pieces
    ChessBoard(ChessPieceSet* chessSet, Positions* blackPos, Positions* whitePos);

    //Initializes the board and chessSet to the normal initial chess positions
    //@chessSet: a pointer to chessPieceSet object
    //Returns true on success, false on failure
    bool setBoard(ChessPieceSet* chessSet);

    //Initializes the board and chessSet using the Positions vectors
    //@chessSet: a pointer to chessPieceSet object
    //@blackPos: vector of 16 positons for the black pieces
    //@whitePos: vector of 16 positons for the white pieces
    //Returns true on success, false on failure
    bool setBoard(ChessPieceSet* chessSet, Positions* blackPos, Positions* whitePos);

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
    static bool isPositionValid(Position pos);

    //Checks if vector of position on the board is valid
    //@pos: the vector of positions to check
    //Returns true or false
    static bool isPositionsValid(Positions* pos);

    //The number of rows in the chess board
    static const uint32_t NUM_ROWS = 8;

    //The number of columns in the chess board
    static const uint32_t NUM_COLUMNS = 8;

  private:
    //Stores the current state of the chess board
    ChessPiece* board[NUM_ROWS][NUM_COLUMNS];

    //The initial positions for the black chess set
    static Positions initialBlackSetPositions;

    //The initial positions for the white chess set
    static Positions initialWhiteSetPositions;
};

} //namespace bg