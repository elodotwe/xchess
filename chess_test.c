#include "chess.h"
#include <assert.h>

void test_initialize();

void main() {
	test_initialize();
}

// When I set up a new board:
//  all pieces should be in the correct positions
//  it should be white's turn
//  game state should be normal
void test_initialize() {
	chesscontext_t context;
	// TODO: deliberately fill with garbage to highlight initialization issues
	chess_initialize(&context);

	assert(context.turn == CHESS_PLAYER_WHITE);
	assert(context.game_state == CHESS_STATE_NORMAL);

	// TODO: I'm pretty sure it's valid to set white up on either side of the board?
	// Assuming white is on row 0 for this.
	piece_t row0[] = {CHESS_PIECE_ROOK, CHESS_PIECE_BISHOP, CHESS_PIECE_KNIGHT,
		CHESS_PIECE_QUEEN, CHESS_PIECE_KING,
		CHESS_PIECE_KNIGHT, CHESS_PIECE_BISHOP, CHESS_PIECE_ROOK };

	for (int x = 0; x < 8; x++) {
		assert(context.cell_type[x][0] == row0[x]);
	}

	piece_t pawn_row[8] = {CHESS_PIECE_PAWN};
	for (int x = 0; x < 8; x++) {
		assert(context.cell_type[x][1] == pawn_row[x]);
		assert(context.cell_type[x][6] == pawn_row[x]);
	}

	piece_t row7[] = {CHESS_PIECE_ROOK, CHESS_PIECE_BISHOP, CHESS_PIECE_KNIGHT,
		CHESS_PIECE_KING, CHESS_PIECE_QUEEN,
		CHESS_PIECE_KNIGHT, CHESS_PIECE_BISHOP, CHESS_PIECE_ROOK};

	for (int x = 0; x < 8; x++) {
		assert(context.cell_type[x][7] == row7[x]);
	}
}
