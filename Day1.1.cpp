#include <iostream>
#include <string>
int main()
{
    long currElf = 0, max = 0;
    std::string currCalories;
    while (getline(std::cin, currCalories))
    {
        if (currCalories == "x")
            break;
        currCalories == "" ? (currElf > max ? max = currElf, currElf = 0 : currElf = 0) : (currElf += std::stol(currCalories));
    }
    std::cout << max;
}