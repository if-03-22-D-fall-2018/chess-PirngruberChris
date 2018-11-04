/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.h
 * Author:			P. Bauer
 * Due Date:		October 15, 2014
 * ----------------------------------------------------------
 * Description:
 * Basic chess functions.
 * ----------------------------------------------------------
 */


enum Color { White, Black };
enum PieceType{Pawn, Knight, Rook, Bishop, Queen, King, NoPiece};

struct ChessPiece{
  enum Color color;
  enum PieceType type;
};

 struct ChessSquare{
   bool is_occupied;
   struct ChessPiece piece;
 };

 typedef ChessSquare ChessBoard[8][8];
 typedef char File;
 typedef int Rank;

bool is_piece(struct ChessPiece piece, enum PieceType type, enum Color color);

void init_chess_board(ChessBoard chess_board);

bool is_piece(struct ChessPiece piece, enum Color color, enum PieceType type);

ChessSquare* get_square(ChessBoard chess_board, File file, Rank rank);

bool is_square_occupied(ChessBoard chess_board, File file, Rank rank);

void init_chess_board(ChessBoard chess_board);

bool add_piece(ChessBoard chess_board, File file, Rank rank, struct ChessPiece piece);

ChessPiece get_piece(ChessBoard chess_board, File file, Rank rank);

void setup_chess_board(ChessBoard chess_board);

bool remove_piece(ChessBoard chess_board, File file, Rank rank);

bool squares_share_file(File file, Rank rank, File second_file, Rank second_rank);
