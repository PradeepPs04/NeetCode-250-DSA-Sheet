/*
    https://leetcode.com/problems/maximum-frequency-stack/

    Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

    Implement the FreqStack class:

        - FreqStack() constructs an empty frequency stack.
        void push(int val) pushes an integer val onto the top of the stack.
        - int pop() removes and returns the most frequent element in the stack.
        - If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.

    Input
        ["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
        [[], [5], [7], [5], [7], [4], [5], [], [], [], []]
    Output
        [null, null, null, null, null, null, null, 5, 7, 5, 4]
*/

class FreqStack
{
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> freq_group_stack;
    int max_freq = 0;

public:
    FreqStack()
    {
    }

    void push(int val)
    {
        // increase frequency of val
        freq[val]++;

        // add element to freq_group_stack
        int elem_freq = freq[val];
        freq_group_stack[elem_freq].push(val);

        // get maximum frequency
        max_freq = max(max_freq, freq[val]);
    }

    int pop()
    {
        // pop element that having maximum frequency (from freq_group_stack)
        int elem = freq_group_stack[max_freq].top();
        freq_group_stack[max_freq].pop();

        // decrease frequency of popped element
        freq[elem]--;

        // decrease max frequency iff there are no more element having max_freq
        if (freq_group_stack[max_freq].empty())
            max_freq--;

        return elem;
    }