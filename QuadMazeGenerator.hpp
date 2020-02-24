#pragma once

#include "Generate2dMazeInSquare.hpp"
#include "RandomUint32Generator.hpp"

class QuadMazeGenerator : Generate2dMazeInSquare
{
public:
    virtual void GenerateMaze(Maze2d & maze,const Uint32x2 & point = Uint32x2(0,0)) override;
protected:
    virtual void MazePostGenerating(Maze2d & maze);
private:

    void ConnectNorthBlocks(Maze2d & maze,RandomUint32Generator & rug,const Uint32x2 & mazeSize,const Uint32x2 & center);
    void ConnectWestBlocks(Maze2d & maze,RandomUint32Generator & rug,const Uint32x2 & mazeSize,const Uint32x2 & center);
    void ConnectSouthBlocks(Maze2d & maze,RandomUint32Generator & rug,const Uint32x2 & mazeSize,const Uint32x2 & center);
    void ConnectEastBlocks(Maze2d & maze,RandomUint32Generator & rug,const Uint32x2 & mazeSize,const Uint32x2 & center);
};
