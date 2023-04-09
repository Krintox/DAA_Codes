#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 20 // maximum board size

int board[N][N]; // board for placing queens
bool row[N], diag1[2 * N - 1], diag2[2 * N - 1]; // arrays to keep track of occupied rows and diagonals
int n; // size of board

// function to print the board
void printBoard() {
    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%c ", board[i][j] ? 'Q' : '.'); // print Q for queen, . for empty cell
        printf("\n");
    }
}

// recursive function to solve the n-queens problem
void solve(int col) {
    if (col == n) { // all columns are occupied
        printBoard();
        return;
    }

    // consider all rows for the current column
    for (int i = 0; i < n; i++) {
        // check if the current row and diagonals are free
        if (!row[i] && !diag1[i - col + n - 1] && !diag2[i + col]) {
            board[i][col] = 1; // place queen on current cell
            row[i] = diag1[i - col + n - 1] = diag2[i + col] = true; // mark current row and diagonals as occupied
            solve(col + 1); // recur to place queens in remaining columns
            // backtrack: remove queen from current cell and mark current row and diagonals as free
            board[i][col] = 0;
            row[i] = diag1[i - col + n - 1] = diag2[i + col] = false;
        }
    }
}

int main() {
    printf("Enter the size of the board: ");
    scanf("%d", &n);
    if (n > N) {
        printf("Maximum board size is %d. Please enter a smaller size.\n", N);
        return 0;
    }

    // initialize board and arrays to false
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            board[i][j] = 0;
        row[i] = false;
    }
    for (int i = 0; i < 2 * n - 1; i++)
        diag1[i] = diag2[i] = false;

    solve(0); // start with the first column
    return 0;
}
