/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.c
 * Author:			P. Bauer
 * Due Date:		November 03, 2010
 * ----------------------------------------------------------
 * Description:
 * Implementation of basic chess functions.
 * ----------------------------------------------------------
 */
 #include "chess.h"
 #include <stdio.h>
 #include <stdbool.h>
 #include "general.h"

 bool is_piece(struct ChessPiece cp, enum Color color, enum PieceType type){
   return cp.color == color && cp.type == type;
}

 void init_chess_board(ChessBoard chess_board){
   for(int i = 0; i < 8; i++){
     for(int j = 0; j < 8; j++){
       chess_board[i][j].is_occupied = false;
       chess_board[i][j].piece.type = NoPiece;
     }
   }
 }

 struct ChessSquare* get_square(Chessboard chess_board, File file, Rank rank){
   if (rank < 1 || rank > 8 || file < 'a' || file > 'h') {
     return 0;
   }
   else{
     return &chess_board[rank - 1][file - 97];
   }
 }

 bool is_square_occupied(ChessBoard chess_board, File file, Rank rank){
   struct ChessSquare* s = get_square(chess_board, file, rank);
   if (s == 0) {
     return true;
   }
   return s->is_occupied;
 }

 bool add_piece(ChessBoard chess_board, File file, Rank rank, struct ChessPiece piece){
   if (is_square_occupied(chess_board, file, rank)) {
     return false;
   }
   chess_board[rank -1][file - 97].is_occupied = true;
   chess_board[rank -1][file - 97].piece = piece;

   return true;
 }

 struct ChessPiece get_piece(ChessBoard chess_board, File file, Rank rank){
   struct ChessSquare* s = get_square(chess_board, file, rank);
   if (s == 0) {
     ChessPiece p = {White, NoPiece};
     return p;
   }
   return s->piece;
 }

 void setup_chess_board(ChessBoard chess_board){
   File file;
   init_chess_board(chess_board);
   for (file = 'a'; file <= 'h'; file++) {
     add_piece(chess_board, file, 2, {White, Pawn});
     add_piece(chess_board, file, 7, {Black, Pawn});
   }
  add_piece(chess_board, 'a', 1, {White, Rook});
 	add_piece(chess_board, 'h', 1, {White, Rook});
 	add_piece(chess_board, 'b', 1, {White, Knight});
 	add_piece(chess_board, 'g', 1, {White, Knight});
 	add_piece(chess_board, 'c', 1, {White, Bishop});
 	add_piece(chess_board, 'f', 1, {White, Bishop});
 	add_piece(chess_board, 'd', 1, {White, Queen});
 	add_piece(chess_board, 'e', 1, {White, King});

  add_piece(chess_board, 'a', 8, {Black, Rook});
 	add_piece(chess_board, 'h', 8, {Black, Rook});
 	add_piece(chess_board, 'b', 8, {Black, Knight});
 	add_piece(chess_board, 'g', 8, {Black, Knight});
 	add_piece(chess_board, 'c', 8, {Black, Bishop});
 	add_piece(chess_board, 'f', 8, {Black, Bishop});
 	add_piece(chess_board, 'd', 8, {Black, Queen});
 	add_piece(chess_board, 'e', 8, {Black, King});
 }

 bool remove_piece(ChessBoard chess_board, File file, Rank rank){
   if (!is_square_occupied(chess_board, file, rank)) {
     return false;
   }
   chess_board[rank -1][file - 97].is_occupied = false;
   return true;
 }

 bool squares_share_file(File file, Rank rank, File file1, Rank rank1){
   if (rank < 1 || rank > 8 || file < 'a' || file > 'h') {
     return false;
   }
   return file == file1;
 }

 bool squares_share_rank(File file, Rank rank, File file1, Rank rank1){
   if (rank < 1 || rank > 8 || file < 'a' || file > 'h') {
     return false;
   }
   return rank == rank1;
 }

 bool squares_share_diagonal(File file, Rank rank, File file1, Rank rank1){
   return false;
 }

 bool squares_share_kings_move(File file, Rank rank, File file1, Rank rank1){
   return false;
 }

 bool squares_share_pawns_move(enum Color color, enum Move NormalMove, File file, Rank rank, File file1, Rank rank1){
   return false;
 }

 bool squares_share_queens_move(File file, Rank rank, File file1, Rank rank1){
   return false;
 }

 bool squares_share_knights_move(File file, Rank rank, File file1, Rank rank1){
   return false;
 }
