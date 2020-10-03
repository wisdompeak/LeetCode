class Solution {
    set<vector<int>>failed;
    set<int>stoneSet;
public:
    bool canCross(vector<int>& stones) 
    {
        for (auto x: stones)        
            stoneSet.insert(x);
            
        return dfs(stones, 0, 0);
    }

    bool dfs(vector<int>&stones, int pos, int step)
    {        
        if (pos==stones.back()) return true; 
        if (stoneSet.find(pos)==stoneSet.end()) return false;
        if (failed.find({pos,step})!=failed.end()) return false;

        // cout<<pos<<" "<<step<<endl;

        if (step>1 && dfs(stones, pos+step-1, step-1))
            return true;
        if (step>0 && dfs(stones, pos+step, step))
            return true;
        if (dfs(stones, pos+step+1, step+1))
            return true;

        failed.insert({pos,step});
        return false;
    }
};
