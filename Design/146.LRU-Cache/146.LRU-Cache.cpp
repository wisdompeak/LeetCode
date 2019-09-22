class LRUCache {
    unordered_map<int,int>key2val;
    list<int>List;
    unordered_map<int, list<int>::iterator>key2iter;    
    int cap;
    
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) 
    {
        if (key2val.find(key)==key2val.end())
            return -1;
        auto iter = key2iter[key];
        List.erase(iter);
        List.push_back(key);
        key2iter[key] = --List.end();
        return key2val[key];
    }
    
    void put(int key, int value) 
    {
        if (get(key)!=-1)
        {
            key2val[key] = value;
            return;
        }
        
        if (key2val.size()==cap)
        {
            int keyDel = *List.begin();
            key2val.erase(keyDel);
            key2iter.erase(keyDel);
            List.erase(List.begin());
        }
        key2val[key] = value;
        List.push_back(key);
        key2iter[key] = --List.end();        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */




//key1, key3, ..., key_n, key2, 
