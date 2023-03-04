#include <stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

int is_valid(int **grid, int *views, int row, int col, int size);
int backtrack(int **grid, int *views, int row, int col, int size);

void solve(int *views) {
    int size = 4; // start met een 4x4 grid
    int **grid = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        grid[i] = calloc(size, sizeof(int));
    }
    backtrack(grid, views, 0, 0, size);
    // geef geheugen vrij
    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);
}

int is_valid(int **grid, int *views, int row, int col, int size) {
    int count;
    // controleer of elke rij voldoet aan het juiste aantal zichtbare vakjes
    for (int i = 0; i < size; i++) {
        count = 0;
        int max_height = 0;
        for (int j = 0; j < size; j++) {
            if (grid[i][j] > max_height) {
                max_height = grid[i][j];
                count++;
            }
        }
        if (count != views[i] && views[i] != -1) {
            return 0;
        }
    }
    // controleer of elke kolom voldoet aan het juiste aantal zichtbare vakjes
    for (int i = 0; i < size; i++) {
        count = 0;
        int max_height = 0;
        for (int j = 0; j < size; j++) {
            if (grid[j][i] > max_height) {
                max_height = grid[j][i];
                count++;
            }
        }
        if (count != views[size + i] && views[size + i] != -1) {
            return 0;
        }
    }
    return 1; // grid voldoet aan alle regels
}

int backtrack(int **grid, int *views, int row, int col, int size) {
    // base case: we hebben een oplossing gevonden
    if (row == size && col == 0) {
        // print de oplossing
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        return 1; // oplossing gevonden
    }
    // bereken de volgende rij- en kolomwaarden
    int next_row = row;
    int next_col = col + 1;
    if (next_col == size) {
        next_row++;
        next_col = 0;
    }
    // als het huidige vakje al is ingevuld, ga naar het volgende vakje
    if (grid[row][col] != 0) {
        return backtrack(grid, views, next_row, next_col, size);
    }
    // probeer elke mogelijke hoogte voor het huidige vakje
    for (int i = 1; i <= size; i++) {
       

