/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpilette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:59:19 by mpilette          #+#    #+#             */
/*   Updated: 2023/03/04 16:28:13 by mpilette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define GRID_SIZE 4

int		g_view_up[GRID_SIZE];
int		g_view_down[GRID_SIZE];
int		g_view_left[GRID_SIZE];
int		g_view_right[GRID_SIZE];

void	init_views(int *views)
{
	for (int i = 0; i < GRID_SIZE; i++)
	{
		g_view_up[i] = views[i];
		g_view_down[i] = views[i + GRID_SIZE];
		g_view_left[i] = views[i + 2 * GRID_SIZE];
		g_view_right[i] = views[i + 3 * GRID_SIZE];
	}
}

void	print_grid(int grid[GRID_SIZE][GRID_SIZE])
{
	for (int i = 0; i < GRID_SIZE; i++)
	{
		for (int j = 0; j < GRID_SIZE; j++)
		{
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
}

int	check_view(int view, int a[GRID_SIZE])
{
	int	highest;
	int	count;

	highest = 0;
	count = 0;
	for (int i = 0; i < GRID_SIZE; i++)
	{
		if (a[i] > highest)
		{
			highest = a[i];
			count++;
		}
	}
	return (view == count);
}

int	check_views(int grid[GRID_SIZE][GRID_SIZE])
{
	for (int i = 0; i < GRID_SIZE; i++)
	{
		if (!check_view(g_view_up[i], grid[i]))
		{
			return (0);
		}
		if (!check_view(g_view_down[i], grid[GRID_SIZE - 1 - i]))
		{
			return (0);
		}
		if (!check_view(g_view_left[i], grid[0][i], grid[1][i], grid[2][i],
				grid[3][i]))
		{
			return (0);
		}
		if (!check_view(g_view_right[i], grid[0][GRID_SIZE - 1 - i],
				grid[1][GRID_SIZE - 1 - i], grid[2][GRID_SIZE - 1 - i],
				grid[3][GRID_SIZE - 1 - i]))
		{
			return (0);
		}
	}
	return (1);
}

void	solve(int grid[GRID_SIZE][GRID_SIZE], int row, int col)
{
	// TODO: implementeer de logica om het rooster op te lossen
//#define MIN(a,b) (((a)<(b))?(a):(b))

int is_valid(int **grid, int *views, int row, int col, int size);
int backtrack(int **grid, int *views, int row, int col, int size);

void solve(int *views)
{
    int size = 4; // start met een 4x4 grid
    int **grid = malloc(size * sizeof(int *));

    for (int i = 0; i < size; i++)
    {
        grid[i] = calloc(size, sizeof(int));
    }
    backtrack(grid, views, 0, 0, size);
    // geef geheugen vrij
    for (int i = 0; i < size; i++)
    {
        free(grid[i]);
    }
    free(grid);
}

int is_valid(int **grid, int *views, int row, int col, int size)
{
    int count;
    // controleer of elke rij voldoet aan het juiste aantal zichtbare vakjes
    for (int i = 0; i < size; i++)
    {
        count = 0;
        int max_height = 0;
        for (int j = 0; j < size; j++)
       	{
            if (grid[i][j] > max_height)
	    {
                max_height = grid[i][j];
                count++;
            }
        }
        if (count != views[i] && views[i] != -1) {
            return 0;
        }
    }
    // controleer of elke kolom voldoet aan het juiste aantal zichtbare vakjes
    for (int i = 0; i < size; i++)
    {
        count = 0;
        int max_height = 0;
        for (int j = 0; j < size; j++)
       	{
            if (grid[j][i] > max_height)
	    {
                max_height = grid[j][i];
                count++;
            }
        }
	    if (count != views[size + i] && views[size + i] != -1)
       	{
            return 0;
        }
    }
    return 1; // grid voldoet aan alle regels
}

int backtrack(int **grid, int *views, int row, int col, int size)
{
    // base case: we hebben een oplossing gevonden
    if (row == size && col == 0)
    {
        // print de oplossing
        for (int i = 0; i < size; i++)
       	{
            for (int j = 0; j < size; j++)
	    {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        return 1; // oplossing gevonden
    }
    // bereken de volgende rij- en kolomwaarden
    int next_row = row;
    int next_col = col + 1;
    if (next_col == size)
    {
        next_row++;
        next_col = 0;
    }
    // als het huidige vakje al is ingevuld, ga naar het volgende vakje
    if (grid[row][col] != 0)
    {
        return backtrack(grid, views, next_row, next_col, size);
    }
    // probeer elke mogelijke hoogte voor het huidige vakje
    for (int i = 1; i <= size; i++)
    {


}

int	main(int argc, char **argv)
{
	int	views[16];
	int	grid[GRID_SIZE][GRID_SIZE];

	if (argc != 17)
	{
		printf("Error\n");
		return (0);
	}
	for (int i = 0; i < 16; i++)
	{
		views[i] = atoi(argv[i + 1]);
		if (views[i] < 1 || views[i] > 4)
		{
			printf("Error\n");
			return (0);
		}
	}
	init_views(views);
	for (int i = 0; i < GRID_SIZE; i++)
	{
		for (int j = 0; j < GRID_SIZE; j++)
		{
			grid[i][j] = 0;
		}
	}
	solve(grid, 0, 0);
	if (check_views(grid))
	{
		print_grid(grid);
	}
	else
	{
		printf("Error\n");
	}
	return (0);
}

