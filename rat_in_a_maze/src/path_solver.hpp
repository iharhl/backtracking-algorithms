#ifndef PATH_SOLVER_H_
#define PATH_SOLVER_H_

#include "types.hpp"

int isItValid();
bool solveMaze(int N, Vector2& maze);
bool solver(int x, int y, int N, Vector2& maze, int xMove[], int yMove[]);

#endif