class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() 
    {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) 
    {
        if (Map.find(val)!=Map.end())
            return false;
        else
        {
            Map[val]=q.size();
            q.push_back(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) 
    {
        if (Map.find(val)==Map.end())
            return false;
        else
        {
            q[Map[val]] = q.back();
            Map[q.back()] = Map[val];
            q.pop_back();
            Map.erase(val);
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() 
    {
        int pos = rand()%q.size();
        return q[pos];
    }
    
private:    
    unordered_map<int,int>Map;
    vector<int>q;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
