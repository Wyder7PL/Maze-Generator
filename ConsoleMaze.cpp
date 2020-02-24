#include "ConsoleMaze.hpp"

ConsoleMaze::ConsoleMaze(const Point<uint32_t> & mazeDimension,const Point<uint32_t> & blocksize)
:Maze2d(mazeDimension),blockSize(blocksize)
{
    for(uint32_t i = 0;i < mazeDimension.y;i++)
    {
        std::vector<std::shared_ptr<ConsoleMazeBlock>> Vector;
        for(uint32_t j = 0;j < mazeDimension.x;j++)
        {
            Vector.push_back(std::make_shared<ConsoleMazeBlock>());
        }
        blocks.push_back(std::move(Vector));
    }

    std::vector<std::vector<std::shared_ptr<MazeBlock>>> newBlocks;
    for(auto & i : blocks)
    {
        std::vector<std::shared_ptr<MazeBlock>> Vector;
        for(auto & j : i) Vector.push_back(j);
        newBlocks.push_back(std::move(Vector));
    }
    SetMazeBlocks(newBlocks);
}

void ConsoleMaze::DrawMaze(std::ostream & ios)
{
    for(auto & i : blocks)
    {
        for(uint32_t k = 0;k < blockSize.y;k++)
        {
            for(auto & j : i)
                ios << j->ReturnLine(k,blockSize);
            ios << "\n";
        }
    }
    ios << "\n";
}

void ConsoleMaze::DrawMazeDebug(std::ostream & ios)
{
    for(auto & i : blocks)
    {
        for(uint32_t k = 0;k < blockSize.y;k++)
        {
            for(auto & j : i)
            {
                ios << j->ReturnLine(k,blockSize);
                ios << " ";
            }
            ios << "\n" ;
        }
        ios << "\n";
    }
    ios << "\n";
}

