.PHONY : program

CC := g++

FILES := main.o ConsoleMaze.o ConsoleMazeBlock.o Generate2dMazeInSquare.o GenerateCircleMaze.o Maze2d.o Maze2dGenerator.o QuadMazeGenerator.o RandomUint32Generator.o 

all : program

%.o : %.c
	$(CC) -c $< -o $@

program: $(FILES)
	$(CC) -std=c++11 -o maze $(FILES)
