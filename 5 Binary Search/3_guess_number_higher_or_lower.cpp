/*
    https://leetcode.com/problems/guess-number-higher-or-lower/description/

    We are playing the Guess Game. The game is as follows:

    I pick a number from 1 to n. You have to guess which number I picked.

    Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

    You call a pre-defined API int guess(int num), which returns three possible results:

        - -1: Your guess is higher than the number I picked (i.e. num > pick).
        - 1: Your guess is lower than the number I picked (i.e. num < pick).
        - 0: your guess is equal to the number I picked (i.e. num == pick).
    Return the number that I picked.

    Input: n = 10, pick = 6
    Output: 6
*/

int guessNumber(int n)
{
    int low = 1;
    int high = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int g = guess(mid);
        if (g == 0)
            return mid;
        else if (g == -1)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}