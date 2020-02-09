#include <map>
#include "chesshelper.h"
#include "chessboard.h"

namespace bg {

class ChessMove{
  public:
    ChessMove(ChessPiece* piece, Position to);
    ChessMove(const char* moveString, ChessBoard* chessBoard);

    static bool checkValidMoveString(const char* moveStr);

    //data structures for converting rows <--> ranks and columns <--> files
    const uint32_t rowToRank[8] = {8,7,6,5,4,3,2,1};
    std::map<uint32_t, uint32_t> rankToRow = {{8,0},{7,1},{6,2},{5,3},{4,4},{3,5},{2,6},{1,7}};

    const char colToFile[8] = {'a','b','c','d','e','f','g','h'};
    std::map<char, uint32_t> fileToCol = {{'a',0},{'b',1},{'c',2},{'d',3},{'e',4},{'f',5},{'g',6},{'h',7}};

  private:
    ChessPiece* piece;
    Position to;

    static uint32_t charToInt(char c);
    static bool isValidRank(uint32_t rank);
    static bool isValidFile(char file);

};

}

