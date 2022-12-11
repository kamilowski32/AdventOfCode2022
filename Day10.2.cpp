#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string str = "";
    string input;
    fstream file;
    file.open("Day10.txt");
    vector<int> valueX = {1};
    int cycle = 0;
    while (getline(file, input)) {
        cycle++;
        int back = valueX.back();
        valueX.push_back(back);
        if (input == "x")
            break;
        else if (input[0] == 'a') {
            valueX.push_back(back + stoi(input.substr(input.find(' ') + 1, input.size() - 1)));
        }
    }
    file.close();
    std::vector<std::string> output(6, std::string(40, '.'));
    for (int r = 0; r < 6; r++)
        for (int c = 0; c < 40; c++) {
            abs(valueX.at(40 * r + c) - c) <= 1 ? output.at(r).at(c) = '#' : c = c;
        }
    for(auto& i : output)
    {
        cout << i << endl;
    }
}

