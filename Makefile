.PHONY : program

CC := g++

all : program

%.o : %.c
	$(CC) -c $< -o $@

program: main.o ConsoleMaze.o ConsoleMazeBlock.o Directions.o Generate2dMazeInSquare.o GenerateCircleMaze.o Maze2d.o Maze2dGenerator.o QuadMazeGenerator.o RandomUint32Generator.o 
	$(CC) -std=c++11 -o maze main.o ConsoleMaze.o ConsoleMazeBlock.o Directions.o Generate2dMazeInSquare.o GenerateCircleMaze.o Maze2d.o Maze2dGenerator.o QuadMazeGenerator.o RandomUint32Generator.o 
