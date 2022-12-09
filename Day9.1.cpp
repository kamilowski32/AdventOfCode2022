#include <iostream>
#include <fstream>
#include <unordered_set>
#include <utility>
#include <tuple>
#include <set>

using namespace std;


pair<int, int> posH = {0, 0}, posT = {0, 0};

struct hashFunction
{
    size_t operator()(const pair<int , int> &x) const {
        return x.first^x.second;
    }
};

bool isTailNear() {
    if(abs(posH.first - posT.first) <= 1)
        if(abs(posH.second - posT.second) <= 1)
            return true;
    return false;
}

int main() {
    string input;
    fstream file;
    file.open("Day9.txt");
    set<pair<int,int>> tailPositions;
    tailPositions.insert(posT);
    while(getline(cin, input)) {
        if (input == "x")
            break;
        char direction = input.at(0);
        int howMany = stoi(input.substr(input.find(' ') + 1, input.size() - 1));
        for (int i = 0; i < howMany; i++) {
            switch (direction) {
                case 'D':
                    posH.second--;
                    isTailNear() ? (direction = 'D') : (posT.second = posH.second + 1, posT.first = posH.first);
                    tailPositions.insert(posT);
                    break;
                case 'U':
                    posH.second++;
                    isTailNear() ? (direction = 'U') : (posT.second = posH.second - 1, posT.first = posH.first);
                    tailPositions.insert(posT);
                    break;
                case 'R':
                    posH.first++;
                    isTailNear() ? (direction = 'R') : (posT.second = posH.second, posT.first = posH.first - 1);
                    tailPositions.insert(posT);
                    break;
                case 'L':
                    posH.first--;
                    isTailNear() ? (direction = 'L') : (posT.second = posH.second, posT.first = posH.first + 1);
                    tailPositions.insert(posT);
                    break;
                default:
                    break;
            }
        }

    }

    std::cout << tailPositions.size() << std::endl;
    return 0;
}
