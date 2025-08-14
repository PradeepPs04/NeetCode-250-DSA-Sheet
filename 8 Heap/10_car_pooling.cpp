/*
    https://leetcode.com/problems/car-pooling/description/

    There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

    You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

    Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

    Input: trips = [[2,1,5],[3,3,7]], capacity = 4
    Output: false
*/

// using min heap
bool carPooling(vector<vector<int>> &trips, int capacity)
{
    // sort according to "from" and "to" locations
    sort(trips.begin(), trips.end(), [](const auto &a, const auto &b)
         { return (a[1] < b[1] || (a[1] == b[1] && a[2] < b[2])); });

    // min heap {destination, passenger}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int currPassengeres = 0; // current passengeres on car

    for (int i = 0; i < trips.size(); i++)
    {
        // remove all passengers those destination is equal to before the  current trip
        while (!pq.empty() && pq.top().first <= trips[i][1])
        {
            // decrease occupied seat
            currPassengeres -= pq.top().second;
            pq.pop();
        }

        // add trip to heap
        pq.push({trips[i][2], trips[i][0]});

        // increament occupied seat
        currPassengeres += trips[i][0];

        // check if currPassengers are more than capacity
        if (currPassengeres > capacity)
            return false;
    }

    return true;
}

// without using heap
bool carPooling(vector<vector<int>> &trips, int capacity)
{
    vector<vector<int>> arr;
    for (int i = 0; i < trips.size(); i++)
    {
        arr.push_back({trips[i][1], trips[i][0]});  // +x passengers added at source
        arr.push_back({trips[i][2], -trips[i][0]}); // -x passengers removed at destination
    }

    // sort according to location
    sort(arr.begin(), arr.end());

    int currPassengers = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        currPassengers += arr[i][1];

        // check if current passengers are more than capacity
        if (currPassengers > capacity)
            return false;
    }

    return true;
}