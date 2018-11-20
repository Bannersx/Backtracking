//
// Created by alex on 18/11/18.
//

#include "Maze.h"
#include <stdlib.h>
#include<stdio.h>
#define N 8


void Maze::addObstacle() {
    for (int m = 0; m <2; m++ ) {
        int i = rand() % 8;
        int j = rand() % 8;
        if (maze[i][j] = 1) {
            maze[i][j] = 0;
        } else {
            addObstacle();
        }
    }

}
void Maze::print()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", maze[i][j]);
        printf("\n");
    }
}
