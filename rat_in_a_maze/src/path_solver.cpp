#include "path_solver.hpp"

// Check if indicies are valid
int isItValid(int x, int y, int N, int& cellStatus){
    return (x >= 0 && x < N && y >= 0 && y < N && cellStatus == 0);
}

// Solve the maze path 
bool solveMaze(int N, Vector2& maze){

    /* xMove and yMove define possible (x, y) combinations
    of how the rat can move in the maze */
    int xMove[4] = {1, 0, -1, 0};
    int yMove[4] = {0, 1, 0, -1};

    // Rat starts at (0, 0)
    maze[0][0] = 1;

    /* If solver returns false (0) -> solution is not found,
    if true (1) -> print the solution matrix */
    if(!solver(0, 0, N, maze, xMove, yMove)){
        // Solution not exists
        return 0;
    } else {
        // Solution found
        return 1;
    }
}

bool solver(int x, int y, int N, Vector2& maze, int xMove[], int yMove[]){

    int k, newX, newY;

    for (k = 0; k < 4; k++){
        newX = x + xMove[k];
        newY = y + yMove[k];
        if(isItValid(newX, newY, N, maze[newX][newY])){
            maze[newX][newY] = 1;

            if (newX == N-1 && newY == N-1){
                return 1;
            }

            if(solver(newX, newY, N, maze, xMove, yMove)){
                return 1;
            } else {
                maze[newX][newY] = 0;
            }
        }
    }
    return 0;
}


