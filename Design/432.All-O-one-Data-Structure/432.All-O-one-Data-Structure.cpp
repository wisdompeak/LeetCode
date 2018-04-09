class AllOne {
    
    unordered_map<string,int>Str2Num;
    unordered_map<int,set<string>>Num2Strs;
    unordered_map<int,list<int>::iterator>Num2Iter;
    list<int>ListNum;
    
public:
    /** Initialize your data structure here. */
    AllOne() 
    {
        Str2Num.clear();
        Num2Strs.clear();
        Num2Iter.clear();
        ListNum.clear();     
        
        ListNum.push_back(0);
        Num2Iter[0] = ListNum.begin();
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) 
    {
        int val = Str2Num[key];
                
        Str2Num[key]++;
        
        Num2Strs[val+1].insert(key);
        if (val!=0) Num2Strs[val].erase(key);
        
        if (Num2Strs[val+1].size()==1)
        {
            auto it = Num2Iter[val];
            ListNum.insert(next(it),val+1);
            Num2Iter[val+1] = next(it);
        }
        
        if (val!=0 && Num2Strs[val].size()==0)
        {
            auto it = Num2Iter[val];
            ListNum.erase(it);
            Num2Iter.erase(val);
        }
        
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) 
    {
        if (Str2Num.find(key)==Str2Num.end())
            return;
        
        int val = Str2Num[key];
        
        Str2Num[key]--;
        
        if (val-1!=0) Num2Strs[val-1].insert(key);
        Num2Strs[val].erase(key);
        
        if (val-1!=0 && Num2Strs[val-1].size()==1)
        {
            auto it = Num2Iter[val];
            ListNum.insert(it,val-1);
            Num2Iter[val-1]=prev(it);
        }
        
        if (Num2Strs[val].size()==0)
        {
            auto it = Num2Iter[val];
            ListNum.erase(it);
            Num2Iter.erase(val);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() 
    {
        if (ListNum.size()==1)
            return "";
        
        int val = ListNum.back();        
        return *(Num2Strs[val].begin());
        
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() 
    {
        if (ListNum.size()==1)
            return "";
        
        int val = *(++ListNum.begin());
        return *(Num2Strs[val].begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
