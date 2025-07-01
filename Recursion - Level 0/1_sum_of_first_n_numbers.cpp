/*
    Given an integer n, your task is to compute the sum of all natural numbers from 1 to n (inclusive). If n is 0, the sum should be 0.
*/

int findSum(int n)
{
    if (n == 0)
        return 0;
    return n + findSum(n - 1);
}