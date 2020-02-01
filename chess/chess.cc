#include <iostream>
#include <vector>
#include "chess.h"

namespace bg{
//Chess
Chess::Chess() : currentTurn(0), currentPlayer(WHITE){
  initializeBoard();
}

void Chess::printBoard(){
  std::cout << "Chess board:\n" << std::endl;
  for(uint32_t i=0; i<NUM_ROWS; i++){
    for(uint32_t j=0; j<NUM_COLUMNS; j++){
      ChessPiece* piece = board[i][j];
      if (piece == nullptr){
        std::cout << "[]";
        continue;
      }

      switch(piece->type){
        case PAWN:
          std::cout << "P";
          break;
        case ROOK:
          std::cout << "R";
          break;
        case KNIGHT:
          std::cout << "K";
          break;
        case BISHOP:
          std::cout << "B";
          break;
        case QUEEN:
          std::cout << "Q";
          break;
        case KING:
          std::cout << "+";
          break;
        default:
          std:: cout << "ERROR" << std::endl;
          return;
      }
      switch(piece->player){
        case BLACK:
          std::cout << "*";
          break;
        case WHITE:
          std::cout << "`";
          break;
        default:
          std:: cout << "ERROR" << std::endl;
          return;
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

bool Chess::isValidBoard(){
  //TODO
  return true;
}

bool Chess::makeMove(ChessMove move){
  //TODO
  return true;
}

bool Chess::isValidMove(ChessMove move){
  //TODO
  return true;
}

std::vector<ChessMove> Chess::getMoves(){
  //TODO
  std::vector<ChessMove> res;
  return res;
}

Player Chess::getNextPlayer(){
  //TODO
  return currentPlayer;
}

Player Chess::getCurrPlayer(){
  //TODO
  return currentPlayer;
}

void Chess::initializeBoard(){
  std::cout << "Initializing board state" <<std::endl;
  for(uint32_t i=0; i<NUM_COLUMNS; i++){
	  board[0][i] = chessSet.getChessPiece(BLACK, i);
    board[1][i] = chessSet.getChessPiece(BLACK, 8+i);
  }

  for(uint32_t i=0; i<NUM_COLUMNS; i++){
	  board[7][i] = chessSet.getChessPiece(WHITE, i);
    board[6][i] = chessSet.getChessPiece(WHITE, 8+i);
  }

  //empty board squares
  for(uint32_t i=2; i<6; i++){
    for(uint32_t j=0; j<NUM_COLUMNS; j++){
      board[i][j] = nullptr;
    }
  }
}

} //namespace board_games
