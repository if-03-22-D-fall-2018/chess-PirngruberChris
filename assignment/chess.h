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
 #include <stdbool.h>
 #ifndef ___CHESS_H
#define ___CHESS_H

enum Move{NormalMove, CaptureMove};
enum Color {White, Black};
enum PieceType{
  Pawn, Rook, Knight, Bishop, Queen, King, NoPiece
};

struct ChessPiece{
  enum Color color;
  enum PieceType type;
};

struct ChessSquare{
  bool is_occupied;
  struct ChessPiece piece;
};

typedef ChessSquare ChessBoard[8] [8];
typedef int Rank;
typedef int File;
typedef ChessSquare Chessboard[8] [8];

bool is_piece(struct ChessPiece piece, enum Color color, enum PieceType type);

void init_chess_board(ChessBoard chess_board);

struct ChessSquare* get_square(Chessboard chess_board, File file, Rank rank);

bool is_square_occupied(ChessBoard chess_board, File file, Rank rank);

bool add_piece(ChessBoard chess_board, File file, Rank rank, struct ChessPiece piece);

struct ChessPiece get_piece(ChessBoard chess_board, File file, Rank rank);

void setup_chess_board(ChessBoard chess_board);

bool remove_piece(ChessBoard chess_board, File file, Rank rank);

bool squares_share_file(File file, Rank rank, File file1, Rank rank1);

bool squares_share_rank(File file, Rank rank, File file1, Rank rank1);

bool squares_share_diagonal(File file, Rank rank, File file1, Rank rank1);

bool squares_share_kings_move(File file, Rank rank, File file1, Rank rank1);

bool squares_share_pawns_move(enum Color color, enum Move move, File file, Rank rank, File file1, Rank rank1);

bool squares_share_queens_move(File file, Rank rank, File file1, Rank rank1);

bool squares_share_knights_move(File file, Rank rank, File file1, Rank rank1);

#endif
