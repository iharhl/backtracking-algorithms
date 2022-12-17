#include "rat_in_a_maze.hpp"

void printOut(int N, Vector2& maze){
    for (int x{0}; x < N; x++){
        for (int y{0}; y < N; y++){
            std::cout << " " << std::setw(2) << maze[x][y] << " ";
        }
        std::cout << std::endl;
    }
}

int rat_main(){

    int N{}; // size of the grid
    bool solved{};

    /* Currently only support size of 6x6 */
    N = 6;
    // std::cout << "Input the size of the maze: ";
    // std::cin >> N;
    // std::cout << std::endl;
    std::cout << "Size of the maze: " << N << std::endl;

    // Initialize 2d vector with values 0
    Vector2 maze(N, Vector(N, 0)); 

    // Put the blocked cells on the grid
    generateMaze(N, maze);

    // Solve the maze
    solved = solveMaze(N, maze);
    if(solved){
        std::cout << "Solution found: " << std::endl;
        printOut(N, maze);
    } else {
        std::cout << "Solution does not exist!" << std::endl;
    }

    return 0;
}
