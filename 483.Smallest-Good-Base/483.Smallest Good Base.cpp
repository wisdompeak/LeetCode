class Solution {
public:
    string smallestGoodBase(string n) 
    {
        long long N = 0;
        for (int i=0; i<n.size(); i++)
            N = N*10 + n[i]-'0';

        if (N==1) return "1";
        
        long long M = log(N+1)/log(2)+1;
        
        for (long long m =M; m>=2; m--)
        {
            long long K = pow(N,1.0/(m-1))+1;
            
            long long left = 2;
            long long right = K;
            long long mid;
            long long k;
            
            while (left<right)
            {

                mid = left+(right-left)/2;
                k = mid;

                long long sum = 1;
                for (int i=1; i<=m-1; i++)
                {
                    sum = sum*k+1;
                }
                
                if (sum == N) return to_string(k);
                if (sum < N) 
                    left = mid+1;
                else
                    right = mid;
                
            }
        }
        
        return to_string(N-1);
        
    }
};
