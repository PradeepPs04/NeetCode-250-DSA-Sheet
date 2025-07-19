/*
    https://leetcode.com/problems/sqrtx/description/

    Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

    You must not use any built-in exponent function or operator.
        - For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

    Input: x = 4
    Output: 2

    Input: x = 8
    Output: 2
*/

#define ll long long

int mySqrt(int x)
{
    ll low = 0;
    ll high = x;

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;

        ll sq = mid * mid;

        if (sq == x)
            return (int)mid;

        if (x > sq)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return (int)high;
}