#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[8][8];

void init_board() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[i][j] = '.';
    board[0][0] = 'T'; board[0][7] = 'T';
    board[0][1] = 'C'; board[0][6] = 'C';
    board[0][2] = 'B'; board[0][5] = 'B';
    board[0][3] = 'Q'; board[0][4] = 'K';
    for (int i = 0; i < 8; i++) board[1][i] = 'P';
}

void print_board() {
    for (int i = 7; i >= 0; i--) {
        printf("%d ", i);
        for (int j = 0; j < 8; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    printf("  0 1 2 3 4 5 6 7\n");
}

bool is_clear_path(int x1, int y1, int x2, int y2) {
    int dx = (x2 - x1) ? ((x2 - x1) > 0 ? 1 : -1) : 0;
    int dy = (y2 - y1) ? ((y2 - y1) > 0 ? 1 : -1) : 0;
    x1 += dx;
    y1 += dy;
    while (x1 != x2 || y1 != y2) {
        if (board[y1][x1] != '.') return false;
        x1 += dx;
        y1 += dy;
    }
    return true;
}

bool is_valid_move(int x1, int y1, int x2, int y2) {
    char p = board[y1][x1];
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    switch (p) {
        case 'P': return x1 == x2 && (y2 == y1 + 1 || (y1 == 1 && y2 == y1 + 2));
        case 'T': return (x1 == x2 || y1 == y2) && is_clear_path(x1, y1, x2, y2);
        case 'B': return dx == dy && is_clear_path(x1, y1, x2, y2);
        case 'C': return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
        case 'Q': return ((dx == dy || x1 == x2 || y1 == y2) && is_clear_path(x1, y1, x2, y2));
        case 'K': return dx <= 1 && dy <= 1;
        default: return false;
    }
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
