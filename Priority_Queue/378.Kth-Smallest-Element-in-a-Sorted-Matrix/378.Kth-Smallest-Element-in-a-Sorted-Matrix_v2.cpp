class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int N = matrix.size();
        int left = matrix[0][0];
        int right = matrix[N-1][N-1];
        while (left<right)
        {
            int mid = left+(right-left)/2;
            //cout<<left<<" "<<right<<" "<<mid<<" "<<equalOrSmaller(matrix,mid)<<endl;
            
            if (equalOrSmaller(matrix,mid)<k)
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
    
    int equalOrSmaller(vector<vector<int>>& matrix, int x)
    {
        int N = matrix.size();
        int i=N-1, j=0, count = 0;
        while (i>=0 && j<N)
        {
            if (matrix[i][j]<=x)
            {
                count+=(i+1);
                j++;
            }
            else
                i--;                
        }
        return count;
    }
};
