class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) 
    {
        sort(coins.begin(), coins.end());
        
        unordered_set<int>Set;
        Set.insert(0);
        int next = 1;
        
        for (auto c: coins)
        {
            if (next < c)
                return next;            
                
            vector<int>temp({c});
            for (auto t: Set)
                temp.push_back(t+c);
            for (auto x: temp)
                Set.insert(x);
            
            while (Set.find(next)!=Set.end())
                next++;            
        }
        return next;        
    }
};
