class Solution {
public:
    int bestRotation(vector<int>& A) 
    {
        int N = A.size();
        vector<int>change(N+1,0);
        for (int i=0; i<N; i++)
        {
            change[(i-A[i]+1+N)%N]-=1;
            change[(i+1)%N]+=1;
        }
        
        int sum = 0;
        int result = 0;
        int K = 0;
        for (int i=1; i<N; i++)
        {
            sum+=change[i];
            if (sum>result)
            {
                result = sum;
                K = i;
            }
        }
        return K;
    }
};
