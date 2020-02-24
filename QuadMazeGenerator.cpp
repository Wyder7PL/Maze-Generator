#include "QuadMazeGenerator.hpp"

void QuadMazeGenerator::GenerateMaze(Maze2d & maze,const Uint32x2 & point)
{
    Uint32x2 MazeSize = maze.GetDimensions();
    Uint32x2 center = Uint32x2((MazeSize.x-1*(MazeSize.x%2))/2,(MazeSize.y-1*(MazeSize.y%2))/2);

    SetAreaForMazeGenerating(Uint32x2(0,0) , Uint32x2( center.x , center.y ));
    Maze2dGenerator::GenerateMaze(maze);

    SetAreaForMazeGenerating(Uint32x2(center.x,0) , Uint32x2(MazeSize.x,center.y));
    Maze2dGenerator::GenerateMaze(maze,Uint32x2(MazeSize.x,0));

    SetAreaForMazeGenerating(Uint32x2(0,center.y),Uint32x2(center.x , MazeSize.y));
    Maze2dGenerator::GenerateMaze(maze,Uint32x2(0,MazeSize.y));

    SetAreaForMazeGenerating(Uint32x2(center.x,center.y),Uint32x2(MazeSize.x,MazeSize.y));
    Maze2dGenerator::GenerateMaze(maze,Uint32x2(MazeSize.x,MazeSize.y));

    MazePostGenerating(maze);
}

void QuadMazeGenerator::MazePostGenerating(Maze2d & maze)
{
    Uint32x2 mazeSize = maze.GetDimensions();
    Uint32x2 center = Uint32x2((mazeSize.x-1*(mazeSize.x%2))/2,(mazeSize.y-1*(mazeSize.y%2))/2);

    RandomUint32Generator rug;
    rug.RandomizeGenerator();

    ConnectNorthBlocks(maze,rug,mazeSize,center);
    ConnectWestBlocks(maze,rug,mazeSize,center);
    ConnectSouthBlocks(maze,rug,mazeSize,center);
    ConnectEastBlocks(maze,rug,mazeSize,center);
}

void QuadMazeGenerator::ConnectNorthBlocks(Maze2d & maze,RandomUint32Generator & rug,const Uint32x2 & mazeSize,const Uint32x2 & center)
{
    uint32_t random = rug.GenerateRandomInRange(0,center.y-1);
    maze.SetWallStatus(EAST,Uint32x2(center.x-1 , random),false);
    maze.SetWallStatus(WEST,Uint32x2(center.x , random),false);
}

void QuadMazeGenerator::ConnectWestBlocks(Maze2d & maze,RandomUint32Generator & rug,const Uint32x2 & mazeSize,const Uint32x2 & center)
{
    uint32_t random = rug.GenerateRandomInRange(0,center.x-1);
    maze.SetWallStatus(SOUTH,Uint32x2(random , center.y-1),false);
    maze.SetWallStatus(NORTH,Uint32x2(random , center.y),false);
}

void QuadMazeGenerator::ConnectSouthBlocks(Maze2d & maze,RandomUint32Generator & rug,const Uint32x2 & mazeSize,const Uint32x2 & center)
{
    uint32_t random = rug.GenerateRandomInRange(center.y,mazeSize.y);
    maze.SetWallStatus(EAST,Uint32x2(center.x-1 , random),false);
    maze.SetWallStatus(WEST,Uint32x2(center.x , random),false);
}

void QuadMazeGenerator::ConnectEastBlocks(Maze2d & maze,RandomUint32Generator & rug,const Uint32x2 & mazeSize,const Uint32x2 & center)
{
    uint32_t random = rug.GenerateRandomInRange(center.x,mazeSize.x);
    maze.SetWallStatus(SOUTH,Uint32x2(random , center.y-1),false);
    maze.SetWallStatus(NORTH,Uint32x2(random , center.y),false);
}
