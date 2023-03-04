#include <stdlib.h>
#include <stdio.h>

#define GRID_SIZE 4

int g_view_up[GRID_SIZE];
int g_view_down[GRID_SIZE];
int g_view_left[GRID_SIZE];
int g_view_right[GRID_SIZE];

// Initialiseert de arrays die de zichtbare gebouwen bevatten
void init_views(int* views) {
    for (int i = 0; i < GRID_SIZE; i++) {
        g_view_up[i] = views[i];
        g_view_down[i] = views[i + GRID_SIZE];
        g_view_left[i] = views[i + 2 * GRID_SIZE];
        g_view_right[i] = views[i + 3 * GRID_SIZE];
    }
}

// Print het rooster op het scherm
void print_grid(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Controleert of het aantal zichtbare gebouwen overeenkomt met de gegeven waarde
int check_view(int view, int a[GRID_SIZE]) {
    int highest = 0;
    int count = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        if (a[i] > highest) {
            highest = a[i];
            count++;
        }
    }
    return view == count;
}

// Controleert of het rooster aan de zichtbare gebouwen voldoet
int check_views(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (!check_view(g_view_up[i], grid[i])) {
            return 0;
        }
        if (!check_view(g_view_down[i], grid[GRID_SIZE - 1 - i])) {
            return 0;
        }
        if (!check_view(g_view_left[i], grid[0][i], grid[1][i], grid[2][i], grid[3][i])) {
            return 0;
        }
        if (!check_view(g_view_right[i], grid[0][GRID_SIZE - 1 - i], grid[1][GRID_SIZE - 1 - i], grid[2][GRID_SIZE - 1 - i], grid[3][GRID_SIZE - 1 - i])) {
            return 0;
        }
    }
    return 1;
}

// Recursieve functie om het rooster op te lossen
void solve(int grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    // Base case: als de rij gelijk is aan GRID_SIZE, hebben we het einde van het rooster bereikt
    if (row == GRID_SIZE) {
        // Controleer of het rooster aan de zichtbare gebouwen voldoet
        if (check_views(grid)) {
            // Als het rooster aan de zichtbare gebouwen voldoet, print het rooster
            print_grid(grid);
        }
        return;
    }

    // Als we het einde van de kolom hebben bereikt, ga naar de volgende rij
    if (col == GRID_SIZE) {
        solve(grid, row + 1, 0);
        return;
    }

    // Probeer elke waarde van 1 tot GRID_SIZE op deze plaats
    for (int i = 1

