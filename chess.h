#include <vector>

namespace bg{

enum ChessPieceType {EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING};
enum Player {BLACK, WHITE, NONE};

struct ChessPiece{
  ChessPieceType type;
  Player player;
};

struct Position{
  int x;
  int y;
};

struct ChessMove{
  ChessPiece piece;
  Position from;
  Position to;
};

class ChessBoardPosition{
  public:
    ChessBoardPosition();
    ChessBoardPosition(ChessPiece piece);
    ChessBoardPosition(ChessPieceType pieceType, Player player);
    inline bool isEmpty() {return empty;}
    inline ChessPiece getPiece() {return piece;}
    inline ChessPieceType getPieceType() {return piece.type;}

  private:
    bool empty;
    ChessPiece piece;
};

class Chess{
  public:
    //default constructor
    Chess();

    //Prints a representation of the current board
    void printBoard();

    //Checks if the current state of the board is valid
    //Returns ture if valid, false if invalid
    bool isValidBoard();

    //Checks if the move is valid, makes he move, updates the board state
    //@move: the move to make
    //Returns true on success, false if invalid
    bool makeMove(ChessMove move);

    //Checks if move is valid
    //@move: the move to check if valid
    //Returns true on success, false if invalid
    bool isValidMove(ChessMove move);
    
    //Gets all valid moves the current player can make
    //Returns a vector containing all valid moves the player can make
    std::vector<ChessMove> getMoves();

    //Returns the player whos turn it is next
    Player getNextPlayer();

    //Returns the player whos turn it is
    Player getCurrPlayer();

  private:
    static const int NUM_ROWS = 8;
    static const int NUM_COLUMNS = 8;
    
    //Stores the current state of the chess board
    ChessBoardPosition board[NUM_ROWS][NUM_COLUMNS];

    //The player who's turn it is
    Player currentPlayer;
    
    //The current turn number
    int currentTurn;
    
    //Sets the board state to the initial state
    void initializeBoardState();
};

} //namespace board_games


