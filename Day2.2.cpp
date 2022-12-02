#include <iostream>
#include <string>
using namespace std;

int main()
{
    int score = 0;
    char player, elf;
    string helper;
    while (getline(cin, helper))
    {
        if (helper == "x")
            break;
        elf = helper[0];
        player = helper[2];
        switch (player)
        {
        case 'X':
            switch (elf)
            {
            case 'A':
                score += 3;
                break;
            case 'B':
                score += 1;
                break;
            case 'C':
                score += 2;
                break;
            }
            break;
        case 'Y':
            score += 3;
            switch (elf)
            {
            case 'A':
                score += 1;
                break;
            case 'B':
                score += 2;
                break;
            case 'C':
                score += 3;
                break;
            }
            break;
        case 'Z':
            score += 6;
            switch (elf)
            {
            case 'A':
                score += 2;
                break;
            case 'B':
                score += 3;
                break;
            case 'C':
                score += 1;
                break;
            }
            break;
        }
    }
    cout << score;
}