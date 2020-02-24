#pragma once

#include "Point.hpp"
#include "Maze2dGenerator.hpp"


using Uint32x2 = Point <uint32_t>;

class GenerateCircleMaze : public Maze2dGenerator
{
public:
    virtual void GenerateMaze(Maze2d&maze,const Uint32x2 & startingPoint=Uint32x2(0,0));
protected:
    virtual bool CheckIfPointNearBorder(Uint32x2 point,Directions d) override;
private:
    Point<float> center=Point<float>(0.0,0.0);
    float radius;
};

