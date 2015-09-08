/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 09/06/2015
Notes:
    Dragon Challenge
    You are the hero in our story and you have been given a quest¡ªto get through a canyon of nasty dragons. As a hero, you have a special skill¡ªyou can fly for short distances. Your strategy is to fly as quickly as possible through the canyon, touching down as few times as you can, never touching down on a dragon, as that leads to your immediate death.
    The canyon is represented as an array of non-negative integers. You are at the starting point in the canyon. This is the first element of the array. The value of that first array element indicates the maximum index of your first flight. You can fly forward in the array at most that many elements before you must land. Array locations containing a zero indicate the presence of a dragon.
    Here is an example canyon array:
    [5, 6, 0, 4, 2, 4, 1, 0, 0, 4]
    You will develop and implement an algorithm to traverse the array in the shortest number of ¡°flights¡± starting at index 0, where traversal is defined as follows:
    ? Start at the first (0th) index of the array, look at the array value there, and you can fly forward to any array index that is no farther than that value away. So in this example, you start at index 0 containing the value 5 and can now consider flying to any of indices 1 through 5 inclusive.
    ? If you choose to fly to index 3, it contains the value 4 and you can next fly up to 4 more spots from your current index (3)¡ªso you now consider indices 4 through 7 as next length in your sequence.
    ? Once you can legally fly beyond the last array element, you have successfully traversed the canyon and have completed the quest.
    Your job is to compute the minimum-index sequence of flights that successfully traverses the canyon starting from index 0, or determine that there is no such sequence. If there are multiple solutions with the same number of flights, you can choose one arbitrarily as the answer.
    Your program will implement the algorithm and write a solution to the standard output stream on a single line identifying the array indices that comprise a solution path, with the indices separated by commas.
    For this example, the following would be valid output:
    0, 5, 9, out
    (Note that your output is a sequence of array indices, not a sequence of flight lengths and this line is terminated with a newline character.)
    Your program may be written in the language of your choice. It must accept from STDIN the array to be solved.
    STDIN will contain the array for a single problem.
    The STDIN will contain one integer per line, with no brackets or commas.
    The input array will eventually be large in our testing, so performance is important.
    If there is no solution or if the input is malformed, the program should write the string ¡°failure¡± to STDOUT, followed by a newline character. Under no circumstance should your program throw unhandled exceptions.
Solution:
	1. DFS.
    2. Calculate backward
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    Solution()
    {
    }

    ~Solution()
    {
    }

    vector<int> DragonChallenge(vector<int> valley)
    {
        // Shortest flight out of valley from each point in valley
        vector<vector<int>> flights;

        if (valley.size() == 0)
        {
            vector<int> flight;
            return flight;
        }

        // Initialize with empty flights
        for (int i = 0; i < valley.size(); i++)
        {
            vector<int> flight;
            flights.push_back(flight);
        }

        // Finid shortest flight starting at end of valley
        for (int i = valley.size() - 1; i >= 0; i--)
        {
            if (valley[i] == 0)
            {
                // Landed on a dragon
                continue;
            }
            else if (i == valley.size() - 1)
            {
                // At end of valley
                flights[i].push_back(i);
            }
            else
            {
                int length = 0;
                int index = 0;
                int min = valley.size() - i;

                for (index = valley[i]; index > 0 ; index--)
                {
                    if (i + index >= valley.size())
                    {
                        // Out of valley
                        flights[i].push_back(i);
                        break;
                    } if (flights[i + index].size() == 0)
                    {
                        // Next stop is dragon
                        continue;
                    }
                    else
                    {
                        if (1 + flights[i + index].size() <= min)
                        {
                            length = index;
                            min = 1 + flights[i + index].size();
                        }
                    }
                }

                // Found minimum length needed to fly out of valley from current point
                if (length > 0)
                {
                    flights[i] = flights[i + length];
                    flights[i].push_back(i);
                }
            }
        }

        vector<int> solution = flights[0];

        reverse(solution.begin(), solution.end());

        return solution;
    }
};
