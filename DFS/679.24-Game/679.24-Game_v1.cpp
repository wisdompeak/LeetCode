#include <algorithm> 

class Solution {
    vector<vector<vector<int>>>AllPermuations;
public:
    bool judgePoint24(vector<int>& nums) 
    {
        vector<double>Nums;
        for (auto x:nums) Nums.push_back(x*1.0);
        return DFS(Nums);
    }
    
    bool DFS(vector<double>& nums)
    {
        int m = nums.size();
        if (m==1) return (abs(nums[0]-24.0)<1e-6);
            
        for (int i=0; i<m; i++)
            for (int j=0; j<m; j++)
            {
                if (i==j) continue;
                
                vector<double>newNums;
                for (int k=0; k<m; k++)
                    if (k!=i && k!=j) newNums.push_back(nums[k]);
                newNums.push_back(-1);
                
                double a = nums[i];
                double b = nums[j];
                
                newNums.back() = a+b;
                if (DFS(newNums)) return true;
            
                newNums.back() = a-b;
                if (DFS(newNums)) return true;
            
                newNums.back() = a*b;
                if (DFS(newNums)) return true;
            
                if (b!=0.0)
                {
                    newNums.back() = a/b;
                    if (DFS(newNums)) return true;
                }            
            }        
        
            return false;
    }
    
};
