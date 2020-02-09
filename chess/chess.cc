#include <iostream>
#include <vector>
#include "chess.h"

namespace bg{
//Chess
Chess::Chess() : currentTurn(0), currentPlayer(WHITE), chessBoard(&chessSet){}

void Chess::printBoard(){
  std::cout << std::endl << " |a|b|c|d|e|f|g|h|" << std::endl; //print files
  std::cout << "------------------" << std::endl; 

  for(uint32_t i=0; i<ChessBoard::NUM_ROWS; i++){
    std::cout <<  8-i << "|"; //print rank

    for(uint32_t j=0; j<ChessBoard::NUM_COLUMNS; j++){
      ChessPiece* piece = chessBoard.getPiece({i, j});
      if (piece == nullptr){
        std::cout << ".|";
        continue;
      }

      switch(piece->type){
        case PAWN:
          std::cout << (piece->player==BLACK ? "p" : "P");
          break;
        case ROOK:
          std::cout << (piece->player==BLACK ? "r" : "R");
          break;
        case KNIGHT:
          std::cout << (piece->player==BLACK ? "n" : "N");
          break;
        case BISHOP:
          std::cout << (piece->player==BLACK ? "b" : "B");
          break;
        case QUEEN:
          std::cout << (piece->player==BLACK ? "q" : "Q");
          break;
        case KING:
          std::cout << (piece->player==BLACK ? "k" : "K");
          break;
        default:
          std:: cout << "ERROR" << std::endl;
          return;
      }
      std::cout << "|";
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

} //namespace board_games
