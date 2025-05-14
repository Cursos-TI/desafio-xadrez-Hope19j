#include <stdio.h>

char board[8][8];

void init_board() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[i][j] = '.';
    board[1][0] = 'P'; // Peão
}

void print_board() {
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void move_piece(int x1, int y1, int x2, int y2) {
    board[y2][x2] = board[y1][x1];
    board[y1][x1] = '.';
}

int main() {
    init_board();
    print_board();
    printf("Mover peça de x1 y1 para x2 y2 (ex: 0 1 0 2): ");
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    move_piece(x1, y1, x2, y2);
    print_board();
    return 0;
}
