#include <iostream>
#include <fstream>
#include <utility>
#include <tuple>
#include <set>
#include <vector>

#define numOfTails 10

template <typename T,typename U>
std::pair<T,U> operator-(const std::pair<T,U> & l,const std::pair<T,U> & r) {
    return {l.first-r.first,l.second-r.second};
}

using namespace std;
vector<pair<int, int>> positions;
set<pair<int,int>> tailPositions;

void moveTail() {
    for (int i = 1; i < numOfTails; i++) {
        tailPositions.insert(positions[numOfTails - 1]);
        auto temp = positions[i] - positions[i-1];
        if (temp.second == 2) {
            if(temp.first == 2)
                positions[i] = {positions[i - 1].first +1, positions[i - 1].second + 1};
            else if(temp.first == -2)
                positions[i] = {positions[i - 1].first -1, positions[i - 1].second + 1};
            else
                positions[i] = {positions[i - 1].first, positions[i - 1].second + 1};
        }
        else if (temp.second == -2) {
            if(temp.first == 2)
                positions[i] = {positions[i - 1].first + 1, positions[i - 1].second - 1};
            else if(temp.first == -2)
                positions[i] = {positions[i - 1].first - 1, positions[i - 1].second - 1};
            else
                positions[i] = {positions[i - 1].first, positions[i - 1].second - 1};
        }
        else if (temp.first == 2)
        {
            positions[i] = {positions[i - 1].first + 1, positions[i - 1].second};
        } else if (temp.first == -2) {
            positions[i] = {positions[i - 1].first - 1, positions[i - 1].second};
        }
        else break;
    }
}

int main() {
    positions.resize(numOfTails);
    fill(positions.begin(),positions.end(),pair<int,int>{0,0});
    string input;
    fstream file;
    file.open("Day9.txt");
    tailPositions.insert(pair<int,int>(0,0));
    while(getline(cin, input)) {
        if (input == "x")
            break;
        char direction = input.at(0);
        int howMany = stoi(input.substr(input.find(' ') + 1, input.size() - 1));
        for (int i = 0; i < howMany; i++) {
            switch (direction) {
                case 'D':
                    positions[0].second--;
                    break;
                case 'U':
                    positions[0].second++;
                    break;
                case 'R':
                    positions[0].first++;
                    break;
                case 'L':
                    positions[0].first--;
                    break;
                default:
                    break;
            }
            moveTail();
        }
    }
    tailPositions.insert(positions[numOfTails-1]);
    std::cout << tailPositions.size() << std::endl;
    return 0;
}

