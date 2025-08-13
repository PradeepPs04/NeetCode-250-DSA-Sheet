/*
    https://leetcode.com/problems/longest-happy-string/description/

    A string s is called happy if it satisfies the following conditions:

        - s only contains the letters 'a', 'b', and 'c'.
        - s does not contain any of "aaa", "bbb", or "ccc" as a substring.
        - s contains at most a occurrences of the letter 'a'.
        - s contains at most b occurrences of the letter 'b'.
        - s contains at most c occurrences of the letter 'c'.
        - Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

    A substring is a contiguous sequence of characters within a string.

    Input: a = 1, b = 1, c = 7
    Output: "ccaccbcc"
*/

string longestDiverseString(int a, int b, int c)
{
    priority_queue<pair<int, char>> pq; // max heap {freq, char}

    // add character to max heap
    if (a > 0)
        pq.push({a, 'a'});
    if (b > 0)
        pq.push({b, 'b'});
    if (c > 0)
        pq.push({c, 'c'});

    string ans = "";

    while (!pq.empty())
    {
        // get the most frequent element
        auto firstElem = pq.top();
        pq.pop();
        
        // check if last 2 characters on answer are same as most frequent character
        if (ans.length() >= 2 && firstElem.second == ans[ans.length() - 1] && firstElem.second == ans[ans.length() - 2])
        {
            // if no elements left
            if (pq.empty())
                return ans;

            // get the next most frequent element
            auto secondElem = pq.top();
            pq.pop();

            // add 1 character to answer
            ans += secondElem.second;

            // push the most frequenct element
            pq.push(firstElem);

            // check if second most frequnet element is still having frequency left
            if (secondElem.first - 1 > 0)
                pq.push({secondElem.first - 1, secondElem.second});
        }
        else
        {
            // add 1 character to answer
            ans += firstElem.second;

            // check if most frequent element is still having frequency left
            if (firstElem.first - 1 > 0)
                pq.push({firstElem.first - 1, firstElem.second});
        }
    }

    return ans;
}