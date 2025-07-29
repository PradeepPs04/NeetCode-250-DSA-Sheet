/*
    https://leetcode.com/problems/lfu-cache/description/

    Design and implement a data structure for a Least Frequently Used (LFU) cache.

    Implement the LFUCache class:

        - LFUCache(int capacity) Initializes the object with the capacity of the data structure.
        - int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
        - void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
    To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

    When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

    The functions get and put must each run in O(1) average time complexity.

    Input
        ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
        [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
    Output
        [null, null, null, 1, null, -1, 3, null, -1, 3, 4]
*/

class LFUCache {
private:
    class Node {
    public:
        int val, key, count;
        struct Node *prev, *next;

        Node(int k, int v) {
            key = k;
            val = v;
            count = 1;
        }
    };

    class List {
    public:
        Node *head, *tail;
        int size;

        List() {
            size = 0;
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
        }

        void addFront(Node *node) {
            node->prev = head;
            node->next = head->next;
            head->next->prev = node;
            head->next = node;

            size++;
        }
        
        void removeNode(Node *node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;

            size--;
        }
    };

    map<int, Node*>keyNodeMap;
    map<int, List*>freqListMap;
    int maxCapacity;
    int minFreq;

    void updateMaps(Node *node) {
        // remove node from keyNode map
        keyNodeMap.erase(node->key);

        // remove node from current frequency List
        freqListMap[node->count]->removeNode(node);

        // if current minimum frequency list has become empty
        if(minFreq == node->count && freqListMap[node->count]->size == 0)  
            minFreq++;

        // create new list
        List *higherFreqList = new List();
        // check if higher frequency list already exists
        if(freqListMap .find(node->count+1) != freqListMap.end())   
            higherFreqList = freqListMap[node->count+1];

        // increase count of node by 1
        node->count += 1;

        // add node to higher frequency list
        higherFreqList->addFront(node);
        
        // add node in keyNode map
        keyNodeMap[node->key] = node;

        // add list to frequency list map
        freqListMap[node->count] = higherFreqList;
    }
public:
    LFUCache(int capacity) {
        maxCapacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        // if key is not present
        if(keyNodeMap.find(key) == keyNodeMap.end())    return -1;

        // get node
        Node *node = keyNodeMap[key];

        // update maps
        updateMaps(node);

        // return value
        return node->val;
    }
    
    void put(int key, int value) {
        if(maxCapacity == 0) return;

        // if key already exists
        if(keyNodeMap.find(key) != keyNodeMap.end()) {
            Node *node = keyNodeMap[key];
            node->val = value;
            updateMaps(node);
            return;
        }

        // if max capacity reached
        if(keyNodeMap.size() == maxCapacity) {
            // get lfu node
            Node *node = freqListMap[minFreq]->tail->prev;
            
            // remove node from keyNode map
            keyNodeMap.erase(node->key);

            // remove node from freqlist
            freqListMap[node->count]->removeNode(node);
        }
        
        // reset minimum frequency
        minFreq = 1;

        // create new node
        Node *node = new Node(key, value);

        // create new list
        List *newList = new List();
        if(freqListMap.find(minFreq) != freqListMap.end())
            newList = freqListMap[minFreq];

        // add node to list
        newList->addFront(node);
        
        // update node in keyNode map
        keyNodeMap[key] = node;

        // update list in freqList map
        freqListMap[node->count] = newList;
    }
};