class LRUCache {
    unordered_map<int,int>Map;
    list<int>List;
    unordered_map<int,list<int>::iterator>iter;
    int cap;
    
public:
    LRUCache(int capacity) 
    {
        cap=capacity;
    }
    
    int get(int key) 
    {
        if (Map.find(key)==Map.end()) return -1;
        
        List.erase(iter[key]);
        List.push_back(key);
        iter[key]=--List.end();        
        return Map[key];
    }
    
    void put(int key, int value) 
    {
        if (cap<=0) return;
        if (get(key)!=-1)
        {
            Map[key]=value;
            return;
        }
        
        if (List.size()<cap)
        {
            List.push_back(key);
            iter[key]=--List.end();
            Map[key]=value;
        }
        else
        {
            int minKey = List.front();
            iter.erase(minKey);
            List.pop_front();
            Map.erase(minKey);
            
            List.push_back(key);
            iter[key]=--List.end();
            Map[key]=value;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
