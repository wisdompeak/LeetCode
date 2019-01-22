class Solution {
    unordered_map<int,int>Map;
    int M;
public:
    Solution(int N, vector<int> blacklist) 
    {
        unordered_set<int>Set(blacklist.begin(),blacklist.end());
        M = N-blacklist.size();
        
        int x = N-1;
        for (int i=0; i<blacklist.size(); i++)
        {
            if (blacklist[i]>=M) continue;
            while (Set.count(x))
                x--;
            Map[blacklist[i]] = x;
            x--;
        }
        
    }
    
    int pick() 
    {
        int k = rand()%M;
        if (Map.find(k)!=Map.end())
            return Map[k];
        else
            return k;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
