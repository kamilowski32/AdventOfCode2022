#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int valueOfChar(char sameLetter)
{
	if (sameLetter >= 'A' && sameLetter <= 'Z')
		return (int)sameLetter - 38;
	return (int)sameLetter - 96;
}


void remove(vector<char>& vect, const char& elem)
{
	vect.erase(remove(vect.begin(), vect.end(), elem), vect.end());
}

int main() {
	vector<char> commonLetters;
	string input;
	int sum = 0;
	while (getline(cin, input)) //first line
	{
		if (input == "x")
			break;
		string secondInput;
		getline(cin, secondInput); //secondline
		for (auto i : input)
		{
			if (secondInput.find(i) != string::npos)
			{
				commonLetters.push_back(i);
			}
		}
		getline(cin, secondInput); //thirdLine
		for (auto i : input)
		{
			if (secondInput.find(i) == string::npos)
			{
				remove(commonLetters, i);
			}
		}
		sum += valueOfChar(commonLetters[0]);
		commonLetters.clear();
	}
	cout << sum;
}