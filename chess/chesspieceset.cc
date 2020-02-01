#include <cstdint>
#include <iostream>
#include <vector>
#include "chesspieceset.h"

namespace bg{

//ChessPieceSet
ChessPieceSet::ChessPieceSet(){
  //setup black set
  blackSet[0] = ChessPiece({ROOK, BLACK, {0,0}});
  blackSet[1] = ChessPiece({KNIGHT, BLACK, {0,1}});
  blackSet[2] = ChessPiece({BISHOP, BLACK, {0,2}});
  blackSet[3] = ChessPiece({QUEEN, BLACK, {0,3}});
  blackSet[4] = ChessPiece({KING, BLACK, {0,4}});
  blackSet[5] = ChessPiece({BISHOP, BLACK, {0,5}});
  blackSet[6] = ChessPiece({KNIGHT, BLACK, {0,6}});
  blackSet[7] = ChessPiece({ROOK, BLACK, {0,7}});

  for(uint32_t i=8; i<16; i++){
    blackSet[i] = ChessPiece({PAWN, BLACK, {1,i-8}});
  }

  //set up white set
  whiteSet[0] = ChessPiece({ROOK, WHITE, {7,0}});
  whiteSet[1] = ChessPiece({KNIGHT, WHITE, {7,1}});
  whiteSet[2] = ChessPiece({BISHOP, WHITE, {7,2}});
  whiteSet[3] = ChessPiece({QUEEN, WHITE, {7,3}});
  whiteSet[4] = ChessPiece({KING, WHITE, {7,4}});
  whiteSet[5] = ChessPiece({BISHOP, WHITE, {7,5}});
  whiteSet[6] = ChessPiece({KNIGHT, WHITE, {7,6}});
  whiteSet[7] = ChessPiece({ROOK, WHITE, {7,7}});

  for(uint32_t i=8; i<16; i++){
    whiteSet[i] = ChessPiece({PAWN, WHITE, {6,i-8}});
  }
}

ChessPiece* ChessPieceSet::getChessPiece(Player player, uint32_t pieceIndex){
  //returns the player's chess piece at the specified index
  // if (pieceIndex >= 16){
  //   std:: cout << "ERROR: getChessPiece() index too large" << std::endl;
  //   return nullptr;
  // }
  switch(player){
    case BLACK:
      return &blackSet[pieceIndex];
    case WHITE:
      return &whiteSet[pieceIndex];
    default:
      std:: cout << "ERROR: getChessPiece()" << std::endl;
      return nullptr;
  }
}

bool pushFreePiece(ChessPieces* pieces, ChessPiece* piece){
    if(!piece->isCaptured){
        pieces->push_back(piece);
        return true;
    }
    return false;
}

ChessPieces ChessPieceSet::getPieces(Player player){
  //push the player's non capture chess pieces into a vector
  ChessPieces res;
  for(uint32_t i=0; i<16; i++){
    pushFreePiece(&res, this->getChessPiece(player, i));
  }
  return res;
}

ChessPieces ChessPieceSet::getPieces(Player player, ChessPieceType type){
  //push the player's non captured pieces of the specified type into a vector
  ChessPieces res;
  switch(type){
    case PAWN:
      for(uint32_t i=8; i<16; i++){
        pushFreePiece(&res, this->getChessPiece(player, i));
      }
      break;
    case ROOK:
      pushFreePiece(&res, this->getChessPiece(player, 0));
      pushFreePiece(&res, this->getChessPiece(player, 7));
      break;
    case KNIGHT:
      pushFreePiece(&res, this->getChessPiece(player, 1));
      pushFreePiece(&res, this->getChessPiece(player, 6));
      break;
    case BISHOP:
      pushFreePiece(&res, this->getChessPiece(player, 2));
      pushFreePiece(&res, this->getChessPiece(player, 5));
      break;
    case QUEEN:
      pushFreePiece(&res, this->getChessPiece(player, 3));
      break;
    case KING:
      pushFreePiece(&res, this->getChessPiece(player, 4));
      break;
    default:
      std:: cout << "ERROR: getPieces()" << std::endl;
  }
  return res;
}

}//namespace board_games