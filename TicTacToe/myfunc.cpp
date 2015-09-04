#include <algorithm>
#include "myfunc.h"


bool isEqual(std::string val1, std::string val2)
{
	std::transform(val1.begin(), val1.end(), val1.begin(), ::tolower);
	std::transform(val2.begin(), val2.end(), val2.begin(), ::tolower);
	return val1 == val2;
}

void setClearMap(char* map[3][3])
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			map[x][y] = "*";
		}
	}
}