class Solution {
public:
    int bestRotation(vector<int>& A) 
    {
        int N = A.size();
        vector<int>diff(N,0);
        for (int i=0; i<N; i++)
        {
            diff[(i-A[i]+1+N)%N]-=1;
            diff[(i+1)%N]+=1;
        }
        
        int sum = 0;
        int ret = 0;
        int K = 0;
        for (int i=1; i<N; i++)
        {
            sum += diff[i];
            if (sum > ret)
            {
                ret = sum;
                K = i;
            }
        }
        return K;
    }
};
