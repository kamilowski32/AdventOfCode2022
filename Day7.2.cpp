#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string input;
	vector<int> sizes, sizes2;
	int sum = 0, free = 70000000, currMin = 30000000;
	ifstream plik;
	plik.open("Day7.txt");
	while (getline(plik, input))
	{
		if (input[0] == '$')
		{
			if (input[2] == 'c')
			{
				if (input[5] != '.')
				{
					sizes.push_back(0);
				}
				else
				{
					int temp = sizes[sizes.size() - 1];
					sizes.pop_back();
					sizes[sizes.size() - 1] += temp;
					sizes2.push_back(temp);
				}
			}
		}
		else if (input[0] >= '0' && input[0] <= '9')
		{
			string size = input.substr(0, input.find(' ') + 4);
			sizes[sizes.size() - 1] += stoi(size);
		}
	}
	plik.close();
	while (sizes.size() > 1)
	{
		int temp = sizes[sizes.size() - 1];
		sizes.pop_back();
		sizes[sizes.size() - 1] += temp;
		sizes2.push_back(temp);
	}
	free -= sizes[0];
	sizes.clear();
	for (auto i : sizes2)
	{
		if (i + free > 30000000 && i < currMin)
		{
			currMin = i;
		}
	}
	cout << currMin;
}