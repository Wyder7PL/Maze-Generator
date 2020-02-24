#include "Generate2dMazeInSquare.hpp"

bool Generate2dMazeInSquare::CheckIfPointNearBorder(Uint32x2 point,Directions d)
{
    switch(d)
    {
    case NORTH:
        return point.y <= mazeOffset.y;
    case EAST:
        return point.x >= mazeSize.x-1;
    case SOUTH:
        return point.y >= mazeSize.y-1;
    case WEST:
        return point.x <= mazeOffset.x;
    }
    return false;
}

void Generate2dMazeInSquare::SetAreaForMazeGenerating(Uint32x2 from,Uint32x2 to)
{
    mazeOffset=from;
    mazeSize=to;
}
