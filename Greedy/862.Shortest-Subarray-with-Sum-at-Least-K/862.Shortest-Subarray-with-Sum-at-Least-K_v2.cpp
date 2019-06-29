class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) 
    {
        int N = A.size();
        vector<int>presum(N+1,0);        
        for (int i=0; i<N; i++) presum[i+1]=presum[i]+A[i];
        
        deque<int>q;
        int result = INT_MAX;
        for (int i=0; i<=N; i++)
        {
            while (q.size()>0 && presum[q.front()]+K<=presum[i])
            {
                result = min(result,i-q.front());
                q.pop_front();
            }
            while (q.size()>0 && presum[q.back()]>=presum[i])
                q.pop_back();
            q.push_back(i);
        }
        return result==INT_MAX? -1:result;
        
    }
};
