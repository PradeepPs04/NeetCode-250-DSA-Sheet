/*
    https://leetcode.com/problems/design-twitter/

    Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

    Implement the Twitter class:

        - Twitter() Initializes your twitter object.
        - void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
        - List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
        - void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
        - void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.

    Input
        ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
        [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
    Output
        [null, null, [5], null, null, [6, 5], null, [5]]
*/

class Twitter
{
private:
    int time;
    unordered_map<int, vector<pair<int, int>>> post;
    unordered_map<int, set<int>> following;

public:
    Twitter()
    {
        time = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        time++;
        post[userId].push_back({time, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<pair<int, int>> pq;

        for (auto i : post[userId])
            pq.push({i.first, i.second});

        for (auto i : following[userId])
        {
            for (auto j : post[i])
                pq.push({j.first, j.second});
        }

        vector<int> ans;

        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
            if (ans.size() == 10)
                break;
        }

        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        following[followerId].erase(followeeId);
    }
};