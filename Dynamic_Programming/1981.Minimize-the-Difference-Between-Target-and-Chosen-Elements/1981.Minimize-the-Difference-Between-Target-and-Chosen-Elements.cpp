class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) 
    {
        int m = mat.size();
        int n = mat[0].size();
        unordered_set<int>Set({0});
        
        for (int i=0; i<m; i++)
        {
            unordered_set<int>temp;
            int great = -1;
            for (auto x: Set)
            {
                for (auto y: mat[i])
                {
                    if (x+y <= target)
                        temp.insert(x+y);
                    else
                    {
                        if (great==-1)
                            great = x+y;
                        else if (x+y < great)
                            great = x+y;                            
                    }
                }                    
            }
            if (great!=-1)
                temp.insert(great);
            
            Set = std::move(temp);                       
        }
        
        int diff = INT_MAX;
        for (auto x:Set)
        {
            diff = min(diff, abs(x-target));
        }
        return diff;
        
    }
};
