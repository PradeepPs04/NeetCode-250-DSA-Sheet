/*
    https://leetcode.com/problems/asteroid-collision/description/

    We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.

    For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

    Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.



    Input: asteroids = [5,10,-5]
    Output: [5,10]
*/

bool can_not_collide(int a, int b)
{
    if (a > 0 && b > 0) // if both are (+) moving in right direction  ->  ->
        return true;
    if (a < 0 && b < 0) // if both are (-) moving in left direction    <- <-
        return true;
    if (a < 0 && b > 0) // if first is (-) moving left and second is (+)
                        // moving right  <-  ->
        return true;
    else
        return false;
}

vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> st;
    for (int i = 0; i < asteroids.size(); i++)
    {
        while (true)
        {
            if (st.empty())
            {
                st.push(asteroids[i]);
                break;
            }
            else if (can_not_collide(st.top(), asteroids[i]))
            {
                st.push(asteroids[i]);
                break;
            }
            else if (abs(asteroids[i]) ==
                     abs(st.top())) // when both have same weight
            {                       // this will be only checked when they can collide
                st.pop();
                break;
            }
            else
            {
                if (abs(asteroids[i]) > abs(st.top()))
                    st.pop();
                else
                    break;
            }
        }
    }

    vector<int> ans(st.size());
    for (int i = st.size() - 1; i >= 0; i--)
    {
        ans[i] = st.top();
        st.pop();
    }
    return ans;
}