class Solution {
    unordered_set<string>FailureSet;
    unordered_set<int>StoneSet;
public:
    bool canCross(vector<int>& stones) 
    {        
        for (auto a:stones)
            StoneSet.insert(a);
        return DFS(stones.back(),1,1);
    }
    
    bool DFS(int dest, int pos, int jump)
    {       
        if (pos==dest)
            return true;
        
        if (StoneSet.find(pos)==StoneSet.end())
            return false;        
        
        string temp = to_string(pos)+"#"+to_string(jump);
        if (FailureSet.find(temp)!=FailureSet.end())
            return false;
        
        for (int k=max(1,jump-1); k<=jump+1; k++)
        {
            if (DFS(dest, pos+k, k))
                return true;            
        }
        
        FailureSet.insert(temp);
        return false;
    }
};
