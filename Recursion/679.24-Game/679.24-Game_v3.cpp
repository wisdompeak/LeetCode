class Solution {
public:
    bool judgePoint24(vector<int>& cards) 
    {
        vector<double>nums(4);
        for (int i=0; i<4; i++) nums[i] = cards[i];
        sort(nums.begin(), nums.end());
                
        while (1)
        {
            unordered_set<double> results = DFS(nums,0,3);
            for (auto a:results)
            {
                if (abs(a-24)<1e-10)
                    return true;
            }
            if (next_permutation(nums.begin(), nums.end()) == false) 
                break;
        }
        return false;
    }
    
    unordered_set<double> DFS(vector<double> &nums, int a, int b)
    {
        if (a==b) return {nums[a]};
        
        unordered_set<double>results;
        
        for (int i=a; i<b; i++)
        {
            unordered_set<double>A = DFS(nums,a,i);
            unordered_set<double>B = DFS(nums,i+1,b);
            for (double x:A)
                for (double y:B)
                {
                    results.insert(x+y);
                    results.insert(x-y);
                    results.insert(x*y);
                    if (y!=0)
                        results.insert(x/y);
                }
        }
        return results;
    }
};
