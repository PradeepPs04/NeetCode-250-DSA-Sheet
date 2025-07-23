/*
    https://leetcode.com/problems/time-based-key-value-store/description/

    Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

    Implement the TimeMap class:

        -> TimeMap() Initializes the object of the data structure.
        -> void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
        -> String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".

    Input
        ["TimeMap", "set", "get", "get", "set", "get", "get"]
        [[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
    Output
        [null, null, "bar", "bar", null, "bar2", "bar2"]
*/

class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>>mpp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        int low = 0;
        int high = mpp[key].size()-1;

        int idx = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;

            int time = mpp[key][mid].second;
            if(time <= timestamp) {
                idx = mid;
                low = mid + 1;
            } else high = mid - 1;
        }

        if(idx == -1)   return "";
        return mpp[key][idx].first;
    }
};