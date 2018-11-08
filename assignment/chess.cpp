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
   return chess_board[rank -1][file - 97].piece;
 }

 void setup_chess_board(ChessBoard chess_board){

 }

 bool remove_piece(ChessBoard chess_board, File file, Rank rank){
   return false;
 }

 bool squares_share_file(File file, Rank rank, File file1, Rank rank1){
   return false;
 }

 bool squares_share_rank(File file, Rank rank, File file1, Rank rank1){
   return false;
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
