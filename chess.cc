#include <iostream>
#include <vector>
#include "chess.h"

namespace bg{
//chessboard position
ChessBoardPosition::ChessBoardPosition(ChessPiece p) : empty(false) , piece(p) {}
ChessBoardPosition::ChessBoardPosition() : empty(true), piece({EMPTY, NONE}) {}
ChessBoardPosition::ChessBoardPosition(ChessPieceType pt, Player p) : empty(false), piece({pt, p}) {}

//chess
Chess::Chess() : currentTurn(0), currentPlayer(WHITE){
  initializeBoardState();
}

void Chess::printBoard(){
  std::cout << "Chess board:\n" << std::endl;
  for(int i=0; i<NUM_ROWS; i++){
    for(int j=0; j<NUM_COLUMNS; j++){
      ChessPiece piece = board[i][j].getPiece();
      switch(piece.type){
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
        case EMPTY:
          std::cout << "[";
          break;
        default:
          std:: cout << "ERROR" << std::endl;
          return;
      }
      switch(piece.player){
        case BLACK:
          std::cout << "*";
          break;
        case WHITE:
          std::cout << "`";
          break;
        case NONE:
          std::cout << "]";
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

//private
void Chess::initializeBoardState(){
  std::cout << "Initializing board state" <<std::endl;

  //black pieces
  board[0][0] = ChessBoardPosition(ROOK, BLACK);
  board[0][1] = ChessBoardPosition(KNIGHT, BLACK);
  board[0][2] = ChessBoardPosition(BISHOP, BLACK);
  board[0][3] = ChessBoardPosition(QUEEN, BLACK);
  board[0][4] = ChessBoardPosition(KING, BLACK);
  board[0][5] = ChessBoardPosition(BISHOP, BLACK);
  board[0][6] = ChessBoardPosition(KNIGHT, BLACK);
  board[0][7] = ChessBoardPosition(ROOK, BLACK);

  for(int i=0; i<NUM_ROWS; i++){
    board[1][i] = ChessBoardPosition(PAWN, BLACK);
  }

  //white pieces
  board[7][0] = ChessBoardPosition(ROOK, WHITE);
  board[7][1] = ChessBoardPosition(KNIGHT, WHITE);
  board[7][2] = ChessBoardPosition(BISHOP, WHITE);
  board[7][3] = ChessBoardPosition(QUEEN, WHITE);
  board[7][4] = ChessBoardPosition(KING, WHITE);
  board[7][5] = ChessBoardPosition(BISHOP, WHITE);
  board[7][6] = ChessBoardPosition(KNIGHT, WHITE);
  board[7][7] = ChessBoardPosition(ROOK, WHITE);

  for(int i=0; i<NUM_ROWS; i++){
    board[6][i] = ChessBoardPosition(PAWN, WHITE);
  }

  //empty board squares
  for(int i=2; i<6; i++){
    for(int j=0; j<NUM_ROWS; j++){
      board[i][j] = ChessBoardPosition();
    }
  }
}

} //namespace board_games
