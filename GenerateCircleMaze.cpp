#include "GenerateCircleMaze.hpp"

void GenerateCircleMaze::GenerateMaze(Maze2d&maze,const Uint32x2 & startingPoint)
{
    center = Point<float>(maze.GetDimensions().x/2.0-0.5,maze.GetDimensions().x/2.0-0.5);
    radius = (center.x+center.y)/2.0;
    Maze2dGenerator::GenerateMaze(maze,Uint32x2(static_cast<uint32_t>(center.x),static_cast<uint32_t>(center.y)));
}

bool GenerateCircleMaze::CheckIfPointNearBorder(Uint32x2 point,Directions d)
{
    float distance = pow( pow(center.x-point.x,2.0)+pow(center.y-point.y,2.0),0.5)*1.0;
    if(distance < radius) return false;
    return true;
}
