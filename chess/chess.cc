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

std::vector<ChessMove> Chess::getMoves(ChessPiece* piece){
  std::vector<ChessMove> res;
  switch (piece->type) {
    case PAWN:
      res = getPawnMoves(piece);
      break;
    case KNIGHT:
      res = getKnightMoves(piece);
      break;
    case BISHOP:
      res = getBishopMoves(piece);
      break;
    case ROOK:
      res = getRookMoves(piece);
      break;
    case QUEEN:
      res = getQueenMoves(piece);
      break;
    case KING:
      res = getKingMoves(piece);
      break;
  }
  return res;
}

bool Chess::pushValidMove(std::vector<ChessMove>* chessMoves, ChessPiece* piece, Position pos, bool onlyCaptures = false){
  if (!chessBoard.isPositionValid(pos)){
    return false;
  }

  ChessPiece* toPiece = chessBoard.getPiece(pos);
  ChessMove move(piece, toPiece->pos);

  if (toPiece == nullptr && !onlyCaptures){
    chessMoves->push_back(move);
    return true; 
  } else if(toPiece != nullptr && piece->player != toPiece->player){
    chessMoves->push_back(move);
    return true;
  } else{
    return false;
  }
}

bool Chess::pushMove(std::vector<ChessMove>* chessMoves, ChessPiece* piece, Position to){
    ChessPiece* toPiece = chessBoard.getPiece(to);
    ChessMove move(piece, to);

    if (toPiece == nullptr){
      chessMoves->push_back(move);
      return true;
    } else if(piece->player != toPiece->player){
      chessMoves->push_back(move);
    } 
    return false;
}

bool Chess::pushMovesStraights(std::vector<ChessMove>* chessMoves, ChessPiece* piece){
  Position pos = piece->pos;

  //check bottom
  for (uint32_t i=pos.row; i<ChessBoard::NUM_ROWS; i++){    
    if (!pushMove(chessMoves, piece, {i, pos.col})){
      break;
    }
  }

  //check top
  for (uint32_t i=pos.row; i>=0; i--){                      
    if (!pushMove(chessMoves, piece, {i, pos.col})){
      break;
    }
  }

  //check right
  for (uint32_t j=pos.col; j<ChessBoard::NUM_ROWS; j++){    
    if (!pushMove(chessMoves, piece, {pos.row, j})){
      break;
    }
  }

  //check left
  for (uint32_t j=pos.col; j>=0; j--){                      
    if (!pushMove(chessMoves, piece, {pos.row, j})){
      break;
    }
  }
}

bool Chess::pushMovesDiagonals(std::vector<ChessMove>* chessMoves, ChessPiece* piece){
  Position pos = piece->pos;

  //check bottom right diagonal
  for (uint32_t i=pos.row, j=pos.col; i<ChessBoard::NUM_ROWS && j<ChessBoard::NUM_COLUMNS; i++,j++ ){
    if (!pushMove(chessMoves, piece, {i, j})){
      break;
    }
  }

  //check top right diagonal
  for (uint32_t i=pos.row, j=pos.col; i<ChessBoard::NUM_ROWS && j<ChessBoard::NUM_COLUMNS; i--,j++ ){
    if (!pushMove(chessMoves, piece, {i, j})){
      break;
    }
  }

  //check top left diagonal
  for (uint32_t i=pos.row, j=pos.col; i<ChessBoard::NUM_ROWS && j<ChessBoard::NUM_COLUMNS; i--,j-- ){
    if (!pushMove(chessMoves, piece, {i, j})){
      break;
    }
  }

  //check bottom left diagonal
  for (uint32_t i=pos.row, j=pos.col; i<ChessBoard::NUM_ROWS && j<ChessBoard::NUM_COLUMNS; i++,j++ ){
    if (!pushMove(chessMoves, piece, {i, j})){
      break;
    }
  }
}

