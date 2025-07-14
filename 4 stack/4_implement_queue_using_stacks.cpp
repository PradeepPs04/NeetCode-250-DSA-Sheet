/*
    https://leetcode.com/problems/implement-queue-using-stacks/description/

    Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

    Implement the MyQueue class:
        - void push(int x) Pushes element x to the back of the queue.
        - int pop() Removes the element from the front of the queue and returns it.
        - int peek() Returns the element at the front of the queue.
        - boolean empty() Returns true if the queue is empty, false otherwise.

    Notes:
        - You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
        - Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.


    Input
        ["MyQueue", "push", "push", "peek", "pop", "empty"]
        [[], [1], [2], [], [], []]
    Output
        [null, null, null, 1, 1, false]
*/

// Brute
class MyQueue {
public:
    stack<int>st1, st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        // shift all elments from st1 to st2
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        
        // add new element to st1
        st1.push(x);
        
        // shift back all elements from st2 to st1
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        if(st1.empty()) return -1;

        int popped = st1.top();
        st1.pop();

        return popped;
    }
    
    int peek() {
        if(st1.empty()) return -1;
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};

// armortized O(1) 
class MyQueue
{
public:
    stack<int> input, output;
    MyQueue()
    {
    }

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        if (output.empty())
            return -1;
        int popped = output.top();
        output.pop();
        return popped;
    }

    int peek()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        if (output.empty())
            return -1;
        return output.top();
    }

    bool empty()
    {
        return (input.empty() && output.empty());
    }
};