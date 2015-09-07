/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 09/06/2015
Notes:
    Dragon Challenge
    You are the hero in our story and you have been given a quest��to get through a canyon of nasty dragons. As a hero, you have a special skill��you can fly for short distances. Your strategy is to fly as quickly as possible through the canyon, touching down as few times as you can, never touching down on a dragon, as that leads to your immediate death.
    The canyon is represented as an array of non-negative integers. You are at the starting point in the canyon. This is the first element of the array. The value of that first array element indicates the maximum length of your first flight. You can fly forward in the array at most that many elements before you must land. Array locations containing a zero indicate the presence of a dragon.
    Here is an example canyon array:
    [5, 6, 0, 4, 2, 4, 1, 0, 0, 4]
    You will develop and implement an algorithm to traverse the array in the shortest number of ��flights�� starting at index 0, where traversal is defined as follows:
    ? Start at the first (0th) index of the array, look at the array value there, and you can fly forward to any array index that is no farther than that value away. So in this example, you start at index 0 containing the value 5 and can now consider flying to any of indices 1 through 5 inclusive.
    ? If you choose to fly to index 3, it contains the value 4 and you can next fly up to 4 more spots from your current index (3)��so you now consider indices 4 through 7 as next steps in your sequence.
    ? Once you can legally fly beyond the last array element, you have successfully traversed the canyon and have completed the quest.
    Your job is to compute the minimum-length sequence of flights that successfully traverses the canyon starting from index 0, or determine that there is no such sequence. If there are multiple solutions with the same number of flights, you can choose one arbitrarily as the answer.
    Your program will implement the algorithm and write a solution to the standard output stream on a single line identifying the array indices that comprise a solution path, with the indices separated by commas.
    For this example, the following would be valid output:
    0, 5, 9, out
    (Note that your output is a sequence of array indices, not a sequence of flight lengths and this line is terminated with a newline character.)
    Your program may be written in the language of your choice. It must accept from STDIN the array to be solved.
    STDIN will contain the array for a single problem.
    The STDIN will contain one integer per line, with no brackets or commas.
    The input array will eventually be large in our testing, so performance is important.
    If there is no solution or if the input is malformed, the program should write the string ��failure�� to STDOUT, followed by a newline character. Under no circumstance should your program throw unhandled exceptions.
Solution:
	1. DFS.
*/

#include <vector>
#include <stack>

using namespace std;

typedef struct _NODE
{
    int index;
    int value;
}NODE;

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
        int min = valley.size();

        stack<NODE> stk;
        vector<int> flights;
        vector<int> solution;

        if (min < 1)
        {
            return solution;
        }

        NODE node;
        node.index = 0;
        node.value = valley[0];
        stk.push(node);
        flights.push_back(0);

        while (!stk.empty())
        {
            NODE node = stk.top();

            if (node.value == 0)
            {
                flights.pop_back();
                stk.pop();
                break;
            }

            if (valley[node.index] == 0)
            {
                // Landed on a dragon
                flights.pop_back();
                stk.pop();
            }
            else if (node.index + node.value >= valley.size())
            {
                // Found a solution
                if (flights.size() <= min)
                {
                    min = flights.size();
                    solution = flights;
                }
                flights.pop_back();
                stk.pop();

                if (node.value >= 1)
                {
                    NODE nextnode = node;

                    nextnode.value--;
                    stk.push(nextnode);
                    flights.push_back(nextnode.index);
                }
                else if (!stk.empty())
                {
                    // Back to last step and try flying less length
                    node = stk.top();
                    while (node.value <= 1)
                    {
                        flights.pop_back();
                        stk.pop();
                        node = stk.top();
                    }

                    if (node.value > 1)
                    {
                        NODE nextnode = node;

                        nextnode.value--;
                        stk.push(nextnode);
                        flights.push_back(nextnode.index);
                    }
                }
            }
            else
            {
                NODE nextnode;

                nextnode.index = node.index + node.value;
                nextnode.value = valley[node.index + node.value];
                stk.push(nextnode);
                flights.push_back(nextnode.index);
            }

        }

        return solution;
    }
};
