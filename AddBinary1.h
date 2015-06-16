/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 06/15/2015
Problem: Given 2 strings of binary digits (1, 0), return another string representing the sum
*/

using namespace std;

class Solution
{
public:
	Solution() {}

	string AddBinary(string str1, string str2)
	{
		int i, j;
		char carry = '0';
		string result = "";
		string final = "";

		for (i = str1.length() - 1, j = str2.length() - 1; i >= 0 || j >= 0; i--, j--)
		{
			if (i >= 0 && j >= 0)
			{
				if (str1.at(i) == '0' || str2.at(j) == '0')
				{
					if (str1.at(i) == '1' || str2.at(j) == '1')
					{
						if (carry == '0')
						{
							result = result + '1';
							carry = '0';
						}
						else
						{
							result = result + '0';
							carry = '1';
						}
					}
					else
					{
						result = result + carry;
						carry = '0';
					}
				}
				else
				{
					if (carry == '0')
					{
						result = result + '0';
						carry = '1';
					}
					else
					{
						result = result + '1';
						carry = '1';
					}
				}
			}
			else if (i >= 0)
			{
				if (carry == '0')
				{
					result = result + str1.at(i);
				}
				else
				{
					if (str1.at(i) == '0')
					{
						result = result + '1';
						carry = '0';
					}
					else
					{
						result = result + '0';
						carry = '1';
					}
				}
			}
			else
			{
				if (carry == '0')
				{
					result = result + str2.at(j);
				}
				else
				{
					if (str2.at(j) == '0')
					{
						result = result + '1';
						carry = '0';
					}
					else
					{
						result = result + '0';
						carry = '1';
					}
				}
			}
		}

		// Reverse the result string to get final result
		for (i = result.length() - 1; i >= 0; i--)
		{
			final = final + result.at(i);
		}

		return final;
	}

};