#include <iostream>
#include <string>
#include "myfunc.h"

using namespace std;

int main(){



	char* p1 = "X";
	char* p2 = "O";

	int turn = 0;
	string input;
	char* map[3][3];
	setClearMap(map);

	while (true)
	{
		cout << "Turn: " << turn << endl;
		// Render game map
		for (int y = 0; y < 3; y++)
		{
			string row = "";
			for (int x = 0; x < 3; x++)
			{
				if (x == 0)
				switch (y)
				{
				case 0:
					row += "A:";
					break;
				case 1:
					row += "B:";
					break;
				case 2:
					row += "C:";
					break;
				}

				row += *map[x][y];
			}
			if (y == 0)
				cout << "  123" << endl;
			cout << row << endl;
		}
		// User input
		cin >> input;
		cout << ":" << input << endl;

		if (isEqual(input, "restart"))
		{
			setClearMap(map);
			turn = 0;
			continue;
		}

		// Valid input?
		if (input.length() == 2)
		{
			// Marker
			char* marker;
			if (turn % 2 == 0){
				marker = p1;
				cout << "Player 1" << endl;
			}
			else
			{
				marker = p2;
				cout << "Player 2" << endl;
			}

			// horizontal X
			string num = input.substr(1, 2);
			int x = 0;
			x = atoi(num.c_str());
			x--;
			if (x == -1)
			{
				cout << "Invalid X" << endl;
				continue;
			}

			// Vertical y
			int y = 0;
			if (isEqual(input.substr(0, 1), "A"))
				y = 0;
			else if (isEqual(input.substr(0, 1), "B"))
				y = 1;
			else if (isEqual(input.substr(0, 1), "C"))
				y = 2;
			else
			{
				cout << "Invalid Y" << endl;
				continue;
			}

			// Check collision
			if (map[x][y] != "*")
			{
				cout << "There is already a marker!\nTry again" << endl;
				continue;
			}


			map[x][y] = marker;
			turn++;
			system("cls");
		}
		else
			cout << "Not valid input. Letter / Number" << endl;
	}

	return 0;
}