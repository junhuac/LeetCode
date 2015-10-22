/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/05/2015
Notes:
    Given a string and dictionary, insert spaces in string so the string contains all valid words
    "ieatfood"
    => "i eat food"

    "ieatzxcv"
    => "ieatzxcv" or throw exception


    // this is given
    function isWord(String)
    => returns true or false

    isWord("food")
    => true

    isWord("zxcv")
    => false

    isWord("i")
    => true

    isWord("b")
    => false
Solution:
*/

#include <string>
#include <exception>

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

    string InsertSpaces(string str)
    {
        bool result = false;
        string str2 = InsertSpacesFunc(str, result);

        if (!result)
        {
            throw(new exception("Invalid string!"));
        }

        return str2;
    }

    string InsertSpacesFunc(string str, bool &result)
    {
        string spaced = str;

        if (str.length() == 0 || isWord(str))
        {
            result = true;
            return str;
        }

        result = false;

        int index = 0;

        while (!result && index < str.length())
        {
            bool found = false;

            while (++index < str.length() && !(found = isWord(str.substr(0, index))));

            if (found)
            {
                spaced = str.substr(0, index) + " " + InsertSpacesFunc(str.substr(index, str.length() - index), result);
                if (result)
                {
                    break;
                }
            }
        }

        return spaced;
    }
};
