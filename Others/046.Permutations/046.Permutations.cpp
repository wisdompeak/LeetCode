class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        queue<vector<int>>q;
        q.push({nums[0]});
        
        for (int i=1; i<nums.size(); i++)
        {
            int N=q.size();
            for (int j=0; j<N; j++)
            {
                auto p=q.front();
                q.pop();
                
                int M=p.size();
                for (int k=0; k<=M; k++)
                {
                    auto temp=p;
                    temp.insert(temp.begin()+k,nums[i]);
                    q.push(temp);
                }
            }
        }
         
        
        vector<vector<int>>results;
        while (!q.empty())
        {
            results.push_back(q.front());
            q.pop();
        }
        return results;
    }
};
