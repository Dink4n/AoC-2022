#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void swap(unsigned int *a, unsigned int *b) {
    unsigned int swapper = *a;

    *a = *b;
    *b = swapper;
}

void sortTop3(unsigned int total, unsigned int *top3) {
    if (total > top3[2]) {
        top3[2] = total;

        if (top3[2] > top3[1]) {
            /* top3[1] = top3[2]; */
            swap(top3 + 1, top3 + 2);

            if (top3[1] > top3[0]) {
                /* top3[0] = top3[1]; */
                swap(top3 + 0, top3 + 1);
            }
        }
    }
}

int main(int argc, char *argv[]) {

    unsigned int elfChungus[3] = {0}, totalElfCalories = 0, elfCalorie = 0;

    FILE *input = fopen("input/day1.txt", "r");

    if (input == NULL) {
        fprintf(stderr, "Where da input?\n");

        return 0;
    }

    char buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, input) != NULL) {
        if (buffer[0] == '\n') {
            sortTop3(totalElfCalories, elfChungus);
            elfCalorie = 0;
            totalElfCalories = 0;

            continue;
        }

        elfCalorie = strtol(buffer, NULL, 10);
        totalElfCalories += elfCalorie;
    }

    sortTop3(totalElfCalories, elfChungus);

    printf("Part 1: %d\n", elfChungus[0]);
    printf("Part 2: %d\n", elfChungus[0] + elfChungus[1] + elfChungus[2]);

    fclose(input);
    return 0;
}
