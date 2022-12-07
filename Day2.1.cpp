#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    fstream file;
    file.open("Day2.txt");
    int score = 0;
    char player, elf;
    string helper;
    while (getline(file, helper))
    {
        elf = helper[0];
        player = helper[2];
        switch (player)
        {
        case 'X':
            score += 1;
            switch (elf)
            {
            case 'A':
                score += 3;
                break;
            case 'B':
                break;
            case 'C':
                score += 6;
                break;
            }
            break;
        case 'Y':
            score += 2;
            switch (elf)
            {
            case 'A':
                score += 6;
                break;
            case 'B':
                score += 3;
                break;
            case 'C':
                break;
            }
            break;
        case 'Z':
            score += 3;
            switch (elf)
            {
            case 'A':
                break;
            case 'B':
                score += 6;
                break;
            case 'C':
                score += 3;
                break;
            }
            break;
        }
    }
    file.close();
    cout << score;
}