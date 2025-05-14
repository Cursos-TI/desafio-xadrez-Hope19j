#include <stdio.h>
#include <stdbool.h>

char board[8][8];

void init_board() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[i][j] = '.';
    board[1][0] = 'P'; // Peão
    board[0][0] = 'T'; // Torre
}

void print_board() {
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool valid_pawn_move(int x1, int y1, int x2, int y2) {
    return x1 == x2 && (y2 == y1 + 1 || (y1 == 1 && y2 == y1 + 2));
}

bool valid_rook_move(int x1, int y1, int x2, int y2) {
    return (x1 == x2 || y1 == y2);
}

bool is_valid_move(int x1, int y1, int x2, int y2) {
    char piece = board[y1][x1];
    if (piece == 'P')
        return valid_pawn_move(x1, y1, x2, y2);
    if (piece == 'T')
        return valid_rook_move(x1, y1, x2, y2);
    return false;
}

void move_piece(int x1, int y1, int x2, int y2) {
    if (is_valid_move(x1, y1, x2, y2)) {
        board[y2][x2] = board[y1][x1];
        board[y1][x1] = '.';
    } else {
        printf("Movimento inválido!\n");
    }
}

int main() {
    init_board();
    print_board();
    int x1, y1, x2, y2;
    while (1) {
        printf("Mover peça (x1 y1 x2 y2): ");
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        move_piece(x1, y1, x2, y2);
        print_board();
    }
    return 0;
}
