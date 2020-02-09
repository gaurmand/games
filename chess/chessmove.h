#include <map>
#include "chesshelper.h"
#include "chessboard.h"

namespace bg {

class ChessMove{
  public:
    //Constructor initializes the ChessMove using the arguments
    //@piece: the piece being moved
    //@to: the position the piece is being moved to
    ChessMove(ChessPiece* piece, Position to);

    //Constructor initializes the ChessMove according to the postion and chesspiece specified in the moveString
    //@moveString: the string to be parsed into positions
    //@chessBoard: the chessboard containing the chess piece to move
    ChessMove(const char* moveString, ChessBoard* chessBoard);

    //Gets the chess move's associated chess piece
    ChessPiece* getPiece();

    //Gets the position the chess piece is being moved to
    Position getTo();

    //Checks if the chess move represents an actual move (not in terms of game rules)
    //Returns true if valid, false if invalid
    bool isValidMove();

    //Checks if a string represents a chess move
    //@moveStr: the string to check
    static bool isChessMoveString(const char* moveStr);

    //converts rows (0-7) to ranks (8-1)
    const uint32_t rowToRank[8] = {8,7,6,5,4,3,2,1};

    //converts ranks (8-1) to rows (0-7)
    std::map<uint32_t, uint32_t> rankToRow = {{8,0},{7,1},{6,2},{5,3},{4,4},{3,5},{2,6},{1,7}};

    //converts columns (0-7) to files (a-h)
    const char colToFile[8] = {'a','b','c','d','e','f','g','h'};

    //converts files (a-h) to columns (0-7)
    std::map<char, uint32_t> fileToCol = {{'a',0},{'b',1},{'c',2},{'d',3},{'e',4},{'f',5},{'g',6},{'h',7}};

  private:
    //The chess piece to move
    ChessPiece* piece;

    //To position to move the piece to
    Position to;

    //Converts a single character to an integer
    //@c: the character to convert
    //Always returns an integer (even if c doesn't represent one)
    static uint32_t charToInt(char c);

    //Checks if an integer is a valid rank (1-8)
    //@rank: the number to check
    //Returns true if valid, false if invalid
    static bool isValidRank(uint32_t rank);

    //Checks if a character is a valid file (a-h)
    //@file: the character to check
    //Returns true if valid, false if invalid
    static bool isValidFile(char file);

};

}

