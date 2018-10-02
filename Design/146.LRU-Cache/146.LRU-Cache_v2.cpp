#include <iostream>
#include <bits/stdc++.h>

class LRUCache {
    int cap;
    list<pair<int,int>>List;        // list node : (key, val)
    unordered_map<int,list<pair<int,int>>::iterator>Map; // key->list node


public:
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (Map.find(key)==Map.end()) return -1;
        auto iter = Map[key];
        int val = iter->second;

        List.erase(iter);
        List.push_back({key,val});
        Map[key] = --List.end();
        return val;

    }

    void put(int key, int value)
    {
        if (get(key)!=-1)
        {
            List.rbegin()->second = value;
            return;
        }

        if (List.size()==cap)
        {
            int key = List.begin()->first;
            auto iter = Map[key];
            List.erase(iter);
            Map.erase(key);
        }

        List.push_back({key,value});
        Map[key] = --List.end();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
