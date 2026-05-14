/*
🧩 PROBLEM 34: LRU CACHE DESIGN

Problem Statement:

Design a data structure that follows the constraints of a Least Recently Used (LRU) Cache.

Implement:

get(key) → return value if exists, else -1
put(key, value) → insert/update key
When capacity is full → remove least recently used

All operations must be in O(1) time.

Example:

LRUCache cache(2)

put(1,1)
put(2,2)
get(1) → 1
put(3,3) → removes key 2
get(2) → -1
put(4,4) → removes key 1
get(1) → -1
get(3) → 3
get(4) → 4
*/



/*
Problem: LRU Cache

Pattern: HashMap + Doubly Linked List
Key Idea:
- Map for O(1) access
- List to maintain order (recent → front)
*/

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    int cap;
    list<pair<int,int>> dll; // {key, value}
    unordered_map<int, list<pair<int,int>>::iterator> mp;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        auto it = mp[key];
        int val = it->second;

        dll.erase(it);
        dll.push_front({key, val});
        mp[key] = dll.begin();

        return val;
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            dll.erase(mp[key]);
        }
        else if(dll.size() == cap) {
            auto last = dll.back();
            mp.erase(last.first);
            dll.pop_back();
        }

        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};

int main() {
    LRUCache cache(2);

    cache.put(1,1);
    cache.put(2,2);
    cout << cache.get(1) << endl; // 1

    cache.put(3,3);
    cout << cache.get(2) << endl; // -1

    cache.put(4,4);
    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 3
    cout << cache.get(4) << endl; // 4
}