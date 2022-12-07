#include <iostream>
#include <string>
#include <fstream>
using namespace std;
char sameLetter;

int valueOfChar()
{
	if (sameLetter >= 'A' && sameLetter <= 'Z')
		return (int)sameLetter - 38;
	return (int)sameLetter - 96;
}


int main() {
	string input;
	int sum = 0;
	fstream file;
	file.open("Day3.txt");
	while (getline(file, input))
	{
		int mid = (input.length() + 1) / 2;
		string firstPart = input.substr(0, mid);
		string secondPart = input.substr(mid);
		for (auto i : firstPart)
		{
			if (secondPart.find(i) != string::npos)
			{
				sameLetter = i;
				break;
			}
		}
		sum += valueOfChar();
	}
	file.close();
	cout << sum;
}