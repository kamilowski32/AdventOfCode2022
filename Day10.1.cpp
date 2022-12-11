#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string input;
    fstream file;
    file.open("Day10.txt");
    vector<int> valueX={0, 1};
    while(getline(file, input))
    {
        int back = valueX.back();
        valueX.push_back(back);
        if(input[0] == 'a')
        {
            valueX.push_back(back+stoi(input.substr(input.find(' ') + 1, input.size()-1)));        }
    }
    cout << valueX[20]*20 + valueX[60]*60 + valueX[100]*100 + valueX[140]*140 + valueX[180] * 180 + valueX[220]*220 << endl;
file.close();
}

