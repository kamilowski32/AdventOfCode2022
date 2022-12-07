#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string input;
	vector<int> sizes;
	int sum = 0;
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
					if (temp <= 100000)
						sum += temp;
					sizes[sizes.size() - 1] += temp;
				}
			}
		}
		else if (input[0] == 'd')
		{

		}
		else if (input[0] >= '0' && input[0] <= '9')
		{
			string size = input.substr(0, input.find(' ') + 4);
			sizes[sizes.size() - 1] += stoi(size);
		}
	}
	plik.close();
	while(sizes.size()>1)
	{
		int temp = sizes[sizes.size() - 1];
		sizes.pop_back();
		if (temp <= 100000)
			sum += temp;
		sizes[sizes.size() - 1] += temp;
	}
	sizes.clear();
	cout << sum;
}