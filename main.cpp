#include <iostream>
#include "Backtracking.cpp"
#include "Maze.h"
#include "Maze.cpp"
#include <unistd.h>
using namespace std;


int main() {
    std::cout << "Hello, World!" << std::endl;


    srand (time(NULL));

    Backtracking *test = new Backtracking();
    int maze[N][N]  =  {{1, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 1, 0, 0, 0, 0, 0},
                        {1, 0, 1, 1, 1, 1, 1, 1},
                        {1, 0, 1, 0, 0, 1, 0, 1},
                        {1, 0, 1, 0, 0, 1, 0, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {0, 0, 0, 1, 0, 0, 0, 1},
                        {0, 0, 0, 1, 1, 1, 1, 1},


    };
    std::cout<<"Test maze solution"<< std::endl;
    test->solveMaze(maze);
    Maze* maze2 = new Maze();
    std::cout<<" "<< std::endl;
    std::cout<<"Obstacle clear maze"<< std::endl;
    maze2->print();
    std::cout<<" "<< std::endl;
    usleep(3000000);

    std::cout<<"Solution to oc maze"<< std::endl;
    test->solveMaze(maze2->maze);
    ///adding the fisrt 2 obstacles
    maze2->addObstacle();
    std::cout<<" "<< std::endl;
    std::cout<<"Maze with 2 obstacles "<< std::endl;
    maze2->print();
    std::cout<<" "<< std::endl;
    usleep(3000000);

    std::cout<<" 2 obstacles solved"<< std::endl;
    test->solveMaze(maze2->maze);
    ///adding the second  2 obstacles
    maze2->addObstacle();
    std::cout<<" "<< std::endl;
    std::cout<<" 4 obstacles"<< std::endl;
    maze2->print();
    std::cout<<" "<< std::endl;

    std::cout<<"4 obstacles solved "<< std::endl;
    test->solveMaze(maze2->maze);
    usleep(3000000);
    ///adding the third 2 obstacles
    maze2->addObstacle();
    std::cout<<" "<< std::endl;
    std::cout<<"6 obstacles "<< std::endl;
    maze2->print();
    std::cout<<" "<< std::endl;

    std::cout<<" 6 obstacles solved"<< std::endl;
    test->solveMaze(maze2->maze);


    return 0;
}