/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 09/06/2015
Notes:

5x5 grid

how many regions of contiguous 1s are in the following grid ?
answer : 1


changed here :

0 1 0 1 0
0 1 0 1 0
0 1 0 1 0
0 1 0 1 0
0 1 1 1 0


1 1 0
1 0 0
0 0 0

Solution:
	1. Record the region number in grid.
*/

class Solution
{
public:
    Solution()
    {
    }

    ~Solution()
    {
    }

    // Check if we have any non zero neighbors and return the region number
    // If there is no non zero neighbor, they return 1
    int checkneighbor(int* grid, int col, int row, int i, int j)
    {
        // A 1 is either a new region or connected to other regions
        int region = 1;
        int neighbor = 0;
        int cl = 0;
        int rw = 0;

        if (i >= 0 && i < row && j >= 0 && j < Col)
        {
            // check all neighbors if any non zero exists and if true we are connected to a previously detected region
            for (int k = -1; k <= 1; k++)
            {
                for (int m = -1; m <= 1; m++)
                {
                    rw = i + k;
                    cl = j + m;
                    // no need to check self
                    if (rw != i && cl != j)
                    {
                        if (rw >= 0 && rw < row && cl >= 0 && cl < Col)
                        {
                            neighbor = *(grid + rw*col + cl);
                            if (neighbor > 0)
                            {
                                if (region == 1)
                                {
                                    if (region < neighbor)
                                    {
                                        region = neighbor;
                                    }
                                }
                                else
                                {
                                    if (region < neighbor)
                                    {
                                        // A previously detected region is connected to another region by this node;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        return region;
    }

    // Find number of contiguos 1s in a grid
    int NumofContiguousRegion(int* grid, int col, int row)
    {
        int num = 2;
        for (int i = 0; i<row; i++)
        {
            for (int j = 0; j<col; j++)
            {
                if (*(grid + i*col + j) == 1)
                {
                    int region = checkneighbor(grid, col, row, i, j);
                    if (region > 1)
                    {
                        *(grid + i*col + j) = region;
                    }
                    else if (region == 1)
                    {
                        // We found a new region previously not recorded
                        region = num;
                        *(grid + i*col + j) = region;
                        num++;
                    }
                }
            }
        }

        return (num - 1);
    }
};
