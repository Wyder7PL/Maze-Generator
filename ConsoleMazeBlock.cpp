#include "ConsoleMazeBlock.hpp"


ConsoleMazeBlock::ConsoleMazeBlock() {WallFlags = 15;}
ConsoleMazeBlock::ConsoleMazeBlock(uint32_t wallflag) {WallFlags = wallflag;}

ConsoleMazeBlock::~ConsoleMazeBlock() {}

std::string ConsoleMazeBlock::AsteriskOrSpace(const bool & asterisk)
{
    return (asterisk ? "*" : " ");
}

std::string ConsoleMazeBlock::ReturnLine(const uint32_t & line,const Point<uint32_t> & dimensions)
{
    Point<uint32_t> newDimensions(std::max(uint32_t(3),dimensions.x),std::max(uint32_t(3),dimensions.y));
    std::string returnline;
    for(uint32_t i = 0; i < newDimensions.x;i++)
    {
        if((line == 0 || line == newDimensions.y-1) && (i == 0 || i == newDimensions.x-1))
        {
            returnline += "*";
            continue;
        }
        if(line == 0) returnline += AsteriskOrSpace((WallFlags>>NORTH)%2);
        else if(i == newDimensions.x-1) returnline += AsteriskOrSpace((WallFlags>>EAST)%2);
        else if(line == newDimensions.y-1) returnline += AsteriskOrSpace((WallFlags>>SOUTH)%2);
        else if(i == 0) returnline += AsteriskOrSpace((WallFlags>>WEST)%2);
        else if (WallFlags == 15)   returnline += "*";
        else returnline += " ";
    }
    return returnline;
}

void ConsoleMazeBlock::SetWall(Directions wall,bool state)
{
    Uint32ToBool convert;
    int wallbit = (WallFlags>>wall)%2;
    if(wallbit==convert(state)) return;
    WallFlags += (1<<wall)* (-1+convert(state));
}
bool ConsoleMazeBlock::CheckForWall(Directions wall)
{
    return ((WallFlags>>wall)%2==1 ? true : false);
}
