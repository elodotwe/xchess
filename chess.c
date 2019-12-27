#include "chess.h"
#include <string.h>

void chess_initialize(chesscontext_t* context) {
	context->turn = CHESS_PLAYER_WHITE;
	context->game_state = CHESS_STATE_NORMAL;

	memset(context->cell_type, 0, sizeof(piece_t) * 8 * 8);
	piece_t row0[] = {CHESS_PIECE_ROOK, CHESS_PIECE_BISHOP, CHESS_PIECE_KNIGHT,
		CHESS_PIECE_QUEEN, CHESS_PIECE_KING, //We'll swap these for the other end of the board.
		CHESS_PIECE_KNIGHT, CHESS_PIECE_BISHOP, CHESS_PIECE_ROOK};
	for (int x = 0; x < 8; x++) {
		context->cell_type[x][0] = row0[x];
		context->cell_type[7-x][7] = row0[x];
		context->cell_type[x][1] = CHESS_PIECE_PAWN;
		context->cell_type[x][6] = CHESS_PIECE_PAWN;
		for (int y = 2; y <= 5; y++) {
			context->cell_type[x][y] = CHESS_PIECE_EMPTY;
		}
	}
}


result_t chess_move(chesscontext_t* context, int from_x, int from_y, int to_x, int to_y) {
	return 0;
}
