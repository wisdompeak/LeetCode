class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<int>zeros(n);
        for (int i=0; i<n; i++)
        {
            int count = 0;
            for (int j=n-1; j>=0; j--)
            {
                if (grid[i][j]!=0)
                    break;
                count++;
            }
            zeros[i] = count;            
        }
        
        int count = 0;
        for (int i=0; i<n-1; i++)
        {
            int num = n-1-i;
            int j = i;
            for (; j<n; j++)
            {
                if (zeros[j]>=num)
                    break;
            }
            if (j==n) return -1;
            count += j-i;
            int temp = zeros[j];
            for (int k=j; k>i; k--)
                zeros[k] = zeros[k-1];
            zeros[i] = temp;
        }
        
        return count;
    }
};
