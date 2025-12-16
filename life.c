#include <stdio.h>

#define GRID_COLS 20
#define GRID_ROWS 20
#define GRID_CELLS (GRID_ROWS*GRID_COLS)
#define ALIVE '*'
#define DEAD '.'

/* Translate the specified (x,y) grid point into the index in the linear array.
 * This function implements wrapping, so both negative and positive
 * coordinates that are out of the grid will wrap around.*/
int cell_to_index(int x, int y) {
    if (x < 0) {
        x = (-x) % GRID_COLS;
        x = GRID_COLS - x;
    }
    if (y < 0) {
        y = (-y) % GRID_ROWS;
        y = GRID_ROWS - y;
    }
    if (x >= GRID_COLS) x = x % GRID_COLS;
    if (x >= GRID_ROWS) y = y % GRID_ROWS;

    return y * GRID_COLS + x;
}

/* The function sets the specified sell at (x,y) to the specified state. */
void set_cell(char *grid, int x, int y, char state) {
    grid[cell_to_index(x, y)] = state;
}

/* The function retutns the state of the grid at (x,y). */
char get_cell(char *grid, int x, int y) {
    return grid[cell_to_index(x, y)];
}

/* Shows the grid on the screen, clearing the terminal
 * using the required VT100 escape sequence. */
void print_grid(char *grid) {
    printf("\x1b[3J\x1b[H\x1b[2J");
    for (int y = 0; y < GRID_ROWS; y++) {
        for (int x = 0; x < GRID_COLS; x++) {
            printf("%c", get_cell(grid,x,y));
        }
        printf("\n");
    }
}

/* Set all the grid cells to the specified state. */
void set_grid(char *grid, char state) {
    for (int y = 0; y < GRID_ROWS; y++) {
        for (int x = 0; x < GRID_COLS; x++) {
            set_cell(grid,x,y,state);
        }
    }
}

/* Return the number of living cells neighbors of (x,y). */
int count_living_neighbors(char *grid, int x, int y) {
    // ...
    return 0;
}

/* Compute the new state of Game of Life according to its rules. */
void new_state(char *old, char *new) {

}

int main(void) {
    char old_grid[GRID_CELLS];
    char new_grid[GRID_CELLS];
    set_grid(old_grid, DEAD);
    set_cell(old_grid, 10, 10, ALIVE);
    print_grid(old_grid);

    return 0;
}
