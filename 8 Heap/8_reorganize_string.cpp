/*
    https://leetcode.com/problems/reorganize-string/description/

    Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

    Return any possible rearrangement of s or return "" if not possible.


    Input: s = "aab"
    Output: "aba"
*/

// max heap
string reorganizeString(string s)
{
    // count frequency of each character
    vector<int> mpp(26, 0);
    for (char &ch : s)
        mpp[ch - 'a']++;

    priority_queue<pair<int, char>> pq; // max heap {freq, character}

    // push all {freq, character} in max heap
    for (int i = 0; i < 26; i++)
    {
        if (mpp[i] > 0)
            pq.push({mpp[i], 'a' + i});
    }

    string ans = "";
    while (!pq.empty())
    {
        // if only 1 element left in heap
        if (pq.size() == 1)
        {
            if (pq.top().first > 1)
                return "";
            else
            {
                ans += pq.top().second;
                return ans;
            }
        }
        else
        {
            // get 2 maximum frequnecies
            auto firstElem = pq.top();
            pq.pop();
            auto secondElem = pq.top();
            pq.pop();

            // add characters to answer
            ans += firstElem.second;
            ans += secondElem.second;

            // decrease frequency
            firstElem.first--;
            secondElem.first--;

            // if frequency still remaining
            if (firstElem.first > 0)
                pq.push(firstElem);
            if (secondElem.first > 0)
                pq.push(secondElem);
        }
    }

    return ans;
}

// greedy
string reorganizeString(string s)
{
    // calculate the frequency of each character
    vector<int> freq(26, 0);
    int maxFreqIdx = 0; // to store the max frequency character
    for (char &ch : s)
    {
        freq[ch - 'a']++;
        if (freq[ch - 'a'] > freq[maxFreqIdx])
            maxFreqIdx = ch - 'a';
    }

    string ans(s.length(), '-'); // answer string of n length

    // if not possible to reorder string
    if (freq[maxFreqIdx] - 1 > s.length() - freq[maxFreqIdx])
        return "";

    int idx = 0;
    // add maximum occuring character at even places (by skipping one index)
    while (freq[maxFreqIdx])
    {
        ans[idx] = 'a' + maxFreqIdx;
        freq[maxFreqIdx]--;
        idx += 2;
    }

    for (int i = 0; i < 26; i++)
    {
        while (freq[i])
        {
            // if idx reaches end (it means that all even places are filled)
            if (idx >= s.length())
                idx = 1; // start from odd places i.e. 1

            ans[idx] = 'a' + i; // add character to answer
            freq[i]--;          // decrease frequency of character
            idx += 2;           // go to next index by skipping one index
        }
    }

    return ans;
}