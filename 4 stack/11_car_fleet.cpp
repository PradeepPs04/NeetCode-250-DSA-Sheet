/*
    https://leetcode.com/problems/car-fleet/submissions/1699830256/

    There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.

    You are given two integer array position and speed, both of length n, where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.

    A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.

    A car fleet is a car or cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.

    If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.

    Return the number of car fleets that will arrive at the destination.

    
    Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
    Output: 3
*/

int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    // sort cars according to position
    vector<pair<int, int>> arr;
    for (int i = 0; i < position.size(); i++)
    {
        arr.push_back({position[i], speed[i]});
    }

    sort(arr.begin(), arr.end());

    stack<float> st;

    for (auto it : arr)
    {
        int pos = it.first;
        int sp = it.second;
        float timeTaken = (float)(target - pos) / sp; // time taken to reach the target

        // if previous car reaches target faster than the current car
        // i.e. previousCar.timeTaken < currentCar.timeTaken
        // then they will form a fleet
        // since slower car will stop the faster car
        // and after that it will move with the speed of slower car
        while (!st.empty() && timeTaken >= st.top())
            st.pop();

        st.push(timeTaken);
    }

    return st.size();
}