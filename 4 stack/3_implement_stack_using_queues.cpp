/*
    https://leetcode.com/problems/implement-stack-using-queues/description/

    Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

    Implement the MyStack class:
        - void push(int x) Pushes element x to the top of the stack.
        - int pop() Removes the element on the top of the stack and returns it.
        - int top() Returns the element on the top of the stack.
        - boolean empty() Returns true if the stack is empty, false otherwise.

    Notes:
        - You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
        - Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.


    Input
        ["MyStack", "push", "push", "top", "pop", "empty"]
        [[], [1], [2], [], [], []]
    Output
        [null, null, null, 2, 2, false]
*/

// using 2 queues
class MyStack
{
public:
    queue<int> q1, q2;
    MyStack()
    {
    }

    void push(int x)
    {
        q2.push(x);

        // shift all from q1 to q2
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // shift all from q2 to q1
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        if (q1.empty())
            return -1;
        int top = q1.front();
        q1.pop();
        return top;
    }

    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};


// using 1 queue
class MyStack
{
public:
    queue<int> q;
    MyStack()
    {
    }

    void push(int x)
    {
        // add element to queue
        q.push(x);

        // reverse queue
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        if (q.empty())
            return -1;
        int top = q.front();
        q.pop();
        return top;
    }

    int top()
    {
        if (q.empty())
            return -1;
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};