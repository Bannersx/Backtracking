//
// Created by alex on 18/11/18.
//

#ifndef BACKTRACKING_MAZE_H
#define BACKTRACKING_MAZE_H
#define N 8


class Maze {
public:

    int maze[N][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 1, 1},
    };
    void addObstacle();
    void print();
};


#endif //BACKTRACKING_MAZE_H
