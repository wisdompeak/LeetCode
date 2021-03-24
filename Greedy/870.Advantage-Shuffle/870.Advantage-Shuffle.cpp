class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) 
    {
        int n = A.size();
        vector<pair<int,int>>BB;
        for (int i=0; i<n; i++)
            BB.push_back({B[i],i});
        sort(BB.begin(), BB.end());
        sort(A.begin(), A.end());
        
        int j=0;
        vector<int>rets(n,-1);
        for (int i=0; i<n; i++)
        {
            while (j<n && A[j]<=BB[i].first)
                j++;
            if (j<n)
            {
                rets[BB[i].second] = A[j];
                A[j] = -1;
            }                
        }
        
        j = 0;
        for (int i=0; i<n; i++)
        {
            if (rets[i]!=-1) continue;
            while (j<n && A[j]==-1) j++;
            rets[i] = A[j];
            j++;
        }
        return rets;
    }
};
