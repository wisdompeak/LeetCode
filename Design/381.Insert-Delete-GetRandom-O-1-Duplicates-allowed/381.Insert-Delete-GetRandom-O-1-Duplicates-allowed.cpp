class RandomizedCollection {
    vector<int>array;
    unordered_map<int,vector<int>>Map;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) 
    {
        if (Map.find(val)==Map.end())
        {
            Map[val].push_back(array.size());
            array.push_back(val);
            return true;
        }
        else
        {
            Map[val].push_back(array.size());
            array.push_back(val);
            return false;        
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) 
    {
        if (Map.find(val)==Map.end())
            return false;
        else
        {
            int pos = Map[val].back();
            array[pos]=array.back();
            for (int i=0; i<Map[array.back()].size(); i++)
            {
                if (Map[array.back()][i]==array.size()-1)
                {
                    Map[array.back()][i] = pos;
                    break;
                }
            }
            array.pop_back();
            Map[val].pop_back();
            if (Map[val].size()==0)
                Map.erase(val);
            return true;
        }
        
    }
    
    /** Get a random element from the collection. */
    int getRandom() 
    {
        int pos = rand()% array.size();
        return array[pos];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
