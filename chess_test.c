#include "chess.h"
#include <assert.h>
#include <stdio.h>

void test_initialize();

int main() {
	test_initialize();
	printf("All tests \e[30;42mPASS\e[m\n");
	return 0;
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
		assert(context.cell_owner[x][0] == CHESS_PLAYER_WHITE);
	}

	for (int x = 0; x < 8; x++) {
		assert(context.cell_type[x][1] == CHESS_PIECE_PAWN);
		assert(context.cell_type[x][6] == CHESS_PIECE_PAWN);
		assert(context.cell_owner[x][1] == CHESS_PLAYER_WHITE);
		assert(context.cell_owner[x][6] == CHESS_PLAYER_BLACK);
	}

	piece_t row7[] = {CHESS_PIECE_ROOK, CHESS_PIECE_BISHOP, CHESS_PIECE_KNIGHT,
		CHESS_PIECE_KING, CHESS_PIECE_QUEEN,
		CHESS_PIECE_KNIGHT, CHESS_PIECE_BISHOP, CHESS_PIECE_ROOK};

	for (int x = 0; x < 8; x++) {
		assert(context.cell_type[x][7] == row7[x]);
		assert(context.cell_owner[x][7] == CHESS_PLAYER_BLACK);
	}
}