std::vector<ChessMove> Chess::getPawnMoves(ChessPiece* piece){
  if (piece->type != PAWN){
    std::cout << "getPawnMoves() call with non pawn piece" << std::endl;
  }
  Position pos = piece->pos;
  std::vector<ChessMove> res;

  if (piece->player == BLACK){
    pushValidMove(&res, piece, {pos.row+1, pos.col});          //check below
    pushValidMove(&res, piece, {pos.row+1, pos.col-1}, true);  //check below left
    pushValidMove(&res, piece, {pos.row+1, pos.col+1}, true);  //check below right
  } else {
    pushValidMove(&res, piece, {pos.row-1, pos.col});          //check above
    pushValidMove(&res, piece, {pos.row-1, pos.col-1}, true);  //check above left
    pushValidMove(&res, piece, {pos.row-1, pos.col+1}, true);  //check above right
  }

  return res;
}

std::vector<ChessMove> Chess::getKnightMoves(ChessPiece* piece){
  if (piece->type != KNIGHT){
    std::cout << "getKnightMoves() call with non knight piece" << std::endl;
  }
  Position pos = piece->pos;
  std::vector<ChessMove> res;

  pushValidMove(&res, piece, {pos.row-2, pos.col+1});  //check hook up right
  pushValidMove(&res, piece, {pos.row-2, pos.col-1});  //check hook up left
  pushValidMove(&res, piece, {pos.row+2, pos.col+1});  //check hook down right
  pushValidMove(&res, piece, {pos.row+2, pos.col-1});  //check hook down left

  pushValidMove(&res, piece, {pos.row-1, pos.col+2});  //check hook right up
  pushValidMove(&res, piece, {pos.row-1, pos.col-2});  //check hook left up
  pushValidMove(&res, piece, {pos.row+1, pos.col+2});  //check hook right down
  pushValidMove(&res, piece, {pos.row+1, pos.col-2});  //check hook left down

  return res;
}

std::vector<ChessMove> Chess::getBishopMoves(ChessPiece* piece){
  if (piece->type != BISHOP){
    std::cout << "getBishopMoves() call with non bishop piece" << std::endl;
  }
  Position pos = piece->pos;
  std::vector<ChessMove> res;

  pushMovesDiagonals(&res, piece);

  return res;
}


std::vector<ChessMove> Chess::getRookMoves(ChessPiece* piece){
  if (piece->type != ROOK){
    std::cout << "getRookMoves() call with non rook piece" << std::endl;
  }
  Position pos = piece->pos;
  std::vector<ChessMove> res;

  pushMovesStraights(&res, piece);

  return res;
}

std::vector<ChessMove> Chess::getQueenMoves(ChessPiece* piece){
  if (piece->type != QUEEN){
    std::cout << "getQueenMoves() call with non queen piece" << std::endl;
  }
  Position pos = piece->pos;
  std::vector<ChessMove> res;

  pushMovesDiagonals(&res, piece);
  pushMovesStraights(&res, piece);

  return res;
}

std::vector<ChessMove> Chess::getKingMoves(ChessPiece* piece){
  if (piece->type != KING){
    std::cout << "getKingMoves() call with non king piece" << std::endl;
  }
  Position pos = piece->pos;
  std::vector<ChessMove> res;

  pushMove(&res, piece, {pos.row-1, pos.col});    //check top
  pushMove(&res, piece, {pos.row-1, pos.col+1});  //check top right
  pushMove(&res, piece, {pos.row, pos.col+1});    //check right
  pushMove(&res, piece, {pos.row+1, pos.col+1});  //check bottom right
  pushMove(&res, piece, {pos.row+1, pos.col});    //check bottom
  pushMove(&res, piece, {pos.row+1, pos.col-1});  //check bottom left
  pushMove(&res, piece, {pos.row, pos.col-1});    //check left
  pushMove(&res, piece, {pos.row-1, pos.col-1});  //check top left

  return res;
}

} //namespace board_games
