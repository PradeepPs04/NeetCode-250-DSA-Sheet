/*
    https://leetcode.com/problems/lru-cache/description/

    Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

    Implement the LRUCache class:

        - LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
        - int get(int key) Return the value of the key if the key exists, otherwise return -1.
        - void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
    The functions get and put must each run in O(1) average time complexity.


    Input
        ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
        [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
    Output
        [null, null, null, 1, null, -1, null, -1, 3, 4]
*/

class Node {
public:
    int val, key;
    Node *prev, *next;
    Node(int k, int data): key(k), val(data), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    Node *head, *tail;
    int capacity;
    unordered_map<int, Node*>mpp;

    void insertNode(Node *temp)
    {
        Node *prevNode = tail->prev;

        temp->prev = prevNode;
        temp->next = tail;

        prevNode->next = temp;
        tail->prev = temp;

        mpp[temp->key] = temp;
        capacity--;
    }

    void deleteNode(Node *temp)
    {
        Node *prevNode = temp->prev;
        Node *nextNode = temp->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        mpp.erase(temp->key);
        delete temp;

        capacity++;
    }
public:
    LRUCache(int cap) {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;

        capacity = cap;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end())  return -1;

        Node *temp = mpp[key];
        int val = temp->val;

        deleteNode(temp);

        temp = new Node(key, val);
        insertNode(temp);

        return val;
    }
    
    void put(int key, int value) {        
        if(mpp.find(key) != mpp.end())
        {
            Node *temp = mpp[key];
            deleteNode(temp);
            temp = new Node(key, value);
            insertNode(temp);
            return;
        }

        if(!capacity)   deleteNode(head->next);

        Node *temp = new Node(key, value);
        insertNode(temp);
    }
};