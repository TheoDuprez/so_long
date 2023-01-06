
#include <stdio.h>
#include <stdbool.h>

int solveMazeUtil(char maze[5][10], int x, int y, char sol[5][10]);

void printSolution(char sol[5][10])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
            printf(" %c ", sol[i][j]);
        printf("\n");
    }
}

int isSafe(char maze[5][10], int x, int y)
{
    printf("%d | %d\n", x, y);
    if (x >= 0 && x < 5 && y >= 0 && y < 10 && maze[x][y] == '0')
        return 1;
    return 0;
}

int solveMaze(char maze[5][10])
{
    char sol[5][10] =
    {
        { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' }
    };
    if (solveMazeUtil(maze, 1, 7, sol) == 0)
    {
        printf("Solution doesn't exist");
        return 0;
    }
    printSolution(sol);
    return 1;
}

int solveMazeUtil(char maze[5][10], int x, int y, char sol[5][10])
{
    printf("%c\n", maze[x][y]);
    if (maze[x][y] == 'E')
    {
        // sol[x][y] = '1';
        return 1;
    }
        printf("TEST\n");
    if (isSafe(maze, x, y) == 1)
    {

        // if (sol[x][y] == '1')
            // return 0;
        // sol[x][y] = '1';
        if (solveMazeUtil(maze, x + 1, y, sol) == 1)
            return 1;
		if (solveMazeUtil(maze, x - 1, y, sol) == 1)
            return 1;
		if (solveMazeUtil(maze, x, y - 1, sol) == 1)
            return 1;
        if (solveMazeUtil(maze, x, y + 1, sol) == 1)
            return 1;
        // sol[x][y] = '1';
        return 0;
    }
    return 0;
}

int main()
{
    char maze[5][10] =
    {
        { '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' },
        { '1', '0', '0', '0', '0', '0', '0', '0', '0', '1' },
        { '1', '0', '0', '1', '1', '1', '1', '0', '1', '1' },
        { '1', 'E', '0', '1', '0', '0', '0', '0', '0', '1' },
        { '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' }
    };
    solveMaze(maze);
    return 0;
}

// #include <stdio.h>
// #include <stdbool.h>

// int solveMazeUtil(int maze[6][6], int x, int y,int sol[6][6]);

// void printSolution(int sol[6][6])
// {
//     for (int i = 0; i < 6; i++)
//     {
//         for (int j = 0; j < 6; j++)
//             printf(" %d ", sol[i][j]);
//         printf("\n");
//     }
// }

// int isSafe(int maze[6][6], int x, int y)
// {
//     if (x >= 0 && x < 6 && y >= 0 && y < 6 && maze[x][y] == 1)
//         return 1;
//     return 0;
// }

// int solveMaze(int maze[6][6])
// {
//     int sol[6][6] = { { 0, 0, 0, 0 },
//                       { 0, 0, 0, 0 },
//                       { 0, 0, 0, 0 },
//                       { 0, 0, 0, 0 } };
//     if (solveMazeUtil(maze, 0, 0, sol) == 0)
//     {
//         printf("Solution doesn't exist");
//         return 0;
//     }
//     printSolution(sol);
//     return 1;
// }

// int solveMazeUtil(int maze[6][6], int x, int y, int sol[6][6])
// {
//     if (maze[x][y] == 2)
//     {
//         sol[x][y] = 1;
//         return 1;
//     }
//     if (isSafe(maze, x, y) == 1)
//     {
//         if (sol[x][y] == 1)
//             return 0;
//         sol[x][y] = 1;
//         if (solveMazeUtil(maze, x + 1, y, sol) == 1)
//             return 1;
// 		if (solveMazeUtil(maze, x - 1, y, sol) == 1)
//             return 1;
// 		if (solveMazeUtil(maze, x, y - 1, sol) == 1)
//             return 1;
//         if (solveMazeUtil(maze, x, y + 1, sol) == 1)
//             return 1;
//         sol[x][y] = 0;
//         return 0;
//     }
//     return 0;
// }

// int main()
// {
//     int maze[6][6] =
//     {
//         { 1, 1, 1, 1, 1, 1},
//         { 0, 1, 0, 0, 0, 1},
//         { 1, 1, 0, 0, 0, 1},
//         { 0, 0, 1, 2, 1, 1},
//         { 1, 0, 1, 0, 0, 0},
//         { 1, 1, 1, 1, 1, 1}
//     };
//     solveMaze(maze);
//     return 0;
// }
