#include <iostream>
#include <string>
#include <fstream>
int main()
{
    std::fstream file;
    file.open("Day1.txt");
    long currElf = 0, top1 = 0, top2 = 0, top3 = 0, temp;
    std::string currCalories;
    while (getline(file, currCalories))
    {
        if (currCalories == "")
            currElf > top3 ? (currElf > top2 ? (currElf > top1 ? (top3 = top2, top2 = top1, top1 = currElf, currElf = 0) : (top3 = top2, top2 = currElf, currElf = 0)) : (top3 = currElf, currElf = 0)) : (currElf = 0);
        else
            currElf += std::stol(currCalories);
    }
    file.close();
    std::cout << top1 + top2 + top3;
}