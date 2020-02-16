#include <cstdint>
#include <iostream>
#include <vector>
#include "chesspieceset.h"

namespace bg{

//ChessPieceSet
ChessPieceSet::ChessPieceSet(){
  Positions blackPos(16, {9,9});
  Positions whitePos(16, {9,9});
  setPiecePositions(&blackPos, &whitePos);
}

ChessPieceSet::ChessPieceSet(Positions* blackPos, Positions* whitePos){
  setPiecePositions(blackPos, whitePos);
}

bool ChessPieceSet::setPiecePositions(Positions* blackPos, Positions* whitePos){
  setPiecePositions(BLACK, blackPos);
  setPiecePositions(WHITE, whitePos);
}

bool ChessPieceSet::setPiecePositions(Player player, Positions* positions) {
  Positions& pos = *positions;
  if(pos.size() < 16){
    std::cout << "Positions array needs contain at least 16 positions" << std::endl;
    return false;
  }

  ChessPiece* playerSet = getPlayerSet(player);
  playerSet[0] = ChessPiece({ROOK, player, pos[0]});
  playerSet[1] = ChessPiece({KNIGHT, player, pos[1]});
  playerSet[2] = ChessPiece({BISHOP, player, pos[2]});
  playerSet[3] = ChessPiece({QUEEN, player, pos[3]});
  playerSet[4] = ChessPiece({KING, player, pos[4]});
  playerSet[5] = ChessPiece({BISHOP, player, pos[5]});
  playerSet[6] = ChessPiece({KNIGHT, player, pos[6]});
  playerSet[7] = ChessPiece({ROOK, player, pos[7]});

  for(uint32_t i=8; i<16; i++){
    playerSet[i] = ChessPiece({PAWN, player, pos[i]});
  }
}

ChessPiece* ChessPieceSet::getChessPiece(Player player, uint32_t pieceIndex){
  if (pieceIndex >= 16){
    std:: cout << "ERROR: getChessPiece() index too large" << std::endl;
    return nullptr;
  }

  return &getPlayerSet(player)[pieceIndex];
}

bool ChessPieceSet::pushPiece(ChessPieces* pieces, ChessPiece* piece, bool filterCaptured){
    if (!filterCaptured || !piece->isCaptured) {
      pieces->push_back(piece);
      return true;
    }
    return false;
}

ChessPieces ChessPieceSet::getPieces(Player player, bool filterCaptured){
  //push the player's non capture chess pieces into a vector
  ChessPieces res;
  for(uint32_t i=0; i<16; i++){
    pushPiece(&res, getChessPiece(player, i), filterCaptured);
  }
  return res;
}

ChessPieces ChessPieceSet::getPieces(Player player, ChessPieceType type, bool filterCaptured){
  //push the player's non captured pieces of the specified type into a vector
  ChessPieces res;
  switch(type){
    case PAWN:
      for(uint32_t i=8; i<16; i++){
        pushPiece(&res, getChessPiece(player, i), filterCaptured);
      }
      break;
    case ROOK:
      pushPiece(&res, getChessPiece(player, 0), filterCaptured);
      pushPiece(&res, getChessPiece(player, 7), filterCaptured);
      break;
    case KNIGHT:
      pushPiece(&res, getChessPiece(player, 1), filterCaptured);
      pushPiece(&res, getChessPiece(player, 6), filterCaptured);
      break;
    case BISHOP:
      pushPiece(&res, getChessPiece(player, 2), filterCaptured);
      pushPiece(&res, getChessPiece(player, 5), filterCaptured);
      break;
    case QUEEN:
      pushPiece(&res, getChessPiece(player, 3), filterCaptured);
      break;
    case KING:
      pushPiece(&res, getChessPiece(player, 4), filterCaptured);
      break;
    default:
      std:: cout << "ERROR: getPieces()" << std::endl;
  }
  return res;
}

ChessPiece* ChessPieceSet::getPlayerSet(Player player) {
  if (player == BLACK){
    return blackSet;
  } else {
    return whiteSet;
  }
}

}//namespace board_games