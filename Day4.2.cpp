#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	int howMany = 0;
	while (true)
	{
		string input;
		cin >> input;
		if (input == "x")
			break;
		int begin1, begin2, end1, end2;
		begin1 = stoi(input.substr(0, input.find('-')));
		input.erase(0, input.find('-') + 1);
		end1 = stoi(input.substr(0, input.find(',')));
		input.erase(0, input.find(',') + 1);
		begin2 = stoi(input.substr(0, input.find('-')));
		input.erase(0, input.find('-') + 1);
		end2 = stoi(input);
		if (begin1 < begin2)
		{
			if (end1 >= begin2)	howMany++;
		}
		else if (begin2 < begin1)
		{
			if (end2 >= begin1)	howMany++;
		}
		else
		{
			howMany++;
		}
	}
	cout << howMany;
}