#pragma once

#include <string>

#include "Point.hpp"
#include "MazeBlock.hpp"
#include "Uint32ToBool.hpp"

class ConsoleMazeBlock : public MazeBlock
{
    std::string AsteriskOrSpace(const bool & asterisk);
public:
    ConsoleMazeBlock();
    ConsoleMazeBlock(uint32_t);
    virtual ~ConsoleMazeBlock();
    virtual void SetWall(Directions wall,bool state) override;
    virtual bool CheckForWall(Directions wall) override;
    std::string ReturnLine(const uint32_t & line,const Point<uint32_t> & dimensions );

protected:

};
