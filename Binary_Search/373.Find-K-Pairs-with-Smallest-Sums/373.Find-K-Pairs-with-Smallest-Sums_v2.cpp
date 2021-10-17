class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[0]+a[1]<b[0]+b[1];
    }
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int M = nums1.size();
        int N = nums2.size();
        if (M==0 || N==0) return {};
        
        auto matrix = vector<vector<int>>(M,vector<int>(N));
        for (int i=0; i<M; i++)
            for (int j=0; j<N; j++)
                matrix[i][j] = nums1[i]+nums2[j];
        
        int left = matrix[0][0];
        int right = matrix[M-1][N-1];
        while (left<right)
        {
            int mid = left+(right-left)/2;
            if (EqualOrSmaller(matrix, mid) < k)
                 left = mid+1;
            else
                right = mid;
        }
        
        int x = left;
        
        vector<vector<int>>results;
        int i = M-1, j = 0;
        while (i>=0 && j<N)
        {
            if (matrix[i][j]<=x)
            {
                for (int k=i; k>=0; k--)
                    results.push_back({nums1[k],nums2[j]});
                j++;
            }
            else
                i--;
        }
        
        sort(results.begin(), results.end(), cmp);
        if (k<results.size())
            results.resize(k);
        return results;
    }
    
    int EqualOrSmaller(vector<vector<int>>& matrix, int x)
    {
        int M = matrix.size();
        int N = matrix[0].size();
        int i = M-1, j = 0;
        int count = 0;
        while (i>=0 && j<N)
        {
            if (matrix[i][j]<=x)
            {
                count += i+1;
                j++;
            }
            else
                i--;
        }
        return count;        
    }
};
