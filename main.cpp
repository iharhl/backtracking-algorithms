#include <iostream>
#include "knights_tour/src/knights_tour.hpp"
#include "rat_in_a_maze/src/rat_in_a_maze.hpp"

int main()
{
    std::cout << "To run KNIGHTS_TOUR press 1, to run RAT_IN_A_MAZE press any other number: ";
    int i;
    std::cin >> i;
    std::cout << std::endl;
    
    if (i==1)
    {
        knight_main();
    } 
    else
    {
        rat_main();
    }
}