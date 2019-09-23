class LFUCache {
    unordered_map<int,int>key2value;
    unordered_map<int, list<int>::iterator> key2iter;
    unordered_map<int, int>key2freq;
    unordered_map<int, list<int>>freq2list;
    int cap, minFreq;
    
    
public:
    LFUCache(int capacity) 
    {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) 
    {
        if (key2value.find(key)==key2value.end())
            return -1;
        
        int f = key2freq[key];
        freq2list[f].erase(key2iter[key]);
        freq2list[f+1].push_back(key);
        key2iter[key] = --freq2list[f+1].end();
        key2freq[key] = f+1;
        
        if (freq2list[minFreq].size()==0)
            minFreq+=1;
        
        return key2value[key];
    }
    
    void put(int key, int value) 
    {
        if (cap==0) return;
        
        if (get(key)!=-1)
        {
            key2value[key] = value;
            return;
        }
        
        if (key2value.size()==cap)
        {
            int k = freq2list[minFreq].front();

            key2value.erase(k);
            key2iter.erase(k);
            key2freq.erase(k);
            freq2list[minFreq].pop_front();
        }

        key2value[key] = value;
        key2freq[key] = 1;
        freq2list[1].push_back(key);
        key2iter[key] = --freq2list[1].end();
        
        minFreq = 1;
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
