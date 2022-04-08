#include <iostream>
#include <vector>
#include <string>
using namespace std;

class maze {
	int height;
	int width;
	int* cells;
	int startPos;

	char neighbor(int pos) const;
	void mazeGen();
public:

	// Generates a maze of given height and width (using recursive back-tracking algorithm)
	maze(int height, int width);
	~maze();
	// Prints the maze with ascii block characters 
	void mazePrint() const;
};
