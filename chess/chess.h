#pragma once
#include <vector>
#include <map>
#include <cstdint>
#include "chesspieceset.h"

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
    static const uint32_t NUM_ROWS = 8;
    static const uint32_t NUM_COLUMNS = 8;
    
    //Stores the current state of the chess board
    ChessPiece* board[NUM_ROWS][NUM_COLUMNS];

    //The player who's turn it is
    Player currentPlayer;
    
    //The current turn number
    int currentTurn;

    //Player sets
		ChessPieceSet chessSet;
    
    //Sets the board state to the initial state
    void initializeBoard();
};

} //namespace board_games


