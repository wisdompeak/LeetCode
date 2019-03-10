#include <algorithm> 

class Solution {
    vector<vector<vector<int>>>AllPermuations;
public:
    bool judgePoint24(vector<int>& nums) 
    {
        vector<double>Nums;
        for (auto x:nums) Nums.push_back(x*1.0);
        
        AllPermuations.resize(5);
        AllPermuations[4] = CalPermutation(4);
        AllPermuations[3] = CalPermutation(3);
        AllPermuations[2] = CalPermutation(2);
        
        return DFS(Nums);
    }
    
    bool DFS(vector<double>& nums)
    {
        int k = nums.size();
        if (k==1) return (abs(nums[0]-24.0)<1e-6);
            
        vector<vector<int>>permutations = AllPermuations[k];
        
        for (int i=0; i<permutations.size(); i++)
        {
            vector<double>newNums(k-1);
            for (int j=0; j<k-2; j++)
                newNums[j] = nums[permutations[i][j]];
            
            double a = nums[permutations[i][k-2]];
            double b = nums[permutations[i][k-1]];
            
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
    
    vector<vector<int>>CalPermutation(int k)
    {
        vector<vector<int>>results;
        vector<int>nums;
        for (int i=0; i<k; i++) nums.push_back(i);
        do
        {
            results.push_back(nums);
        }while (next_permutation(nums.begin(),nums.end()));
        
        return results;        
    }
    
};
