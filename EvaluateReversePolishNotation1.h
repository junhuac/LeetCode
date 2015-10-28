/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/28/2015
Notes:
    Evaluate the value of an arithmetic expression in Reverse Polish Notation.
    Valid operators are +, -, *, /. Each operand may be an integer or another expression.
    Some examples:
    ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
    ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
Solution:
    stack.
*/

#include <vector>
#include <string>
#include <stack>
#include <set>

using namespace std;

const int BUF_SIZE = 20;

class Math
{
public:
    Math() {}

    int EvaluateReversePolishNotation(vector<string> str)
    {
        int result = 0;
        stack<string> stk;
        set<string> operators = {"+", "-", "*", "/"};

        for (int i = 0; i < str.size(); i++)
        {
            stk.push(str[i]);

            if (operators.find(stk.top()) != operators.end())
            {
                string op, param1, param2;
                int v1, v2;

                op = stk.top();
                stk.pop();

                if (!stk.empty())
                {
                    param2 = stk.top();
                    stk.pop();
                }

                if (!stk.empty())
                {
                    param1 = stk.top();
                    stk.pop();
                }

                v1 = atoi(param1.c_str());
                v2 = atoi(param2.c_str());

                if (op == "+")
                {
                    result = v1 + v2;
                }
                else if (op == "-")
                {
                    result = v1 - v2;
                }
                else if (op == "*")
                {
                    result = v1 * v2;
                }
                else if (op == "/")
                {
                    result = v1 / v2;
                }

                char buf[BUF_SIZE];
                _itoa_s(result, buf, 10);
                stk.push(buf);
            }
        }

        return result;
    }
};

