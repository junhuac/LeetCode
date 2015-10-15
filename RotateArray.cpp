#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef vector<vector<int>> ARRAY;

// rotate array of (size X size), starting from (index,index) 
void rotate(ARRAY &array, int index, int size)
{
    int temp0_0 = array[index][index];
    int temp0_1 = array[index][index + size - 1];
    int temp1_1 = array[index + size - 1][index + size - 1];
    int temp1_0 = array[index + size - 1][index];

    array[index][index] = array[index + 1][index];

    for (int j = index; j<index + size; j++)
    {
        if (j == index)
        {
            for (int i = index; i<index + size - 1; i++)
            {
                if (i == index)
                {
                    array[j][i + 1] = temp0_0;
                }
                else
                {
                    array[j][i + 1] = array[j][i];
                }
            }
        }
        else if (j == index + size - 1)
        {
            for (int i = index; i<index + size - 1; i++)
            {
                if (i == index + size - 1)
                {
                    array[j][i] = temp0_1;
                }
                else
                {
                    array[j][i] = array[j][i + 1];
                }
            }
        }
    }

    for (int i = index; i<index + size; i++)
    {
        if (i == index)
        {
            for (int j = index; j<index + size - 1; j++)
            {
                if (j == index + size - 1)
                {
                    array[j][i] = temp1_0;
                }
                else
                {
                    array[j][i] = array[j + 1][i];
                }
            }
        }
        else if (i == index + size - 1)
        {
            for (int j = index; j<index + size - 1; j++)
            {
                if (j == index)
                {
                    array[j + 1][i] = temp0_1;
                }
                else
                {
                    array[j + 1][i] = array[j][i];
                }
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    string line;
    int rows;

    ARRAY array;

    getline(cin, line);
    stringstream(line) >> rows;
    //cout << rows << "\n";

    for (int i = 0; i<rows; i++)
    {
        int j = 0;
        vector<int> v;

        getline(cin, line);

        stringstream sstream(line);

        while (!sstream.eof())
        {
            int num;
            sstream >> num;
            //cout << num << " ";
            v.push_back(num);
            j++;
            sstream >> ws;
        }

        array.push_back(v);
        //cout << "\n";
    }

    for (int j = 0; j<array.size(); j++)
    {
        vector<int> v = array[j];

        if (array.size() != v.size())
        {
            cout << "ERROR\n";
        }
    }

    for (int j = 0; j<array.size()/2; j++)
    {
        rotate(array, j, array[j].size() - j * 2);
    }

    //cout << rows << "\n";
    for (int j = 0; j<array.size(); j++)
    {
        vector<int> v = array[j];

        for (int i = 0; i<v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}