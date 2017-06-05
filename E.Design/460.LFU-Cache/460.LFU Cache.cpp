class LFUCache {
    int cap, minfreq;
    unordered_map<int,pair<int,int>>Map; // key -> value, freq;
    unordered_map<int,list<int>>freq; // freq -> keys
    unordered_map<int,list<int>::iterator>iter; // key -> iterator
public:
    LFUCache(int capacity) 
    {
        cap=capacity;
    }
    
    int get(int key) 
    {
        if (Map.find(key)==Map.end()) return -1;
        int f=Map[key].second;
        freq[f].erase(iter[key]);
        freq[f+1].push_back(key);
        iter[key]=--freq[f+1].end();
        Map[key].second++;
        if (freq[minfreq].size()==0)
            minfreq++;
        return Map[key].first;
    }
    
    void put(int key, int value) 
    {
        if (cap<=0) return;
        if (get(key)!=-1)
        {
            Map[key].first=value;
            return;
        }
        else
        {
            if (Map.size()>=cap)
            {
                int minKey=freq[minfreq].front();
                iter.erase(minKey);
                Map.erase(minKey);
                freq[minfreq].pop_front();
            }
            Map[key]={value,1};
            freq[1].push_back(key);
            iter[key]=--freq[1].end();
            minfreq=1;
            return;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
