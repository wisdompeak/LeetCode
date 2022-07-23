class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) 
    {
        int n = rolls.size();        
        unordered_set<int>Set;
                
        int ret = 0;
        for (int i=n-1; i>=0; i--)
        {
            Set.insert(rolls[i]);
            if (Set.size()==k)
            {
                ret++;
                Set.clear();
            }
        }
        return ret+1;
        
    }
};
