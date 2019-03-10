class Solution {
public:
    bool judgePoint24(vector<int>& nums) 
    {
        vector<double>Nums;
        for (int i=0; i<4; i++) 
            Nums.push_back(nums[i]*1.0);
        
        return DFS(Nums,3);
    }
    
    bool DFS(vector<double>nums, int k)
    {
        if (k==0)
        {
            if (abs(nums[0]-24)<1e-10) 
                return true;
            else 
                return false;
        }
        
        vector<vector<double>>permuations=permute(nums);                
        
        for (int i=0; i<permuations.size(); i++)
        {
            vector<double>newNums(k);
            
            for (int j=0; j<k-1; j++)
                newNums[j]=permuations[i][j];
                        
            newNums[k-1]=permuations[i][k-1]+permuations[i][k];            
            if (DFS(newNums,k-1)) return true;
                    
            newNums[k-1]=permuations[i][k-1]-permuations[i][k];
            if (DFS(newNums,k-1)) return true;
                        
            newNums[k-1]=permuations[i][k-1]*permuations[i][k];            
            if (DFS(newNums,k-1)) return true;        
                                                      
            if (permuations[i][k]!=0.0)
            {
                newNums[k-1]=permuations[i][k-1]/permuations[i][k];
                if (DFS(newNums,k-1)) return true;
            }                           
        }
                
        return false;                         
    }
    
    vector<vector<double>> permute(vector<double>& nums) 
    {
        int N=nums.size();
        if (N==1) return {nums};
        
        vector<vector<double>>results;
        
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                if (j==i) continue;
                vector<double>temp;
                
                for (int k=0; k<N; k++)
                {
                    if (k==i||k==j) continue;
                    temp.push_back(nums[k]);
                }
                temp.push_back(nums[j]);
                temp.push_back(nums[i]);                
                results.push_back(temp);
            }            
        }
        return results;
    }    
};
