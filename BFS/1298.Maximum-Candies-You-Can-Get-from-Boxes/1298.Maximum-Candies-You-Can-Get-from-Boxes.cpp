class Solution {
    unordered_set<int>key;
    int ret = 0;
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) 
    {
        queue<int>q;
        for (auto b: initialBoxes)
            q.push(b);
        
        bool changed = 1;
        while (q.size()>0 && changed)
        {
            changed = 0;
            int len = q.size();
            while (len--)
            {
                int b = q.front();
                q.pop();
                
                if (status[b]==0 && key.find(b)==key.end())
                {
                    q.push(b);
                }
                else
                {
                    changed = 1;
                    ret+=candies[b];
                    for (auto k: keys[b])
                        key.insert(k);
                    for (auto bb: containedBoxes[b])
                        q.push(bb);                
                }
            }
        }
        return ret;
        
    }
};
