class Solution {
    vector<int>Father;
    int FindFather(int x)
    {
        if (Father[x]!=x)
            Father[x] = FindFather(Father[x]);
        return Father[x];
    }
    
    void Union(int x, int y)
    {
        x = Father[x];
        y = Father[y];
        if (x<y) Father[y] = x;
        else Father[x] = y;
    }    

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) 
    {
        int n = source.size();
        Father.resize(n);
        for (int i=0; i<n; i++)
            Father[i] = i;
        
        for (auto pair: allowedSwaps)
        {
            int a = pair[0];
            int b = pair[1];
            if (FindFather(a)!=FindFather(b))
                Union(a,b);
        }
        
        unordered_map<int,vector<int>>Map;
        for (int i=0; i<n; i++)
            Map[FindFather(i)].push_back(i);
        
        int count = 0;
        for (auto x: Map)
        {
            multiset<int>Set;
            for (auto i: x.second)
                Set.insert(source[i]);
            for (auto i: x.second)
            {
                if (Set.find(target[i])!=Set.end())
                    Set.erase(Set.lower_bound(target[i]));
            }
            count += Set.size();
        }
        return count;                
    }
};
