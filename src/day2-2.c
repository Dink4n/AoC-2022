#include <stdio.h>

#define YOU 0
#define OPPONENT 1

#define MOVES 3
#define BUFFER_SIZE 6

#define ASCII_X 88
#define ASCII_A 65

static char winningMoves[][MOVES] = {
    // Rock Paper Scissor
    { 'A',  'B',  'C' },
    {  3,    1,    2 }
};

int findIndex(char search) {
    int index = -1;

    for (char *c = winningMoves[OPPONENT]; c < winningMoves[OPPONENT] + MOVES; c++) {
        if (*c == search) {
            index = c - winningMoves[OPPONENT];
        }
    }

    return index + 1;
}

int didWeWin(char you, char opponent) {
    int result = 0;
    int yourMove = 0;
    int opponentIndex = opponent - ASCII_A;

    switch (you) {
        case 'X': // Lose
            result = 0;
            yourMove = winningMoves[1][opponentIndex];
            break;

        case 'Y': // Draw
            result = 3;
            yourMove = opponentIndex + 1;
            break;

        case 'Z': // Win
            result = 6;
            yourMove = findIndex(opponentIndex + 1);
            break;

        default:
            break;
    }

    return result + yourMove;
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

    printf("Score: %d\n", score);

    fclose(file);
    return 0;
}
