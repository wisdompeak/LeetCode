class Solution {
    map<int,int>Map;
    multiset<int>Set;
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) 
    {                
        int n = s.size();
        for (int i=0; i<n; i++)
        {
            int j = i;
            while (j<n && s[j]==s[i])
                j++;
            Set.insert(j-i);
            Map[i] = j-1;
            i = j-1;            
        }
        
        vector<int>rets;
        for (int k=0; k<queryIndices.size(); k++)
        {
            int idx = queryIndices[k];
            if (s[idx]!=queryCharacters[k]) 
            {                
                insert(idx);
                s[idx] = queryCharacters[k];
                mergeRight(idx, s);
                mergeLeft(idx, s);
            }
            rets.push_back(*Set.rbegin());                
        }
        return rets;        
    }
    
    void removeInterval(int a)
    {
        int b = Map[a];
        Map.erase(a);
        Set.erase(Set.find(b-a+1));
    }
    
    void addInterval(int a, int b)
    {
        Map[a] = b;
        Set.insert(b-a+1);
    }
    
    void insert(int idx)
    {
        auto iter = Map.upper_bound(idx);
        iter = prev(iter);
        int a = iter->first, b = iter->second;
        if (a==b && a==idx) return;
                
        removeInterval(a);        
        
        if (a == idx)
        {                 
            addInterval(a, a);
            addInterval(a+1, b);
        }
        else if (b == idx)
        {
            addInterval(b, b);
            addInterval(a, b-1);
        }
        else
        {
            addInterval(a, idx-1);
            addInterval(idx, idx);
            addInterval(idx+1, b);
        }
    }
    
    void mergeRight(int idx, string&s)
    {
        if (idx == s.size()-1) return;
        if (s[idx] != s[idx+1]) return;
        
        auto iter = Map.lower_bound(idx+1);
        int b = iter->second;
        
        removeInterval(idx);
        removeInterval(idx+1);
        addInterval(idx, b);
    }
    
    void mergeLeft(int idx, string&s)
    {
        if (idx == 0) return;
        if (s[idx] != s[idx-1]) return;
        
        auto iter = Map.lower_bound(idx);
        iter = prev(iter);
        int a = iter->first;
        int b = Map[idx];
        
        removeInterval(idx);
        removeInterval(a);
        addInterval(a, b);
    }
};
