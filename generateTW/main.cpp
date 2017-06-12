#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::flush;
using std::atoi;
using std::snprintf;

int main(int argc, char** argv)
{
	vector<int> vertexOp = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<string> edgeOp;
	for (size_t i = 0; i < 10; ++i)
	{
		for (size_t j = 0; j < 10; ++j)
		{
			if (j != i)
			{
				char opStr[3] = "";
				snprintf(opStr, 3, "%d%d", i, j);
				edgeOp.push_back(opStr);
			}
		}
	}

	//cout << "please input the treewidth and the vertices number: " << endl;

	int width = atoi(argv[1]);
	int vertices = atoi(argv[2]);
	//cin >> width;
	//cin >> vertices;

	cout << width << " " << "( ";
	int vertexCount = 0;
	int j = 0;
	int k = 0;
	while (vertexCount < vertices - width - 1)
	{
		for (size_t i = 0; i < width + 1; ++i)
		{
			cout << vertexOp[i] << " ";
			++vertexCount;
		}
		j %= (width + 1);
		k = (k + 1) % width;
		cout << edgeOp[9 * j + k] << " ";

		++j;
		++k;
	}

	cout << ")\n" << flush;
}