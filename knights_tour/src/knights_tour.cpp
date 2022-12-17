#include "knights_tour.hpp"

bool solver(int x, int y, int N, int countMove, Vector2d &solution, int xMove[], int yMove[]);

// Check if indicies are valid
int isValid(int x, int y, int N, int& solutionStatus){
    return (x >= 0 && x < N && y >= 0 && y < N && solutionStatus == -1);
}

// Print out the solution
void printSolution(Vector2d &solution, int N){
    for (int x{0}; x < N; x++){
        for (int y{0}; y < N; y++){
            std::cout << " " << std::setw(2) << solution[x][y] << " ";
        }
        std::cout << std::endl;
    }    
}

// Solve Knight's Tour problem with backtracking
void solveKT(int N){

    // Initialize 2d vector with values -1
    Vector2d solution(N, Vector(N, -1));

    /* xMove and yMove define possible (x, y) combinations
    of how the knight can move on the board */
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    // Knight starts at (0, 0)
    solution[0][0] = 0;

    /* If solver returns false (0) -> solution is not found,
    if true (1) -> print the solution matrix */
    if(!solver(0, 0, N, 1, solution, xMove, yMove)){
        std::cout << "Solution does not exist" << std::endl;
    } else {
        std::cout << "Found solution: " << std::endl;
        printSolution(solution, N);
    }
}

bool solver(int x, int y, int N, int countMove, Vector2d &solution, int xMove[], int yMove[]){

    int k, newX, newY;

    // If all moves are complete, return success
    if (countMove == N * N){
        return 1;
    }

    // Backtracking through use of recursion
    for (k = 0; k < 8; k++){
        newX = x + xMove[k];
        newY = y + yMove[k];
        if (isValid(newX, newY, N, solution[newX][newY])){
            solution[newX][newY] = countMove;
            if(solver(newX, newY, N, countMove+1, solution, xMove, yMove)){
                return 1;
            } else {
                solution[newX][newY] = -1; //backtrack
            }
        }
    }
    return 0;  
}

int knight_main(){

    int N{};

    // Request user input
    std::cout << "Enter board size: ";
    std::cin >> N;
    std::cout << std::endl;

    // Backtracking loop
    solveKT(N);

    return 0;
}