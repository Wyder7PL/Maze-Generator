#pragma once

#include <vector>
#include <stack>

#include "Maze2d.hpp"
#include "Point.hpp"
#include "RandomUint32Generator.hpp"
#include "Uint32ToBool.hpp"

using Uint32x2 = Point <uint32_t>;

class Maze2dGenerator
{

public:
    Maze2dGenerator();
    virtual void GenerateMaze(Maze2d & maze,const Uint32x2 &startingPoint = Uint32x2(0,0));
protected:
    virtual bool CheckIfPointNearBorder(Uint32x2 point,Directions d)=0;
private:
    Uint32x2 MovePoint(Uint32x2 p,Directions d);
    bool CheckIfBlockWasModified(Maze2d & maze,Uint32x2 point);
    std::vector<Directions> GetPossibleAdjacentBlocks(Maze2d & maze,Uint32x2 point);

    RandomUint32Generator randGenerator;
};
