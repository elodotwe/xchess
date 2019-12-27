#ifndef CHESS_H
#define CHESS_H

#define CHESS_PIECE_EMPTY 0
#define CHESS_PIECE_PAWN 1
#define CHESS_PIECE_ROOK 2
#define CHESS_PIECE_BISHOP 3
#define CHESS_PIECE_KNIGHT 4
#define CHESS_PIECE_QUEEN 5
#define CHESS_PIECE_KING 6

#define CHESS_PLAYER_WHITE 0
#define CHESS_PLAYER_BLACK 1

// It is currently `turn` player's turn; nobody has won and we are not in a "check" condition.
#define CHESS_STATE_NORMAL 0
// It is currently `turn` player's turn, and he must move a piece to remedy "check".
#define CHESS_STATE_CHECK 1
// The game is finished; `turn` player has lost.
#define CHESS_STATE_CHECKMATE 2

// It remains `turn` player's turn; the move specified is not valid.
#define CHESS_RESULT_ILLEGAL_MOVE -1
// The specified move was allowed; it is now the other player's turn.
#define CHESS_RESULT_SUCCESS 0

typedef int piece_t;
typedef int player_t;
typedef int result_t;
typedef int state_t;

/**
 * State object describing current game.
 *
 * First dimension of the arrays is x, second is y.
 *
 * 0, 0 is always a black square.
 */
typedef struct {
	// First dimension is x, second is y.
	piece_t cell_type[8][8];
	player_t cell_owner[8][8];
	player_t turn;
	state_t game_state;
} chesscontext_t;

/**
 * Starts a new game, overwriting the game in the given context object.
 */
void chess_initialize(chesscontext_t* context);

/**
 * Moves the piece at the given coordinates to the given coordinates.
 *
 * Returns one of the CHESS_RESULT_* constants to indicate the resulting state of the game.
 * If the return value is negative, the given move is illegal and has been rejected; otherwise, the
 * move has succeeded and gameplay continues.
 */
result_t chess_move(chesscontext_t* context, int from_x, int from_y, int to_x, int to_y);



#endif
