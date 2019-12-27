#include "chess.h"

void main() {

}

// When I set up a new board:
//  all pieces should be in the correct positions
//  it should be white's turn
//  game state should be normal
int test_initialize() {
	chesscontext_t context;
	// TODO: deliberately fill with garbage to highlight initialization issues
	chess_initialize(&context);
	if (context.turn != CHESS_PLAYER_WHITE) {
		return -1;
	}

	if (context.game_state != CHESS_STATE_NORMAL) {
		return -2;
	}

	// TODO: I'm pretty sure it's valid to set white up on either side of the board?
	// Assuming white is on row 0 for this.
	piece_t row0[] = {CHESS_PIECE_ROOK, CHESS_PIECE_BISHOP, CHESS_PIECE_KNIGHT,
		CHESS_PIECE_QUEEN, CHESS_PIECE_KING,
		CHESS_PIECE_KNIGHT, CHESS_PIECE_BISHOP, CHESS_PIECE_ROOK };

	for (int x = 0; x < 8; x++) {
		if (context.cell_type[x][0] != row0[x]) {
			return -3;
		}
	}

	piece_t row1[

	return 0;
}
