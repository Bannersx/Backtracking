#include <LedControl.h>
//////////////////
#include<stdio.h>

// Maze size
#define N 8

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);

/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

/* A utility function to check if x,y is valid index for N*N maze */
bool isSafe(int maze[N][N], int x, int y)
{
    // if (x,y outside maze) return false
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;

    return false;
}

/* This function solves the Maze problem using Backtracking.  It mainly
   uses solveMazeUtil() to solve the problem. It returns false if no
   path is possible, otherwise return true and prints the path in the
   form of 1s. Please note that there may be more than one solutions,
   this function prints one of the feasible solutions.*/

/* A recursive utility function to solve Maze problem */
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    // if (x,y is goal) return true
    if(x == N-1 && y == N-1)
    {
        sol[x][y] = 1;
        return true;
    }

    // Check if maze[x][y] is valid
    if(isSafe(maze, x, y) == true)
    {
        // mark x,y as part of solution path
        sol[x][y] = 1;

        /* Move forward in x direction */
        if (solveMazeUtil(maze, x+1, y, sol) == true)
            return true;

        /* If moving in x direction doesn't give solution then
           Move down in y direction  */
        if (solveMazeUtil(maze, x, y+1, sol) == true)
            return true;

        /* If none of the above movements work then BACKTRACK:
            unmark x,y as part of solution path */
        sol[x][y] = 0;
        return false;
    }

    return false;
}
bool solveMaze(int (*maze)[8]) {
    int sol[N][N] = { {0, 0, 0, 0, 0, 0, 0,0},
                      {0, 0, 0, 0, 0, 0, 0,0},
                      {0, 0, 0, 0, 0, 0, 0,0},
                      {0, 0, 0, 0, 0, 0, 0,0},
                      {0, 0, 0, 0, 0, 0, 0,0},
                      {0, 0, 0, 0, 0, 0, 0,0},
                      {0, 0, 0, 0, 0, 0, 0,0},
                      {0, 0, 0, 0, 0, 0, 0,0}
    };

    if(solveMazeUtil(maze, 0, 0, sol) == false)
    {
        printf("Solution doesn't exist");
        return false;
    }

    printSolution(sol);
    return true;
}
 
 
 
 
 
 /////////////////////////////
int DIN = 12;
int CS =  11;
int CLK = 10;
int i = 0;

byte s1[8]=     {0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xFF};
byte s2[8]=     {0x80,0x80,0x80,0x80,0x80,0x80,0xC0,0x7F};
byte s3[8]=     {0x80,0xC0,0x40,0x60,0x20,0x20,0x20,0x3F };
byte s4[8]=     {0x80,0xC0,0x40,0x60,0x20,0x20,0x3E,0x03};
byte eight[8]= {0x7E,0x7E,0x66,0x7E,0x7E,0x66,0x7E,0x7E};
byte s[8]=     {0x00,0x3C,0x40,0x40,0x3C,0x02,0x02,0x3C};
byte dot[8]=   {0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18};
byte o[8]=     {0x7E,0x7E,0x66,0x66,0x66,0x66,0x7E,0x7E};
byte m[8]=     {0xE7,0xFF,0xFF,0xDB,0xDB,0xDB,0xC3,0xC3};
byte map1[8]  = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
byte map2[8]  = {0xFF,0xFF,0xFF,0xFF,0xF7,0xFF,0xFF,0x7F};
byte map3[8]=   {0xFF,0xFF,0x7F,0xFF,0xB7,0xFF,0xFF,0x7F};
byte map4[8]=   {0xFD,0xFF,0x7F,0xFF,0xB7,0xFD,0xFF,0x7F};
byte map5[8]=   {0xDD,0xFF,0x7F,0xFF,0xB7,0xFD,0xFF,0x7B};
byte smile[8]=   {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};


byte cerocero[8] = {0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00};
byte ceroo[8] = {0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00};


LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,15);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display
}

void loop(){ 
    
    byte smile[8]=   {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};
    byte neutral[8]= {0x3C,0x42,0xA5,0x81,0xBD,0x81,0x42,0x3C};
    byte frown[8]=   {0x3C,0x42,0xA5,0x81,0x99,0xA5,0x42,0x3C};
   solvemaze();
   addobstacles();
   lc.clearDisplay(0);
   delay(1000);
  
}
void solvemaze()
{
 if (i == 0){
  printByte(map1);
  delay(1600);
    
   printByte(s1);
   delay(1600);
    
 }
 else if(i==1){
  printByte(map2);
  delay(1600);
    
   printByte(s2);
   delay(1600);
 }
 else if(i==2){
  printByte(map3);
  delay(1600);
    
   printByte(s3);
   delay(1600);
 }
 else if(i==3){
  printByte(map4);
  delay(1600);
    
   printByte(s3);
   delay(1600);
 }
 else if(i==4){
  printByte(map5);
  delay(1600);
    
   printByte(s4);
   delay(1600);
 }else if(i==5){
   printByte(smile);
   delay(1600);
 }else if (i>5){
  i=-1;
 }
}
void addobstacles(){
   i++;
}
void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
