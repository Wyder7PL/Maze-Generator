#pragma once

#include <vector>
#include <memory>

#include "MazeBlock.hpp"
#include "Point.hpp"

class Maze2d
{
protected:
    Maze2d()=delete;
    Maze2d(const Point<uint32_t> & dimensions);
    void SetMazeBlocks(std::vector<std::vector<std::shared_ptr<MazeBlock>>> newBlock);
public:
    virtual ~Maze2d();

    void SetWallStatus(Directions direction,Point<uint32_t> blockpos, bool value);
    bool GetWallStatus(Directions direction,Point<uint32_t> blockpos);
    Point<uint32_t> GetDimensions();
private:
    Point<uint32_t> dimensions;
    std::vector <std::vector <std::shared_ptr <MazeBlock> > > blocks;
};
