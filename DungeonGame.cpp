// DivideTwoIntegers.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "DungeonGame1.h"

using namespace std;

int main(int argc, char* argv[])
{
    Solution solution;

    vector<vector<int>> dungeon;

    dungeon.push_back({ -2, -3, 3 });
    dungeon.push_back({ -5, -10, 1 });
    dungeon.push_back({ 10, 30, -5 });

    for (int i = 0; i < dungeon.size(); i++)
    {
        for (int j = 0; j < dungeon[i].size(); j++)
        {
            cout << dungeon[i][j] << " ";
        }
        cout << "\r\n";
    }

    int result = solution.DungeonGame(dungeon);
    cout << result << "\r\n";

	return 0;
}

