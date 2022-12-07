#include <iostream>
#include <string>
#include <fstream>
int main()
{
    std::fstream file;
    file.open("Day1.txt");
    long currElf = 0, max = 0;
    std::string currCalories;
    while (getline(file, currCalories))
    {
        currCalories == "" ? (currElf > max ? max = currElf, currElf = 0 : currElf = 0) : (currElf += std::stol(currCalories));
    }
    file.close();
    std::cout << max;
}