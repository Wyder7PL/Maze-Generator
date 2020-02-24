#include <iostream>
#include <vector>
#include <memory>

#include "ConsoleMaze.hpp"
#include "QuadMazeGenerator.hpp"
#include "GenerateCircleMaze.hpp"

int main()
{
	{
	std::cout << "Regular maze:\n";
	ConsoleMaze coma(Point<uint32_t>(8,8),Point<uint32_t>(5,3));
        auto gen = std::make_shared<Generate2dMazeInSquare>();
	gen->SetAreaForMazeGenerating(Uint32x2(0,0),Uint32x2(8,8));
        gen->GenerateMaze(coma);
        coma.DrawMaze(std::cout);
	}
    {
	std::cout << "Four mazes merged into one:\n";
        ConsoleMaze coma(Point<uint32_t>(15,15),Point<uint32_t>(5,3));
        auto gen = std::make_shared<QuadMazeGenerator>();
        gen->GenerateMaze(coma);
        coma.DrawMaze(std::cout);
    }
    {
	std::cout << "Circle maze:\n";
        ConsoleMaze coma(Point<uint32_t>(25,25),Point<uint32_t>(3,3));
        auto gen = std::make_shared<GenerateCircleMaze>();
        gen->GenerateMaze(coma);
        coma.DrawMaze(std::cout);
    }
    return 0;
}
