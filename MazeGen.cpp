#include <iostream>
#include "maze.h"
#include <time.h>
using namespace std;

int main() {

	int w, h;

	while (true) {
		cout << "Enter the width of the maze (as an integer): ";
		cin >> w;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} else {
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}
	while (true) {
		cout << "Enter the height of the maze (as an integer): ";
		cin >> h;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			break;
		}
	}
	srand(time(0));
	maze m = maze(h, w);
	m.mazePrint();
}
