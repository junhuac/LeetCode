/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 09/27/2015
Notes:
   Find the path to exit a maze. 
   The maze is stored in a 2 dimensional array:
   0: wall
   1: room
   You can only move horizontally or vertically in the maze.

Solution: DFS
*/

#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX_LENGTH = 1000;

class Solution
{
public:
    Solution()
    {
    }

    ~Solution()
    {
    }

    // Find path to exit maze
    // Entrance is at <0, 0>
    // Exit is at <exit_x, exit_y>
    vector<pair<int, int>> Maze(int* pMaze, int row, int col, int exit_x, int exit_y)
    {
        typedef pair<int, int> POINT;
        typedef map<POINT, vector<POINT>> MAP;
        MAP doors;

        int x, y;
        POINT pt, door;
        stack<pair<int, int>> st;
        vector<POINT> path;

        st.push({0, 0});

        while (!st.empty())
        {
            pt = st.top();

            x = pt.first;
            y = pt.second;

            // Test if we hit a wall or not
            if (*(pMaze + y * col + x) == 1)
            {
                if (x == exit_x && y == exit_y)
                {
                    // Exit found
                    break;
                }

                if (doors.find(pt) != doors.end())
                {
                    // We have just backed from last door, try next door
                    if (doors[pt].size() > 0)
                    {
                        while (doors[pt].size() > 0)
                        {
                            door = *(--doors[pt].end());
                            if (doors.find(door) == doors.end())
                            {
                                st.push(door);
                                doors[pt].pop_back();
                                break;
                            }
                            else
                            {
                                // We already tried this door earlier
                                doors[pt].pop_back();
                            }
                        }
                    }
                    else
                    {
                        // No more doors to try, so go back
                        do
                        {
                            st.pop();
                        } while (!st.empty() && (doors.find(st.top()) == doors.end() || doors[st.top()].size() == 0));
                    }
                }
                else
                {
                    // Find all the doors out of this room
                    for (int i = 0; i < 2; i++)
                    {
                        for (int j = 0; j < 2; j++)
                        {
                            if (j == 0)
                            {
                                x = pt.first + (i == 0 ? -1 : 1);
                                y = pt.second;
                            }
                            else
                            {
                                x = pt.first;
                                y = pt.second + (i == 0 ? -1 : 1);
                            }

                            if (x >= 0 && x < col && y >= 0 && y < row)
                            {
                                if (*(pMaze + y * col + x) == 1)
                                {
                                    // Found a door
                                    if (doors.find({ x, y }) == doors.end())
                                    {
                                        doors[pt].push_back({ x, y });
                                    }
                                }
                            }
                        }
                    }
                    if (doors[pt].size() == 0)
                    {
                        // No door out of this room, so go back
                        do
                        {
                            st.pop();
                        } while (!st.empty() && (doors.find(st.top()) == doors.end() || doors[st.top()].size() == 0));
                    }
                }
            }
            else
            {
                // Hit a wall, so go back
                do
                {
                    st.pop();
                } while (!st.empty() && (doors.find(st.top()) == doors.end() || doors[st.top()].size() == 0));
            }
        }

        while (!st.empty())
        {
            pt = st.top();
            path.push_back(pt);
            st.pop();
        }

        reverse(path.begin(), path.end());

        return path;
    }
};
