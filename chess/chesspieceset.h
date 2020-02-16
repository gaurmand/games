#pragma once
#include <vector>
#include <cstdint>
#include "chesshelper.h"

namespace bg{

class ChessPieceSet{
  public:
    //default constructor that places each chess piece at the normal starting positions
    ChessPieceSet();

    //constructor that places each chess piece at the positons specified in the arguments
    //@blackPos: vector of 16 positons used to initialize the blackSet
    //@whitePos: vector of 16 positons used to initialize the whiteSet
    ChessPieceSet(Positions* blackPos, Positions* whitePos);

    //Sets the positions of a player set according to the postions argument
    //@blackPos: vector of 16 positons used to initialize the blackSet
    //@whitePos: vector of 16 positons used to initialize the whiteSet
    bool setPiecePositions(Positions* blackPos, Positions* whitePos);

    //Gets a specific chess piece
    //@player: the player whose chess piece is returned
    //@pieceIndex: the piece's index in the player's ChessPiece array
		ChessPiece* getChessPiece(Player player, uint32_t pieceIndex);

    //Gets a player's chess pieces
    //@player: the player whose chess pieces are returned
    //@filterCaptured: only return free pieces if set to true, otherwise returns all pieces
		ChessPieces getPieces(Player player, bool filterCaptured = true);

    //Gets a player's chess pieces of a specific type
    //@player: the player whose chess pieces are returned
    //@type: the type of chess piece to return
    //@filterCaptured: only return free pieces if set to true, otherwise returns all pieces
		ChessPieces getPieces(Player player, ChessPieceType type, bool filterCaptured = true);

  private:
    //Sets the positions of a player set according to the postions argument
    //@player: the player whose pieces' positions are to be set
    //@positions: vector of 16 positons
    bool setPiecePositions(Player player, Positions* positions);

    //Returns a player's chessPiece array
    //@player: the player whose chessPiece array is to be returned
    ChessPiece* getPlayerSet(Player player);

    //Pushes a ChessPiece into a ChessPiece vector if it meets the specified condition
    //@pieces: a vector of ChessPieces
    //@piece: the chess piece that is to be pushed to the vector
    //@filterCaptured: only pushes free pieces if set to true, otherwise always pushes the piece
    static bool pushPiece(ChessPieces* pieces, ChessPiece* piece, bool filterCaptured);

  private:
    //Number of pieces in a proper chess set
    static const uint32_t NUM_PIECES = 16;

    //Set of BLACK's 16 chess pieces
    ChessPiece blackSet[NUM_PIECES];

    //Set of WHITE's 16 chess pieces
    ChessPiece whiteSet[NUM_PIECES];
};

} //namespace bg