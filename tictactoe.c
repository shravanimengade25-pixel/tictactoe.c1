#include <stdio.h>

char board[3][3];
char currentPlayer = 'X';

// Function declarations
void initBoard();
void printBoard();
int makeMove(int row, int col);
int checkWin();

int main() {
    int row, col, moves = 0;

    initBoard();

    while (1) {
        printBoard();
        printf("Player %c, enter your move (row and col 1-3): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Input validation
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input. Enter numbers between 1 and 3.\n");
            continue;
        }

        if (makeMove(row - 1, col - 1)) {
            moves++;

            if (checkWin()) {
                printBoard();
                printf("Player %c wins!\n", currentPlayer);
                break;
            }

            if (moves == 9) {
                printBoard();
                printf("It's a draw!\n");
                break;
            }

            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            printf("Invalid move. Cell already occupied.\n");
        }
    }

    return 0;
}

// Initialize board with spaces
void initBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// Print the board nicely
void printBoard() {
    printf("\n   1   2   3\n"); // column numbers
    for (int i = 0; i < 3; i++) {
        printf("%d ", i + 1); // row number
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("  ---|---|---\n");
    }
    printf("\n");
}

// Make a move on the board
int makeMove(int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return 1;
    }
    return 0;
}

// Check if current player has won
int checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return 1;
        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return 1;
    }

    // Check diagonals
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return 1;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return 1;

    return 0;
}
