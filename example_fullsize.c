#include <stdlib.h>
#include <stdio.h>

#define GRID_SIZE 4

int g_view_up[GRID_SIZE];
int g_view_down[GRID_SIZE];
int g_view_left[GRID_SIZE];
int g_view_right[GRID_SIZE];

void init_views(int* views) {
    for (int i = 0; i < GRID_SIZE; i++) {
        g_view_up[i] = views[i];
        g_view_down[i] = views[i + GRID_SIZE];
        g_view_left[i] = views[i + 2 * GRID_SIZE];
        g_view_right[i] = views[i + 3 * GRID_SIZE];
    }
}

void print_grid(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

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

void solve(int grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    // TODO: implementeer de logica om het rooster op te lossen
}

int main(int argc, char** argv) {
    if (argc != 17) {
        printf("Error\n");
        return 0;
    }

    int views[16];
    for (int i = 0; i < 16; i++) {
        views[i] = atoi(argv[i + 1]);
        if (views[i] < 1 || views[i] > 4) {
            printf("Error\n");
            return 0;
        }
    }

    init_views(views);

    int grid[GRID_SIZE][GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = 0;
        }
    }

    solve(grid, 0, 0);

    if (check_views(grid)) {
        print_grid(grid);
    } else {
        printf("Error\n");
    }

    return 0;
}

