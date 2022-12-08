#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	fstream file;
	file.open("Day8.txt");
	vector<string> trees;
	string temp;
	while (getline(file, temp))
	{
		trees.push_back(temp);
	}
	file.close();
	int size = trees.size();

    int maximum = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int currTree = trees[i][j] -'0';
            int up = 0, down = 0, left = 0, right = 0;
            for (int u = i - 1; u >= 0; u--) // up
            {
                up++;
                if (trees[u][j] - '0' >= currTree) break;
            }
            for (int d = i + 1; d < size; d++) // down
            {
                down++;
                if (trees[d][j] - '0' >= currTree) break;
            }
            for (int l = j - 1; l >= 0; l--) // left
            {
                left++;
                if (trees[i][l] - '0' >= currTree) break;
            }
            for (int r = j + 1; r < size; r++) // right
            {
                right++;
                if (trees[i][r] - '0' >= currTree) break;
            }
            int currScore = up * down * left * right;
            if (currScore > maximum)
            {
                maximum = currScore;
            }
        }
    }
	cout << maximum << endl;
}