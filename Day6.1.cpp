#include <iostream>

using namespace std;

bool anySame(char c1, char c2, char c3, char c4)
{
    return c1 == c2 || c1 == c3 || c1 == c4 || c2 == c3 || c2 == c4 || c3 == c4;
}

int main()
{
    string input;
    cin >> input;
    char c1 = input.at(0), c2 = input.at(1), c3 = input.at(2), c4 = input.at(3);
    int i = 4;
    while (anySame(c1, c2, c3, c4))
    {
        i++;
        c1 = c2;
        c2 = c3;
        c3 = c4;
        c4 = input.at(i - 1);
    }
    cout << i << endl;
}