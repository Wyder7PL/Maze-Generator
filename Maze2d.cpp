#include "Maze2d.hpp"

Maze2d::~Maze2d(){}

Maze2d::Maze2d(const Point<uint32_t> & dimension)
: dimensions(dimension)
{

}

void Maze2d::SetMazeBlocks(std::vector<std::vector<std::shared_ptr<MazeBlock>>> newBlocks)
{
    blocks=std::move(newBlocks);
}

void Maze2d::SetWallStatus(Directions direction,Point<uint32_t> blockpos, bool value)
{
    blocks[std::min(blockpos.y,dimensions.y-1)][std::min(blockpos.x,dimensions.x-1)]->SetWall(direction,value);
}

bool Maze2d::GetWallStatus(Directions direction,Point<uint32_t> blockpos)
{
    return blocks[std::min(blockpos.y,dimensions.y-1)][std::min(blockpos.x,dimensions.x-1)]->CheckForWall(direction);
}

Point<uint32_t> Maze2d::GetDimensions()
{
    return dimensions;
}
