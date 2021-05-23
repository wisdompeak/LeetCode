class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) 
    {
        int m = encoded1.size(), n = encoded2.size();
        int i = 0, j = 0;        
        int ret = 0;
        
        vector<vector<int>>rets;
        while (i<m && j<n)
        {
            int k = min(encoded1[i][1], encoded2[j][1]);            
            rets.push_back({encoded1[i][0]*encoded2[j][0], k});
            encoded1[i][1]-=k;
            encoded2[j][1]-=k;
            if (encoded1[i][1]==0)
                i++;
            if (encoded2[j][1]==0)
                j++;
        }
        
        vector<vector<int>>ans;
        for (int i=0; i<rets.size(); i++)
        {
            int j = i;
            int count = 0;
            while (j<rets.size() && rets[j][0]==rets[i][0])
            {
                count+=rets[j][1];
                j++;
            }
            ans.push_back({rets[i][0], count});
            i = j-1;                
        }
        
        return ans;
    }
};
