class AllOne {
    list<int>List; // ordered sequence of values
    unordered_map<string,int>key2val;   // key->val
    unordered_map<int,unordered_set<string>>val2set;  //val->set of keys
    unordered_map<int,list<int>::iterator>val2iter; //val-> iterator in list
    
public:
    /** Initialize your data structure here. */
    AllOne() {
        List.push_back(0);
        val2iter[0] = List.begin();
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) 
    {
        int val = key2val[key];
        
        key2val[key] = val+1;
        
        val2set[val+1].insert(key);
        if (val>0) val2set[val].erase(key);
            
        if (val2set[val+1].size()==1)
        {
            List.insert(next(val2iter[val]), val+1);
            val2iter[val+1] = next(val2iter[val]);
        }
            
        if (val>0 && val2set[val].size()==0)
        {
            List.erase(val2iter[val]);
        }
        
        //cout<<"OK"<<endl;
            
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) 
    {
        int val = key2val[key];
        if (val==0) return;
        
        key2val[key] = val-1;
        
        if (val-1>0) val2set[val-1].insert(key);
        val2set[val].erase(key);
            
        if (val-1>0 && val2set[val-1].size()==1)
        {
            List.insert(val2iter[val], val-1);
            val2iter[val-1] = prev(val2iter[val]);
        }
            
        if (val2set[val].size()==0)
        {
            List.erase(val2iter[val]);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() 
    {
        if (List.size()==1)
            return "";
        else
            return *(val2set[List.back()].begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() 
    {
        if (List.size()==1)
            return "";
        else
            return *(val2set[*(++List.begin())].begin());;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

