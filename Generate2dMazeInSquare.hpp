#pragma once

#include "Maze2dGenerator.hpp"


using Uint32x2 = Point <uint32_t>;

class Generate2dMazeInSquare : public Maze2dGenerator
{
public:
    void SetAreaForMazeGenerating(Uint32x2 from,Uint32x2 to);
protected:
    virtual bool CheckIfPointNearBorder(Uint32x2 point,Directions d) override;
private:
    Uint32x2 mazeOffset=Uint32x2(0,0);
    Uint32x2 mazeSize=Uint32x2(0,0);
};
