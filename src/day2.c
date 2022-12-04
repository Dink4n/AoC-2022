#include <stdio.h>

#define YOU 0
#define OPPONENT 1

#define MOVES 3
#define BUFFER_SIZE 6

#define ASCII_X 88
#define ASCII_A 65

static char winningMoves[][MOVES] = {
    { 'X', 'Y', 'Z' },
    { 'C', 'A', 'B' },
};

int didWeWin(char you, char opponent) {
    int result = 0;
    int yourIndex = you - ASCII_X;
    int opponentIndex = opponent - ASCII_A;

    if (winningMoves[OPPONENT][yourIndex] == opponent) {
        result = 6;
    } else if (yourIndex == opponentIndex) { // Check if game is draw
        result = 3;
    }

    return result + (yourIndex + 1);
}

int main (int argc, char *argv[]) {
    FILE *file = fopen("input/day2.txt", "r");

    int ch;
    int result = 0;
    int score = result;
    char yourMove;
    char opponentMove;
    char buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        yourMove = buffer[2];
        opponentMove = buffer[0];

        result = didWeWin(yourMove, opponentMove);

        score += result;
    }

    printf("X: %d, Y: %d, Z: %d\nA: %d, B: %d, C: %d\n",'X', 'Y', 'Z', 'A', 'B', 'C');
    printf("Score: %d\n", score);

    fclose(file);
    return 0;
}
