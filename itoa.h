/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/02/2015
Notes:
    integer to ascii
    1234 => "1234"
    only concerned about base 10

Solution: Recursion.
*/

char* itoa(int value)
{
    const int BUF_SIZE = 100;
    int sign = 0;
    int v = value;
    int digit = 0;
    int index = 0;
    int length = 0;
    char buf[BUF_SIZE];
    char* result;

    memset(buf, 0, BUF_SIZE);

    if (v < 0)
    {
        sign = 1;
        v = -v;
    }

    if (v == 0)
    {
        buf[0] = '0';
    }
    else
    {
        while (v > 0 && index < BUF_SIZE)
        {
            digit = v % 10;
            v /= 10;
            buf[index++] = '0' + digit;
        }
    }

    length = strlen(buf);

    result = (char*)malloc(length + 1 + sign);

    if (sign)
    {
        result[0] = '-';
    }

    for (int i = 0; i < length; i++)
    {
        result[i + sign] = buf[length - 1 - i];
    }
    result[length + sign] = 0;

    return result;
}

