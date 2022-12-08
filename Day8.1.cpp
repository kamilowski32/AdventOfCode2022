#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	fstream file;
	file.open("Day8.txt");
	vector<string> trees;
	string temp;
	int sum = 0;
	while (getline(file, temp))
	{
		trees.push_back(temp);
	}
	file.close();
	int size = trees.size();
	bool** isItVisible = new bool* [size];
	for (int i = 0; i < size; i++)
	{
		isItVisible[i] = new bool[size];
		for (int j = 0; j < size; j++)
			isItVisible[i][j] = false;
	}


	int currMax = -1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int temp = trees[i][j] - '0';
			if (temp > currMax)
			{
				currMax = temp;
				isItVisible[i][j] = true;
			}
		}
		currMax = -1;
		for (int j = size - 1; j >= 0; j--)
		{
			int temp = trees[i][j] - '0';
			if (temp > currMax)
			{
				currMax = temp;
				isItVisible[i][j] = true;
			}
		}
		currMax = -1;
	}
	currMax = -1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int temp = trees[j][i] - '0';
			if (temp > currMax)
			{
				currMax = temp;
				isItVisible[j][i] = true;
			}
		}
		currMax = -1;
		for (int j = size - 1; j >= 0; j--)
		{
			int temp = trees[j][i] - '0';
			if (temp > currMax)
			{
				currMax = temp;
				isItVisible[j][i] = true;
			}
		}
		currMax = -1;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			if (isItVisible[j][i])
				sum++;
	}
	for (int i = 0; i < size; i++)
	{
		delete[] isItVisible[i];
	}
	delete[] isItVisible;
	cout << sum << endl;
}