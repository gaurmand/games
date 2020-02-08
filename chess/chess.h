#pragma once
#include <vector>
#include <map>
#include <cstdint>
#include "chesspieceset.h"
#include "chessboard.h"

namespace bg{

class Chess{
  public:
    //default constructor
    Chess();

    //Prints a representation of the current board
    void printBoard();

    //Checks if the current state of the board is valid
    //Returns ture if valid, false if invalid
    bool isValidBoard();

    //Checks if the move is valid, makes he move, updates the board state
    //@move: the move to make
    //Returns true on success, false if invalid
    bool makeMove(ChessMove move);

    //Checks if move is valid
    //@move: the move to check if valid
    //Returns true on success, false if invalid
    bool isValidMove(ChessMove move);
    
    //Gets all valid moves the current player can make
    //Returns a vector containing all valid moves the player can make
    std::vector<ChessMove> getMoves();

    //Returns the player whos turn it is next
    Player getNextPlayer();

    //Returns the player whos turn it is
    Player getCurrPlayer();

  private:
    //The player who's turn it is
    Player currentPlayer;
    
    //The current turn number
    int currentTurn;

    //Stores each player's chess pieces
		ChessPieceSet chessSet;

    //Represents the chessboard
		ChessBoard chessBoard;
};

} //namespace board_games


