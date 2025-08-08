/*
    https://leetcode.com/problems/k-closest-points-to-origin/description/

    Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

    The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

    You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).


    Input: points = [[1,3],[-2,2]], k = 1
    Output: [[-2,2]]
*/

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    priority_queue<pair<float, pair<int, int>>> pq; // max heap {distance, {x,y}}

    for (int i = 0; i < k; i++)
    {
        float a = points[i][0] * points[i][0];
        float b = points[i][1] * points[i][1];

        float dist = sqrt(a + b);
        pq.push({dist, {points[i][0], points[i][1]}});
    }

    for (int i = k; i < points.size(); i++)
    {
        float a = points[i][0] * points[i][0];
        float b = points[i][1] * points[i][1];

        float dist = sqrt(a + b);

        if (dist < pq.top().first)
        {
            pq.pop();
            pq.push({dist, {points[i][0], points[i][1]}});
        }
    }

    vector<vector<int>> ans;

    while (!pq.empty())
    {
        ans.push_back({pq.top().second.first, pq.top().second.second});
        pq.pop();
    }

    return ans;
}