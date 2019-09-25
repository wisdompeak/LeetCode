class RandomizedCollection {
    vector<int>nums;
    unordered_map<int,unordered_set<int>>val2pos;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) 
    {
        int flag = val2pos.find(val)==val2pos.end();
        
        nums.push_back(val);
        val2pos[val].insert(nums.size()-1);
        
        return flag;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) 
    {
        int flag = val2pos.find(val)!=val2pos.end();
        if (flag==false) return false;
        
        int pos = *(val2pos[val].begin());
        int val2 = nums.back();
        
        if (val2==val)
        {
            nums.pop_back();
        }
        else
        {
            int pos2 = nums.size()-1;
            nums[pos] = val2;
            nums.pop_back();
            val2pos[val2].erase(pos2);
            val2pos[val2].insert(pos);
        }
        
        val2pos[val].erase(pos);
        if (val2pos[val].size()==0)
            val2pos.erase(val);
        
        return flag;
        
    }
    
    /** Get a random element from the collection. */
    int getRandom() 
    {
        int idx = rand()%nums.size();
        return nums[idx];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

