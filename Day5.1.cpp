#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string arr[] = { "BVWTQNHD", "BWD", "CJWQST", "PTZNRJF", "TSMJVPG", "NTFWB", "NVHFQDLB", "RFPH", "HPNLBMSZ" };
	string input;
	while (getline(cin, input))
	{
		if (input == "x")
			break;
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
		string added = arr[stack1].substr(0, quantity);
		reverse(added.begin(), added.end());
		arr[stack2] = added + arr[stack2];
		arr[stack1].erase(0, quantity);
	}
	for (auto i : arr)
	{
		cout << i[0];
	}
}