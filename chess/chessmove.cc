#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "chessmove.h"

namespace bg {

  ChessMove::ChessMove(ChessPiece* piece, Position to) : piece(piece), to(to) {}

  ChessMove::ChessMove(const char* moveStr, ChessBoard* chessBoard) {
    if (!checkValidMoveString(moveStr)){
      //set empty chessmove
      piece = nullptr;
      to = {8,8};
      return;
    }

    char fromFile = moveStr[0];
    uint32_t fromRank = charToInt(moveStr[1]);
    char toFile = moveStr[3];
    uint32_t toRank = charToInt(moveStr[4]);

    Position from = {rankToRow[fromRank], fileToCol[fromFile]};
    piece =  chessBoard->getPiece(from);
    to = {rankToRow[toRank], fileToCol[toFile]};
  }

  bool ChessMove::checkValidMoveString(const char* moveStr){
    if (strlen(moveStr) != 5){
      std::cout << "Invalid move string (" <<  moveStr << "): wrong length" << std::endl;
      return false;
    } else if(!isalpha(moveStr[0]) || !isdigit(moveStr[1]) || moveStr[2] != ' ' ||!isalpha(moveStr[3]) || !isdigit(moveStr[4])){
      std::cout << "Invalid move string (" <<  moveStr << "): wrong format" << std::endl;
      return false;
    }

    char fromFile = moveStr[0];
    uint32_t fromRank = charToInt(moveStr[1]);
    char toFile = moveStr[3];
    uint32_t toRank = charToInt(moveStr[4]);

    if (!isValidFile(fromFile)){
      std::cout << "Invalid move string (" <<  moveStr << "): file in first position" << std::endl;
      return false;
    } else if (!isValidRank(fromRank) ){
      std::cout << "Invalid move string (" <<  moveStr << "): rank in first position" << std::endl;
      return false;
    } else if (!isValidFile(toFile) ){
      std::cout << "Invalid move string (" <<  moveStr << "): file in second position" << std::endl;
      return false;
    } else if (!isValidRank(toRank) ){
      std::cout << "Invalid move string (" <<  moveStr << "): rank in second position" << std::endl;
      return false;
    }

    return true;
  }

  uint32_t ChessMove::charToInt(char c){
    return int(c) - int('0');
  }

  bool ChessMove::isValidRank(uint32_t rank){
    return (rank >= 1 && rank <= 8);
  }

  bool ChessMove::isValidFile(char file){
    return (file == 'a' || file == 'b' || file == 'c' || file == 'd' || file == 'e' || file == 'f' || file == 'g' || file == 'h');
  }
}