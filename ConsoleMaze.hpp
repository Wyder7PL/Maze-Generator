#pragma once

#include <string>
#include <iostream>

#include "Maze2d.hpp"
#include "ConsoleMazeBlock.hpp"

class ConsoleMaze : public Maze2d
{
public:
    ConsoleMaze()=delete;
    ConsoleMaze(const Point<uint32_t> & dimension,const Point<uint32_t> & blocksiz);
    virtual void DrawMaze(std::ostream &);
    virtual void DrawMazeDebug(std::ostream &);
private:
    Point<uint32_t> blockSize;
    std::vector<std::vector<std::shared_ptr<ConsoleMazeBlock>>> blocks;
};
