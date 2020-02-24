#pragma once

#include "Directions.hpp"

class MazeBlock
{
public:
    virtual ~MazeBlock(){}
    virtual void SetWall(Directions wall,bool state)=0;
    virtual bool CheckForWall(Directions wall)=0;
protected:
    uint32_t WallFlags;
};
