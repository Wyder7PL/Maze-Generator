#include "Maze2dGenerator.hpp"

Maze2dGenerator::Maze2dGenerator()
{
    randGenerator.RandomizeGenerator();
}

void Maze2dGenerator::GenerateMaze(Maze2d & maze,const Uint32x2 &startingPoint)
{
    std::stack<Uint32x2> pathToStart;
    Uint32x2 ItIsNotBechindMazeArea = Uint32x2(std::min(startingPoint.x,maze.GetDimensions().x-1),std::min(startingPoint.y,maze.GetDimensions().y-1));
    pathToStart.push( std::move(ItIsNotBechindMazeArea) );

    while(!pathToStart.empty())
    {
        auto currentPoint = pathToStart.top();
        auto possibilities = GetPossibleAdjacentBlocks(maze,currentPoint);
        if(possibilities.empty())
            pathToStart.pop();
        else
        {
            uint32_t randomDirection = randGenerator.GenerateRandomInRange(0,possibilities.size()-1);
            Directions NextBlock = possibilities[randomDirection];
            maze.SetWallStatus(NextBlock,currentPoint, false);
            maze.SetWallStatus((Directions)((NextBlock+2)%4),MovePoint(currentPoint,NextBlock), false);
            pathToStart.push(MovePoint(currentPoint,NextBlock));
        }
    }
}

bool Maze2dGenerator::CheckIfBlockWasModified(Maze2d & maze,Uint32x2 point)
{
    if(maze.GetWallStatus(NORTH, point)==false) return true;
    if(maze.GetWallStatus(EAST, point)==false) return true;
    if(maze.GetWallStatus(SOUTH, point)==false) return true;
    if(maze.GetWallStatus(WEST, point)==false) return true;
    return false;
}

Uint32x2 Maze2dGenerator::MovePoint(Uint32x2 p,Directions d)
{
    Uint32ToBool con;
    return Uint32x2(p.x+1*con(d!=3)-1*con(d!=1), p.y+1*con(d!=0)-1*con(d!=2));
}

std::vector<Directions> Maze2dGenerator::GetPossibleAdjacentBlocks(Maze2d & maze,Uint32x2 point)
{
    std::vector<Directions> adjacentPoints;
    if(!CheckIfPointNearBorder(point,NORTH) && !CheckIfBlockWasModified(maze,Uint32x2(point.x,point.y-1)))
        adjacentPoints.push_back(NORTH);
    if(!CheckIfPointNearBorder(point,EAST) && !CheckIfBlockWasModified(maze,Uint32x2(point.x+1,point.y)))
        adjacentPoints.push_back(EAST);
    if(!CheckIfPointNearBorder(point,SOUTH) && !CheckIfBlockWasModified(maze,Uint32x2(point.x,point.y+1)))
        adjacentPoints.push_back(SOUTH);
    if(!CheckIfPointNearBorder(point,WEST) && !CheckIfBlockWasModified(maze,Uint32x2(point.x-1,point.y)))
        adjacentPoints.push_back(WEST);
    return adjacentPoints;
}
