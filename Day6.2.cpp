#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool anySame(vector<short> vect)
{
    for (auto i : vect)
    {
        if (i > 1)
            return true;
    }
    return false;
}

int main()
{
    fstream file;
    file.open("Day6.txt");
    string input;
    file >> input;
    file.close();
    vector<short> vect;
    vect.resize(26);
    for (int iter = 0; iter < 14; iter++)
    {
        vect[(int)input.at(iter) - 97]++;
    }
    int i = 14;
    while (anySame(vect))
    {
        i++;
        vect[input.at(i - 15) - 97]--;
        vect[input.at(i - 1) - 97]++;
    }
    cout << i << endl;
}