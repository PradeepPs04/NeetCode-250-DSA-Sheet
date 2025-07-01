/*
    given n return the nth power of 2

    Input: 4
    Output: 16
*/

int powerOfTwo(int n)
{
    if(n == 0)  return 1;
    return 2*powerOfTwo(n-1);
}