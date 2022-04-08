#include "maze.h"


maze::maze(int h, int w) : height{ h }, width{ w } {
	if (height < 1) height = 1;
	if (width < 1) width = 1;
	cells = new int[height * width];
	for (int i = 0; i < (height * width); ++i) {
		cells[i] = 0;
	}
	
	startPos = rand() % (width * height);
	mazeGen();
}
maze::~maze() {
	delete[] cells;
}
void maze::mazeGen() {
	vector<int> path;
	int curPos = startPos;
	int oldPos = 0;
	path.emplace_back(startPos);

	while (!(path.empty())) {
		oldPos = curPos;
		switch (neighbor(curPos)) {
		case 'U':
			curPos -= width;
			cells[curPos] += 100;
			cells[oldPos] += 1;
			break;
		case 'D':
			curPos += width;
			cells[curPos] += 1;
			cells[oldPos] += 100;
			break;
		case 'L':
			curPos -= 1;
			cells[curPos] += 10;
			cells[oldPos] += 1000;
			break;
		case 'R':
			curPos += 1;
			cells[curPos] += 1000;
			cells[oldPos] += 10;
			break;
		case 'N':
			path.pop_back();
			if (!(path.empty())) curPos = path.back();
			continue;
		}
		path.emplace_back(curPos);
	}
}

char maze::neighbor(int pos) const {
	vector<char> dir;

	// Determine all possible direction we have move in
	if ((pos - width) >= 0)
		if (cells[pos - width] == 0) dir.push_back('U');
	if ((pos + width) < (width * height))
		if (cells[pos + width] == 0) dir.push_back('D');
	if ((pos % width) != (width - 1))
		if (cells[pos + 1] == 0) dir.push_back('R');
	if ((pos % width) != 0)
		if (cells[pos - 1] == 0) dir.push_back('L');

	// return token value of N if no possible directions
	if (dir.empty()) return 'N';

	// Pick a direction at random
	return dir[rand() % dir.size()];
}

void maze::mazePrint() const {
	char b = char(219); // a bloack charactor

	// prints the maze
	for (int y = 0; y < height; ++y) {
		cout << b;
		// add walls above the cell
		for (int x = 0; x < width; ++x) {
			if ((cells[(y * width) + x] % 10) == 0) {
				cout << b << b << b;
			} else {
				cout << "  " << b;
			}
		}
		cout << "\n" << b;
		// add walls to the right of the cell
		for (int x = 0; x < width; ++x) {
			if ((cells[(y * width) + x] % 100) < 9) {
				cout << "  " << b;
			}
			else {
				cout << "   ";
			}
		}
		cout << "\n";
	}
	// print out floor
	cout << b;
	for (int x = 0; x < width; ++x) {
		cout << b << b<< b;
	}
}

