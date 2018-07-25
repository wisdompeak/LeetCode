class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) 
    {
        vector<int>q(length+1,0);
        for (int i=0; i<updates.size(); i++)
        {
            q[updates[i][0]]+=updates[i][2];
            q[updates[i][1]+1]-=updates[i][2];
        }
        
        vector<int>results(length,0);        
        results[0] = q[0];
        int count = q[0];
        for (int i=1; i<length; i++)
        {
            count += q[i];
            results[i] = count;
        }
        return results;
    }
};
