#include "generate_maze.hpp"

void generateMaze(int N, Vector2& maze){

    int grid_block_x[] = {0,0,0,0,0,1,1,2,3,3,3,3,3};
    int grid_block_y[] = {1,2,3,4,5,1,2,4,0,1,2,3,4};
    int idx{};
    int idy{};
    
    // Calculate the length of the array
    int k = sizeof(grid_block_x) / sizeof(grid_block_x[0]);

    // Mark the blocked cells on the maze
    for (int i{0}; i < k; i++){
        idy = grid_block_x[i];
        idx = grid_block_y[i];
        maze[idx][idy] = -1;
    }

}