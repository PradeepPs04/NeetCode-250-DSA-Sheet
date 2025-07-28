/*
    https://leetcode.com/problems/design-circular-queue/

    Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle, and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

    One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

    Implement the MyCircularQueue class:

        - MyCircularQueue(k) Initializes the object with the size of the queue to be k.
        - int Front() Gets the front item from the queue. If the queue is empty, return -1.
        - int Rear() Gets the last item from the queue. If the queue is empty, return -1.
        - boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
        - boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
        - boolean isEmpty() Checks whether the circular queue is empty or not.
        - boolean isFull() Checks whether the circular queue is full or not.
    You must solve the problem without using the built-in queue data structure in your programming language.


    Input
        ["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
        [[3], [1], [2], [3], [4], [], [], [], [4], []]
    Output
        [null, true, true, true, false, 3, true, true, true, 4]
*/

class MyCircularQueue
{
private:
    vector<int> q;
    int start = -1;
    int end = -1;
    int maxSize;
    int curSize = 0;

public:
    MyCircularQueue(int k)
    {
        q.resize(k);
        maxSize = k;
    }

    bool enQueue(int value)
    {
        // if queue is full
        if (curSize == maxSize)
            return false;

        // if inserting for the first time
        if (start == -1)
        {
            start = 0;
            end = 0;
            q[end] = value;
        }
        else
        {
            end = (end + 1) % maxSize;
            q[end] = value;
        }

        curSize++;
        return true;
    }

    bool deQueue()
    {
        // if queue is empty
        if (curSize == 0)
            return false;

        start = (start + 1) % maxSize;
        curSize--;
        return true;
    }

    int Front()
    {
        if (curSize == 0)
            return -1;
        return q[start];
    }

    int Rear()
    {
        if (curSize == 0)
            return -1;
        return q[end];
    }

    bool isEmpty()
    {
        return curSize == 0;
    }

    bool isFull()
    {
        return curSize == maxSize;
    }
};