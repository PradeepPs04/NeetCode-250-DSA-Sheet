/*
    https://leetcode.com/problems/min-stack/description/

    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    Implement the MinStack class:
        - MinStack() initializes the stack object.
        - void push(int val) pushes the element val onto the stack.
        - void pop() removes the element on the top of the stack.
        - int top() gets the top element of the stack.
        - int getMin() retrieves the minimum element in the stack.

    You must implement a solution with O(1) time complexity for each function.

    Input
        ["MinStack","push","push","push","getMin","pop","top","getMin"]
        [[],[-2],[0],[-3],[],[],[],[]]

    Output
        [null,null,null,null,-3,null,0,-2]
*/

class MinStack
{
private:
    stack<int> st;
    stack<int> cur_min;
    // cur_min stack will be used to store the current minimum value
    // when an element is pushed in stack
public:
    MinStack() {}

    void push(int val)
    {
        st.push(val);
        if (cur_min.empty())
        {
            // calling push for the first time
            cur_min.push(val);
        }
        else
        {
            // update the current minimum value in stack
            if (val < cur_min.top())
                cur_min.push(val);
            // if new values is not minimum then retain the previous minimum
            // value by pusing it again
            else
                cur_min.push(cur_min.top());
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        // we have to pop from both stacks
        // if minimum value is popped from stack
        // so the value which was previous minimum would be on top of cur_min
        st.pop();
        cur_min.pop();
    }

    int top()
    {
        if (st.empty())
            return -1;
        return st.top();
    }

    int getMin()
    {
        if (st.empty())
            return -1;
        return cur_min.top();
    }
};