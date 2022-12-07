#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string arr[] = { "BVWTQNHD", "BWD", "CJWQST", "PTZNRJF", "TSMJVPG", "NTFWB", "NVHFQDLB", "RFPH", "HPNLBMSZ" };
	string input;
	fstream file;
	file.open("Day5.txt");
	while (getline(file, input))
	{
		input.erase(0, input.find(' ') + 1);
		int quantity, stack1, stack2;
		quantity = stoi(input.substr(0, input.find(' ')));
		input.erase(0, input.find(' ') + 1);
		input.erase(0, input.find(' ') + 1);
		stack1 = stoi(input.substr(0, input.find(' ')));
		input.erase(0, input.find(' ') + 1);
		input.erase(0, input.find(' ') + 1);
		stack2 = stoi(input.substr(0, input.find(' ')));
		input.clear();
		stack1--;
		stack2--;
		arr[stack2] = arr[stack1].substr(0, quantity) + arr[stack2];
		arr[stack1].erase(0, quantity);
	}
	file.close();
	for (auto i : arr)
	{
		cout << i[0];
	}
}